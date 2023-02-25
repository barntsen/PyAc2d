// Methods for the model struct
//

include <libe.i>  // Standard library
include "model.i" // Model struct definition

//Internal functions
int Modeld(float [*] d, float dx, int nb){}  // 1D profile function
float Modeltaus(float Q, float w0){}         // Compute taus
float Modeltaue(float Q, float w0){}         // Compute taue

// ModelNew creates a new model.
//
// Parameters: 
//
//  - vp :  P-wave velocity model
//  - rho:  Density 
//  - Q  :  Q-values
//  - Dx :  Grid interval in x- and y-directions
//  - Dt :  Modeling time sampling interval
//  - W0 :  Q-model peak angular frequency
//  - Nb :  Width of border attenuation zone (in grid points)
//
// Return:  Model structure
//
// The model is defined by several 2D arrays, with the x-coordinate
// as the first index, and the y-coordinate as the second index.
// A position in the model (x,y) maps to the arrays as [i,j]
// where x=Dx*i, y=Dx*j
// The absorbing boundaries is equal to the CPML method
// but constructed using a visco-elastic medium with
// relaxation specified by a standard-linear solid, while 
// a time dependent density which uses a standard-linear solid
// relaxation mechanism.
//
//                     Nx                        
//    |----------------------------------------------|
//    |           Qmin=1.1                           |
//    |                                              |
//    |           Qmax=Q(x,y=Dx*Nb)                  |
//    |      ----------------------------------      |
//    |      |                                |      |
//    |      |                                |      | Ny
//    |      |      Q(x,y)                    |      |
//    |      |                                |<-Nb->|
//    |      |                                |      |
//    |      |                                |      |
//    |      ----------------------------------      |
//    |                                              |
//    |                                              |
//    |                                              |
//    |-----------------------------------------------
//
// The Boundary condition is implemented by using a strongly
// absorbing medium in a border zone with width Nb.
// The border zone has the same width both in the horizontal
// and vertical directions.
// The medium in the border zone has a Q-value of Qmax
// at the inner bondary (taken from the Q-model) and
// the Q-value is gradualy reduced to Qmin at the outer boundary.
// (See the notes.tex in the Doc directory for the equations.)
struct model ModelNew(float [*,*] vp, float [*,*] rho, float [*,*] Q, 
                      float Dx, float Dt, float W0, int Nb)
{
  struct model Model; // Object to instantiate

  int Nx,Ny;          // Model dimensions in x- and y-directions
  float tau0;         // Relaxation time at Peak 1/Q-value
  
  // Smoothing parameters
  float Qmin, Qmax;       // Minimum and Maximum Q-values in boundary zone
  float tauemin,tauemax;  // Taue values corresponding to Qmin and Qmax
  float tausmin,tausmax;  // Taus values corresponding to Qmin and Qmax
  float argx;             // Temp variabels
  float argy;             // Temp variables

  // Relaxation times
  float tausx, tausy;
  float tauex, tauey;

  int i,j;               // Loop indices

  Model= new(struct model);
  Model.Dx = Dx;
  Model.Dt = Dt;
  Model.Nx = len(vp,0);
  Model.Ny = len(vp,1);
  Model.Nb = Nb;
  Model.W0 = W0;
  Nx = Model.Nx;
  Ny = Model.Ny;
  Model.Rho     =  new(float [Nx,Ny]); // Density
  Model.Q       =  new(float [Nx,Ny]); // Q-values
  Model.Kappa   = new(float [Nx,Ny]);  // Unrelaxed bulk modulus

  // The following parameters are the change in the 
  // bulk modulus caused by visco-elasticity
  // A separate factor is used for the x- and y-directions
  // due to tapering
  Model.Dkappax = new(float [Nx,Ny]);  
  Model.Dkappay = new(float [Nx,Ny]);
  Model.Drhox     = new(float [Nx,Ny]);
  Model.Drhoy     = new(float [Nx,Ny]);

  // Coeffcients used for updating memory functions
  Model.Alpha1x   =  new(float [Nx,Ny]);
  Model.Alpha1y   =  new(float [Nx,Ny]);
  Model.Alpha2x   =  new(float [Nx,Ny]);
  Model.Alpha2y   =  new(float [Nx,Ny]);
  Model.Eta1x   =  new(float [Nx,Ny]);
  Model.Eta1y   =  new(float [Nx,Ny]);
  Model.Eta2x   =  new(float [Nx,Ny]);
  Model.Eta2y   =  new(float [Nx,Ny]);

  // Tapering (profile) functions for
  // the x- and y-directions.
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
      tau0 = 1.0/Model.W0;   // Relaxation time corresponding to absorption top
      Qmin = 1.1;            // MinimumQ-value at the outer boundaries

      // Compute relaxation times corresponding to Qmax and Qmin
      tauemin = (tau0/Qmin)*(LibeSqrt(Qmin*Qmin+1.0)+1.0);
      tauemin = 1.0/tauemin;
      tausmin = (tau0/Qmin)*(LibeSqrt(Qmin*Qmin+1.0)-1.0);
      tausmin = 1.0/tausmin;

      Qmax  = Model.Q[Nb,j];
      tauemax = (tau0/Qmin)*(LibeSqrt(Qmax*Qmax+1.0)+1.0);
      tauemax = 1.0/tauemax;
      tausmax = (tau0/Qmin)*(LibeSqrt(Qmax*Qmax+1.0)-1.0);
      tausmax = 1.0/tausmax;
      // Note that the equations below corresponds to
      // smoothing of the inverse taus with a taper
      // in the x-direction in the left and right border zone
      tauex = tauemin + (tauemax-tauemin)*Model.dx[i];
      tausx = tausmin + (tausmax-tausmin)*Model.dx[i];

      Qmax  = Model.Q[i,Nb];
      tauemax = (tau0/Qmin)*(LibeSqrt(Qmax*Qmax+1.0)+1.0);
      tauemax = 1.0/tauemax;
      tausmax = (tau0/Qmin)*(LibeSqrt(Qmax*Qmax+1.0)-1.0);
      tausmax = 1.0/tausmax;
      // Note that the equations below corresponds to
      // smoothing of the inverse taus with a taper
      // in the y-direction in the top- and bottom border zone
      tauey = tauemin + (tauemax-tauemin)*Model.dy[j];
      tausy = tausmin + (tausmax-tausmin)*Model.dy[j];

      // In the equations below the relaxation times taue and taus
      // are inverses (1/taue, 1/taus)
      // Compute alpha and eta coefficients
      argx = Model.dx[i];
      argy = Model.dy[j];
      // An extra tapering factor of exp(-(x/L)**2)
      // is used to taper coefficeints
      Model.Alpha1x[i,j]   = LibeExp(-argx)*LibeExp(-Model.Dt*tausx);
      Model.Alpha1y[i,j]   = LibeExp(-argy)*LibeExp(-Model.Dt*tausy);
      Model.Alpha2x[i,j]   = Model.Dt*tauex;
      Model.Alpha2y[i,j]   = Model.Dt*tauey;
      Model.Eta1x[i,j]     = LibeExp(-argx)*LibeExp(-Model.Dt*tausx);
      Model.Eta1y[i,j]     = LibeExp(-argy)*LibeExp(-Model.Dt*tausy);
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
// 
// Parameters:
//       
//     - Model : Model object
//
// Return      : Stability index
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
// 
// Parameters:
//
//   d  : Input 1D float array
//   dx : Grid spacing
//   nb : Width of boarder zone   
//   
//   Return: OK if no error, ERR in all other cases.
int Modeld(float [*] d, float dx, int nb){
  int i,n;

  n = len(d,0);

  for(i=0; i<n; i=i+1){
    d[i]=1.0;
  }

  // Taper left border
  for(i=0; i<nb;i=i+1){
      d[i] = d[i]*((cast(float,i)*dx)/(cast(float,nb)*dx)
                 *(cast(float,i)*dx)/(cast(float,nb)*dx));
  }

  // taper right border
  for(i=n-1-nb; i<n;i=i+1){
      d[i] = d[i]*((cast(float,n-1-i)*dx)/(cast(float,nb)*dx)
                 *(cast(float,n-1-i)*dx)/(cast(float,nb)*dx));
  }

  return(OK);
}
