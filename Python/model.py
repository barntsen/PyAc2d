import pyeps
import babin as ba
import pyeps


class model :
  ''' model creates a model suitable for the pyac2d library 
      solver.

     Parameters: 
       pyac2d  : Reference to the pyac2d wave propagation
                 library.

     Returns   : model object.       

  '''

  # Modelmaxwell creates a new model.
  #
  # Parameters: 
  #
  #  - vp :  P-wave velocity model
  #  - rho:  Density 
  #  - Q  :  Q-values
  #  - Dx :  Grid interval in x- and y-directions
  #  - Dt :  Modeling time sampling interval
  #  - W0 :  Q-model peak angular frequency
  #  - Nb :  Width of border attenuation zone (in grid points)
  #
  #  Return:  Model structure
  #
  # ModelNew creates the parameters needed by the Ac2d object
  # to perform 2D acoustic modeling.
  # The main parameters are density $\rho$ and bulk modulus $\kappa$ which are
  # calculated from the wave velocity and density.
  # In addition are the visco-elastic coefficients $\alpha_1$, $\alpha_2$ ,
  # $\eta_1$  and $\eta_2$ computed.
  #
  # The model is defined by several 2D arrays, with the x-coordinate
  # as the first index, and the y-coordinate as the second index.
  # A position in the model (x,y) maps to the arrays as [i,j]
  # where x=Dx*i, y=Dx*j
  # The absorbing boundaries is comparable to the CPML method
  # but constructed using a visco-elastic medium with
  # relaxation specified by a standard-linear solid, while 
  # a time dependent density which uses a standard-linear solid
  # relaxation mechanism.
  #
  #                     Nx                Outer border        
  #    |----------------------------------------------|
  #    |           Qmin=1.1                           |
  #    |                                              |
  #    |           Qmax=Q(x,y=Dx*Nb)     Inner border |
  #    |      ----------------------------------      |
  #    |      |                                |      |
  #    |      |                                |      | Ny
  #    |      |      Q(x,y)                    |      |
  #    |      |                                |<-Nb->|
  #    |      |                                |      |
  #    |      |                                |      |
  #    |      ----------------------------------      |
  #    |                                              |
  #    |                                              |
  #    |                                              |
  #    |-----------------------------------------------
  #
  #    Fig 1: Organisation of the Q-model.
  #           The other arrays are organised in the same way.
  #
  # The Boundary condition is implemented by using a strongly
  # absorbing medium in a border zone with width Nb.
  # The border zone has the same width both in the horizontal
  # and vertical directions.
  # The medium in the border zone has a Q-value of Qmax
  # at the inner bondary (taken from the Q-model) and
  # the Q-value is gradualy reduced to Qmin at the outer boundary.
  #
  #  In the finit-edifference solver we use the Maxwell 
  #  solid to implement time dependent 
  #  bulk modulus and density.
  #  The Maxwell solid model uses
  #  one parameter, tau0.
  #  tau0 is related to the Q-value by
  # (See the notes.tex in the Doc directory for the equations.)
  #  
  #    taue(Q0) = Q(W0)/W0
  #
  #  Q0 is here the value for Q at the frequency W0.
  #
  #  The coeffcients needed by the solver methods in the Ac2d object are
  #    alpha1x =  exp(d_x/Dt)exp(tau0x),                                  \\
  #    alpha2x =  - dx Dt/tau0x
  #    alpha1y =  exp(d_x/Dt)exp(tau0y),                                  \\
  #    alpha2y =  -dx Dt/tau0y
  #    eta1x   =  exp(d_x/Dt)exp(tau0x),                                  \\
  #    eta2x   =  -dx Dt/tau0x
  #    eta1y   =  exp(d_x/Dt)exp(tau0y),                                  \\
  #    eta2y   =  -dx Dt/tau0y
  #
  # tau0 is interpolated between the values given by the Q-value 
  # Qmax at the inner border of the model and the Qmin at the outer border. 
  # For the interpolation we just assume that the relaxation times
  # varies proportionaly with the square of the distance from
  # the inner border, according to
  #
  #  tau0x(x) = tau0xmin + (tau0xmax-tau0xmin)*d(x)
  #  tau0y(x) = tau0ymin + (tau0xmax-tau0ymin)*d(y)
  #                       
  #  where 
  #
  #   d(x) = (x/L)^2
  #
  # x is the distance from the outer border, while
  # L is the length of the border.
  # We also have
  #
  #   tau0xmax = tau0(Qmax)
  #   tau0xmin = tau0(Qmin)
  #   tau0ymax = tau0(Qmax)
  #   tau0ymin = tau0(Qmin)
  #
  # Here Qmin= 1.1, while Qmax is equal to the value 
  # of Q at the inner border.
  # 
  def Modelmaxwell(self,vp, rho,  Q, Dx, Dt, W0, Nb) :
    self.Dx = Dx;
    self.Dt = Dt;
    self.Nx = vp.shape[0]
    self.Ny = vp.shape[1]
    self.Nb = Nb;
    self.W0 = W0;
    Nx=self.Nx;
    Ny=self.Ny;
    self.Rho     = np.zeros([Nx,Ny]); // Density
    self.Q       = np.zeros([Nx,Ny]); // Q-values
    self.Kappa   = np.zeros([Nx,Ny]);  // Unrelaxed bulk modulus

    # The following parameters are the change in the 
    # bulk modulus caused by visco-elasticity
    # A separate factor is used for the x- and y-directions
    # due to tapering
    self.Dkappax = np.zeros([Nx,Ny]);  
    self.Dkappay = np.zeros([Nx,Ny]);
    self.Drhox   = np.zeros([Nx,Ny]);
    self.Drhoy   = np.zeros([Nx,Ny]);

    # Coeffcients used for updating memory functions
    self.Alpha1x   =  np.zeros([Nx,Ny]);
    self.Alpha1y   =  np.zeros([Nx,Ny]);
    self.Alpha2x   =  np.zeros([Nx,Ny]);
    self.Alpha2y   =  np.zeros([Nx,Ny]);
    self.Eta1x    =   np.zeros([Nx,Ny]);
    self.Eta1y   =  np.zeros([Nx,Ny]);
    self.Eta2x   =  np.zeros([Nx,Ny]);
    self.Eta2y   =  np.zeros([Nx,Ny]);

    # Tapering (profile) functions for
    # the x- and y-directions.
    self.dx   =  np.zeros([Nx]);
    self.dy   =  np.zeros([Ny]);

    # Store the model
    for j in range(0,Ny):
      for i in range(0,Nx):
        self.Kappa[i,j] = rho[i,j]*vp[i,j]*vp[i,j];
        self.Rho[i,j]   = 1.0/rho[i,j];
        self.Q[i,j]       = Q[i,j];

    # Compute 1D profile functions
    self.Modeld(Model.dx, Model.Dx, Model.Nb);
    self.Modeld(Model.dy, Model.Dx, Model.Nb);
 
    # Compute relaxation times
    for j in range(0,Ny) :
      for i in range(0,Nx) :
        # Note that we compute the inverse
        # of tau0, and use the same
        # name for the inverse, tau0=1/tau0.
      
        Qmin = 1.1;   # MinimumQ-value at the outer boundaries:       
        tau0min = Qmin/self.W0;
        tau0min = 1.0/tau0min;
        Qmax  = self.Q[Nb,j];
        tau0max = Qmax/self.W0;
        tau0max = 1.0/tau0max;

        # Interpolate tau0 in x-direxction
        tau0x = tau0min + (tau0max-tau0min)*Model.dx[i];

        Qmax  = self.Q[i,Nb];
        tau0max = Qmax/self.W0;
        tau0max = 1.0/tau0max;

        # Interpolate tau0 in y-direxction
        tau0y = tau0min + (tau0max-tau0min)*Model.dy[j];

        # In the equations below the relaxation time tau0 
        # is inverse (1/tau0)
        # Compute alpha and eta coefficients
        argx = Model.dx[i];
        argy = Model.dy[j];
        # An extra tapering factor of exp(-(x/L)**2)
        # is used to taper some coefficeints 
        self.Alpha1x[i,j]   = LibeExp(-argx)*LibeExp(-self.Dt*tau0x);
        self.Alpha1y[i,j]   = LibeExp(-argy)*LibeExp(-self.Dt*tau0y);
        self.Alpha2x[i,j]   = -self.Dt*tau0x;
        self.Alpha2y[i,j]   = -self.Dt*tau0y;
        self.Eta1x[i,j]     = LibeExp(-argx)*LibeExp(-self.Dt*tau0x);
        self.Eta1y[i,j]     = LibeExp(-argy)*LibeExp(-self.Dt*tau0y);
        self.Eta2x[i,j]     = -self.Dt*tau0x;
        self.Eta2y[i,j]     = -self.Dt*tau0y;
 
        # For the Maxwell solid Dkappa = kappa and Drho = 1/rho
        # to comply with the solver algorithm in ac2d.e
        self.Dkappax[i,j]   = Model.Kappa[i,j];
        self.Dkappay[i,j]   = Model.Kappa[i,j];
        self.Drhox[i,j]     = Model.Rho[i,j];
        self.Drhoy[i,j]     = Model.Rho[i,j];

  # ModelNew creates a new model.
  #
  # Parameters:
  #
  #  - vp :  P-wave velocity model
  #  - rho:  Density
  #  - Q  :  Q-values
  #  - Dx :  Grid interval in x- and y-directions
  #  - Dt :  Modeling time sampling interval
  #  - W0 :  Q-model peak angular frequency
  #  - Nb :  Width of border attenuation zone (in grid points)
  #  - Rheol : Type of Q-model. Rheol=MAXWELL (Maxwell solid)
  #                             Rheol=SLS     (Standard linear solid)
  #
  # Return:  Model structure
  #
  # ModelNew creates the parameters needed by the Ac2d object
  # to perform 2D acoustic modeling.
  # For the details of the MAXWELL or SLS type models
  # see the comments in Modelmaxwell and Modelsls.

  def  ModelNew(self,vp, rho, Q, Dx, Dt, W0, Nb, Rheol) :
    if(Rheol == MAXWELL) :
      self.Modelmaxwell(vp, rho, Q, Dx, Dt, W0, Nb);
    elif(Rheol == SLS):
      self.Modelsls(vp, rho, Q, Dx, Dt, W0, Nb);
    else :
      print("Uknown Q-model\n");
      exit();

  def __init__(self,pyac2d,par):
    #Get the velocity model
    fin = ba.bin(par.fvp)
    data=fin.read((par.ny,par.nx))
    #Convert 2d numpy float array to eps
    vp=pyeps.PyepsStore2df(pyac2d,data);

    #Get the density model
    fin = ba.bin(par.frho)
    data=fin.read((par.ny,par.nx))
    #Convert 2d numpy float array to eps
    rho=pyeps.PyepsStore2df(pyac2d,data);

    #Get the Q model
    fin = ba.bin(par.fq)
    data=fin.read((par.ny,par.nx))
    #Convert 2d numpy float array to eps
    q=pyeps.PyepsStore2df(pyac2d,data);

    #Create a new model
    self.model=pyac2d.ModelNew (vp,rho,q,par.dx,par.dt,par.w0,par.nb,par.rheol)
