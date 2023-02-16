// Methods for the model struct

include <libe.i>
include "model.i"


// ModelNew creates a new model.
struct model ModelNew(float [*,*] vp, float [*,*] rho, float [*,*] Q, 
                      float Dx, float Dt, float W0, int Nb)
{
  int Nx,Ny;
  int i,j;
  float tau0,tauemin,tausmin,tausmax,tauemax,Qmin,Qmax;
  float arg;
  struct model Model;
  int fd;
  char [*] tmp;
  float argexp;

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
  Model.Tauex   =  new(float [Nx,Ny]);
  Model.Tausx   =  new(float [Nx,Ny]);
  Model.Tauey   =  new(float [Nx,Ny]);
  Model.Tausy   =  new(float [Nx,Ny]);
  Model.Alpha1x   =  new(float [Nx,Ny]);
  Model.Alpha1y   =  new(float [Nx,Ny]);
  Model.Alpha2x   =  new(float [Nx,Ny]);
  Model.Alpha2y   =  new(float [Nx,Ny]);
  Model.Eta1x   =  new(float [Nx,Ny]);
  Model.Eta1y   =  new(float [Nx,Ny]);
  Model.Eta2x   =  new(float [Nx,Ny]);
  Model.Eta2y   =  new(float [Nx,Ny]);

  // Store the model
  for(i=0; i<Nx;i=i+1){
    for(j=0; j<Ny;j=j+1){
      Model.Kappa[i,j] = rho[i,j]*vp[i,j]*vp[i,j];
      Model.Rho[i,j]   = rho[i,j];
      Model.Q[i,j]       = Q[i,j];
    }
  }

  // Compute relaxation times
  tau0 = 1.0/Model.W0;
  for(i=0; i<Nx;i=i+1){
    for(j=0; j<Ny;j=j+1){
      Q = Model.Q;
      Model.Tauex[i,j]   = (tau0/Q[i,j])*(LibeSqrt(Q[i,j]*Q[i,j]+1.0)+1.0);
      Model.Tauex[i,j]   = 1.0/Model.Tauex[i,j];
      Model.Tausx[i,j]   = (tau0/Q[i,j])*(LibeSqrt(Q[i,j]*Q[i,j]+1.0)-1.0);
      Model.Tausx[i,j]   = 1.0/Model.Tausx[i,j];
      Model.Tauey[i,j]   = (tau0/Q[i,j])*(LibeSqrt(Q[i,j]*Q[i,j]+1.0)+1.0);
      Model.Tauey[i,j]   = 1.0/Model.Tauey[i,j];
      Model.Tausy[i,j]   = (tau0/Q[i,j])*(LibeSqrt(Q[i,j]*Q[i,j]+1.0)-1.0);
      Model.Tausy[i,j]   = 1.0/Model.Tausy[i,j];
    }
  }

  if(Model.Nb > 0){
  //
  // Taper the relaxation times
  //

  //
  // Compute value of relaxation times in the attenuating
  // border zone of the model
  Qmin = 1.1;
  Qmax=100000.0;
  tauemin = (tau0/Qmin)*(LibeSqrt(Qmin*Qmin+1.0)+1.0);
  tauemin = 1.0/tauemin;
  tausmin = (tau0/Qmin)*(LibeSqrt(Qmin*Qmin+1.0)-1.0);
  tausmin = 1.0/tausmin;
  tauemax = (tau0/Qmax)*(LibeSqrt(Qmax*Qmax+1.0)+1.0);
  tauemax = 1.0/tauemax;
  tausmax = (tau0/Qmax)*(LibeSqrt(Qmax*Qmax+1.0)-1.0);
  tausmax = 1.0/tausmax;

  argexp=1.0;
  // taper in x-direction left border
  for(i=0; i<Nb;i=i+1){
    for(j=0; j<Ny;j=j+1){
      arg = (cast(float,i)*Dx)/(cast(float,Nb)*Dx);
      Model.Tauex[i,j] = tauemin 
                       + (Model.Tauex[Nb,j]-tauemin)*arg;
      Model.Tausx[i,j] = tausmin 
                       + (Model.Tausx[Nb,j]-tausmin)*arg;
    }
  }

  // taper in x-direction right border
  for(i=Nx-1-Nb; i<Nx;i=i+1){
    for(j=0; j<Ny;j=j+1){
      arg = (cast(float,Nx-1-i)*Dx)/(cast(float,Nb)*Dx);
      Model.Tauex[i,j] = tauemin 
                       + (Model.Tauex[Nb,j]-tauemin)*arg;
      Model.Tausx[i,j] = tausmin 
                       + (Model.Tausx[Nb,j]-tausmin)*arg;
    }
  }

  // taper in y-direction upper border
 for(i=0; i<Nx;i=i+1){
   for(j=0; j<Nb;j=j+1){
      arg = (cast(float,j)*Dx)/(cast(float,Nb)*Dx);
      Model.Tauey[i,j] = tauemin 
                       + (Model.Tauey[i,Nb]-tauemin)*arg;
      Model.Tausy[i,j] = tausmin 
                       + (Model.Tausy[i,Nb]-tausmin)*arg;
    }
  }
  // taper in y-direction lower border
  for(i=0; i<Nx;i=i+1){
    for(j=Ny-1-Nb; j<Ny;j=j+1){
      arg = (cast(float,Ny-1-j)*Dx)/(cast(float,Nb)*Dx);
      Model.Tauey[i,j] = tauemin 
                       + (Model.Tauey[i,Nb]-tauemin)*arg;
      Model.Tausy[i,j] = tausmin 
                       + (Model.Tausy[i,Nb]-tausmin)*arg;
    }
  }
}
  // Compute alpha and eta coefficients
  for(i=0; i<Nx;i=i+1){
    for(j=0; j<Ny;j=j+1){
      Model.Alpha1x[i,j]   = LibeExp(-Model.Dt*Model.Tausx[i,j]);
      Model.Alpha1y[i,j]   = LibeExp(-Model.Dt*Model.Tausy[i,j]);
      Model.Alpha2x[i,j]   = Model.Dt*Model.Tauex[i,j];
      Model.Alpha2y[i,j]   = Model.Dt*Model.Tauey[i,j];
      Model.Eta1x[i,j]     = LibeExp(-Model.Dt*Model.Tausx[i,j]);
      Model.Eta1y[i,j]     = LibeExp(-Model.Dt*Model.Tausy[i,j]);
      Model.Eta2x[i,j]     = Model.Dt*Model.Tauex[i,j];
      Model.Eta2y[i,j]     = Model.Dt*Model.Tauey[i,j];
      Model.Dkappax[i,j]   = Model.Kappa[i,j]
                            *(1.0-Model.Tausx[i,j]/Model.Tauex[i,j]);
      Model.Dkappay[i,j]   = Model.Kappa[i,j]
                             *(1.0-Model.Tausy[i,j]/Model.Tauey[i,j]);
      Model.Drhox[i,j]       = (1.0/Model.Rho[i,j])
                             *(1.0-Model.Tausx[i,j]/Model.Tauex[i,j]);
      Model.Drhoy[i,j]       = (1.0/Model.Rho[i,j])
                             *(1.0-Model.Tausy[i,j]/Model.Tauey[i,j]);
                             
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
      }
    }
  }

  return(stab);
}
