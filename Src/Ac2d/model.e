// Methods for the model struct
//

include <libe.i>
include "model.i"

//Internal functions
int Modeld(float [*] d, float dx, int nb){}
float Modeltaus(float Q, float w0){}
float Modeltaue(float Q, float w0){}

// ModelNew creates a new model.
// The model is defined by several 2D arrays, with the x-coordinate
// as the first index, and the y-coordinate as the second index.
// A position in the model (x,y) maps to the arrays as [i,j]
// where x=Dx*i, y=Dx*j
// The arrays vp and rho dfines the P-wave velocity and the density.
// Q defines the P-wave Q-value.
// Dx and Dt are the spatial and time sampling intervals, while
// W0 is the angular frequency of the Q absorption peak.
// Nb (in grid points) is the width of the border zone used for the 
// boundary conditions.
// The absorbing boundaries is equal to the CPML method
// but constructed using a visco-elastic medium with
// relaxation specified by a standard-linear solid, while 
// Newtons equation of motion includes viscous losses through
// a time dependent density which uses a standard-linera solid
// relaxation mechanism.
// The Boundary condition is implemented by using a strongly
// absorbing medium with low Q around a border zone with width Nb.

struct model ModelNew(float [*,*] vp, float [*,*] rho, float [*,*] Q, 
                      float Dx, float Dt, float W0, int Nb)
{
  struct model Model; // Object to instantiate

  int Nx,Ny;              // Model dimensions in x- and y-directions
  float tau0;             // Relaxation time at Peak 1/Q-value
  
  // Smoothing parameters
  float Qmin, Qmax;
  float tauemin,tauemax;
  float tausmin,tausmax;

  // Relaxation times
  float tausx, tausy;
  float tauex, tauey;

  int i,j;

  Model= new(struct model);
  Model.Dx = Dx;
  Model.Dt = Dt;
  Model.Nx = len(vp,0);
  Model.Ny = len(vp,1);
  Model.Nb = Nb;
  Model.W0 = W0;
  Nx = Model.Nx;
  Ny = Model.Ny;
  Model.Kappa   = new(float [Nx,Ny]);
  Model.Dkappax = new(float [Nx,Ny]);
  Model.Dkappay = new(float [Nx,Ny]);
  Model.Drhox     = new(float [Nx,Ny]);
  Model.Drhoy     = new(float [Nx,Ny]);
  Model.Rho     =  new(float [Nx,Ny]);
  Model.Q       =  new(float [Nx,Ny]);
  Model.Alpha1x   =  new(float [Nx,Ny]);
  Model.Alpha1y   =  new(float [Nx,Ny]);
  Model.Alpha2x   =  new(float [Nx,Ny]);
  Model.Alpha2y   =  new(float [Nx,Ny]);
  Model.Eta1x   =  new(float [Nx,Ny]);
  Model.Eta1y   =  new(float [Nx,Ny]);
  Model.Eta2x   =  new(float [Nx,Ny]);
  Model.Eta2y   =  new(float [Nx,Ny]);
  Model.dx   =  new(float [Nx]);
  Model.dy   =  new(float [Ny]);

  // Store the model
  for(i=0; i<Nx;i=i+1){
    for(j=0; j<Ny;j=j+1){
      Model.Kappa[i,j] = rho[i,j]*vp[i,j]*vp[i,j];
      Model.Rho[i,j]   = rho[i,j];
      Model.Q[i,j]       = Q[i,j];
    }
  }

  //Compute 1D profile functions
    Modeld(Model.dx, Model.Dx, Model.Nb);
    Modeld(Model.dy, Model.Dx, Model.Nb);
 
  // Compute relaxation times
  for(i=0; i<Nx;i=i+1){
    for(j=0; j<Ny;j=j+1){
      tau0 = 1.0/Model.W0;
      Qmin = 1.1;
      tauemin = (tau0/Qmin)*(LibeSqrt(Qmin*Qmin+1.0)+1.0);
      tauemin = 1.0/tauemin;
      tausmin = (tau0/Qmin)*(LibeSqrt(Qmin*Qmin+1.0)-1.0);
      tausmin = 1.0/tausmin;

      Qmax  = Model.Q[Nb,j];
      tauemax = (tau0/Qmin)*(LibeSqrt(Qmax*Qmax+1.0)+1.0);
      tauemax = 1.0/tauemax;
      tausmax = (tau0/Qmin)*(LibeSqrt(Qmax*Qmax+1.0)-1.0);
      tausmax = 1.0/tausmax;
      tauex = tauemin + (tauemax-tauemin)*Model.dx[i];
      tausx = tausmin + (tausmax-tausmin)*Model.dx[i];

      Qmax  = Model.Q[i,Nb];
      tauemax = (tau0/Qmin)*(LibeSqrt(Qmax*Qmax+1.0)+1.0);
      tauemax = 1.0/tauemax;
      tausmax = (tau0/Qmin)*(LibeSqrt(Qmax*Qmax+1.0)-1.0);
      tausmax = 1.0/tausmax;
      tauey = tauemin + (tauemax-tauemin)*Model.dy[j];
      tausy = tausmin + (tausmax-tausmin)*Model.dy[j];

      // Compute alpha and eta coefficients
      Model.Alpha1x[i,j]   = LibeExp(-Model.Dt*tausx);
      Model.Alpha1y[i,j]   = LibeExp(-Model.Dt*tausy);
      Model.Alpha2x[i,j]   = Model.Dt*tauex;
      Model.Alpha2y[i,j]   = Model.Dt*tauey;
      Model.Eta1x[i,j]     = LibeExp(-Model.Dt*tausx);
      Model.Eta1y[i,j]     = LibeExp(-Model.Dt*tausy);
      Model.Eta2x[i,j]     = Model.Dt*tauex;
      Model.Eta2y[i,j]     = Model.Dt*tauey;
      Model.Dkappax[i,j]   = Model.Kappa[i,j]
                             *(1.0-tausx/tauex);
      Model.Dkappay[i,j]   = Model.Kappa[i,j]
                             *(1.0-tausy/tauey);
      Model.Drhox[i,j]     = (1.0/Model.Rho[i,j])
                             *(1.0-tausx/tauex);
      Model.Drhoy[i,j]     = (1.0/Model.Rho[i,j])
                             *(1.0-tausy/tauey);
    }
  }

  return(Model);
}
// Modelstability checks velocity model for stability.
float ModelStability(struct model Model)
{
  int nx,ny;
  int i,j;
  float vp,stab;

  nx = Model.Nx;
  ny = Model.Ny;
  for(i=0; i<nx; i=i+1){
    for(j=0; j<ny; j=j+1){
      vp = LibeSqrt(Model.Kappa[i,j]/Model.Rho[i,j]);
      stab = (vp*Model.Dt)/Model.Dx;
      if(stab > 1.0/LibeSqrt(2.0)){
        LibePuts(stderr,"Stability index too large! ");
        LibePutf(stderr,stab);
        LibePuts(stderr,"\n"); 
        LibeFlush(stderr);
      }
    }
  }

  return(stab);
}
// Modeld creates a 1D profile function tapering the left
// and right borders. 
int Modeld(float [*] d, float dx, int nb){
  int i,n;

  n = len(d,0);

  for(i=0; i<n; i=i+1){
    d[i]=1.0;
  }

  // Taper left border
  for(i=0; i<nb;i=i+1){
      d[i] = d[i]*(cast(float,i)*dx)/(cast(float,nb)*dx);
  }

  // taper right border
  for(i=n-1-nb; i<n;i=i+1){
      d[i] = d[i]*(cast(float,n-1-i)*dx)/(cast(float,nb)*dx);
  }

  return(OK);
}
// Modeltaue computes taue from Q and w0.
float Modeltaue(float Q, float w0){
  float tau0,taue; 

  tau0=1.0/w0;
  taue=(tau0/Q)*(LibeSqrt(Q*Q+1.0)-1.0);

  return(taue);
}
// Modeltaus computes taus from Q and w0.
float Modeltaus(float Q, float w0){
  float tau0,taus; 

  tau0=1.0/w0;
  taus=(tau0/Q)*(LibeSqrt(Q*Q+1.0)-1.0);

  return(taus);
}
