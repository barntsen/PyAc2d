// Ac2d object

// Imports
  include <libe.i>             
  include "diff.i"
  include "rec.i"
  include "src.i"
  include "model.i"
  include "ac2d.i"

// Internal functions

  int Ac2dvx(struct ac2d Ac2d, struct model Model){}
  int Ac2dvy(struct ac2d Ac2d, struct model Model){}
  int Ac2dstress(struct ac2d Ac2d, struct model Model){} 

// Public functions

// Ac2dNew creates a new Ac2d object
//
// Parameters:
//   Model : Model object
//
// Return:
//   Ac2d object  
  struct ac2d Ac2dNew(struct model Model){
  struct ac2d Ac2d;
  int i,j;
  
  Ac2d = new(struct ac2d);
  Ac2d.p=new(float [Model.Nx,Model.Ny]); 
  Ac2d.vx=new(float [Model.Nx,Model.Ny]);
  Ac2d.vy=new(float [Model.Nx,Model.Ny]);
  Ac2d.exx=new(float [Model.Nx,Model.Ny]);
  Ac2d.eyy=new(float [Model.Nx,Model.Ny]);
  Ac2d.gammax=new(float [Model.Nx,Model.Ny]);
  Ac2d.gammay=new(float [Model.Nx,Model.Ny]);
  Ac2d.thetax=new(float [Model.Nx,Model.Ny]);
  Ac2d.thetay=new(float [Model.Nx,Model.Ny]);
  
  for (i=0; i<Model.Nx; i=i+1){ 
    for (j=0; j<Model.Ny; j=j+1){ 
      Ac2d.p[i,j]       = 0.0;
      Ac2d.vx[i,j]      = 0.0;
      Ac2d.vy[i,j]      = 0.0;
      Ac2d.exx[i,j]     = 0.0;
      Ac2d.eyy[i,j]     = 0.0;
      Ac2d.gammax[i,j]  = 0.0;
      Ac2d.gammay[i,j]  = 0.0;
      Ac2d.thetax[i,j]  = 0.0;
      Ac2d.thetay[i,j]  = 0.0;
      Ac2d.ts = 0;
    }
  }
  return(Ac2d);
}
// Ac2dSolve computes the solution of the acoustic wave equation.
// The acoustic equation of motion are integrated using Virieux's (1986) stress-velocity scheme.
//
// vx(\xx,t+dt) = dt/rhox [d^+_x sigma(\xx,t)] + dt fx(\xx,t) + vx(\xx,t)
//              + thetax d[1/rhox]
// vy(\xx,t+dt) = dt/rhoz [d^+_y sigma(\xx,t)] + dt fy(\xx,t) + vy(\xx,t)
//              + thetay d[1/rhoy]
//
// \dot{p}(\xx,t+dt) = dt lambda(\xx)[d_x \dot{e}xx + d_y \dot{e}zz] + dt \dot{q}(\xx,t) 
//                   + dt [gammax dK + gammay dK]
//                       + p(\xx,t)
// \dot{e}xx             =  d^-_x vx 
// \dot{e}yy             =  d^-_z vy 
//
//  gammax(\xx, t+dt) = alpha1x gammax(\xx,t) + alpha2x \dot{e}xx 
//  gammay(\xx, t+dt) = alpha1y gammay(\xx,t) + alpha2y \dot{e}yy 
//
//  thetax(\xx, t+dt) = theta1x gammax(\xx,t) + theta2x d^+x p
//  thetay(\xx, t+dt) = theta1y gammay(\xx,t) + theta2y d^+y p
//  
//  Parameters:  
//    Ac2d : Solver object
//    Model: Model object
//    Src  : Source object
//    Rec  : Receiver object
//    nt   : Number of timesteps to do starting with current step  
//    l    : The differentiator operator length
int Ac2dSolve(struct ac2d Ac2d, struct model Model, struct src Src, struct rec Rec,int nt,int l)
{
  int sx,sy;         // Source x,y-coordinates 
  struct diff Diff;  // Differentiator object
  int ns,ne;         // Start stop timesteps
  int i,k;

  float perc,oldperc; // Percentage finished current and old
  int iperc;          // Percentage finished

  Diff = DiffNew(l);  // Create differentiator object

  oldperc=0.0;
  ns=Ac2d.ts;         //Get current timestep 
  ne = ns+nt;         
  for(i=ns; i<ne; i=i+1){

    // Compute spatial derivative of stress
    // Use exx and eyy as temp storage
    DiffDxplus(Diff,Ac2d.p,Ac2d.exx,Model.Dx); // Forward differentiation x-axis
    Ac2dvx(Ac2d,Model);                        // Compute vx
    DiffDyplus(Diff,Ac2d.p,Ac2d.eyy,Model.Dx); // Forward differentiation y-axis
    Ac2dvy(Ac2d,Model);                        // Compute vy

    // Compute time derivative of strains
    DiffDxminus(Diff,Ac2d.vx,Ac2d.exx,Model.Dx); //Compute exx     
    DiffDyminus(Diff,Ac2d.vy,Ac2d.eyy,Model.Dx); //Compute eyy   

    // Update stress

     Ac2dstress(Ac2d,Model);  

    // Add source
    for (k=0; k<Src.Ns;k=k+1){
      sx=Src.Sx[k];
      sy=Src.Sy[k];
      Ac2d.p[sx,sy] = Ac2d.p[sx,sy]
                    + Model.Dt*(Src.Src[i]/(Model.Dx*Model.Dx)) ; 
    }

    // Print progress
    perc=100.0*(cast(float,i)/cast(float,nt-1));
    if(perc-oldperc >= 1.0){
      iperc=cast(int,perc+0.5);
      if(LibeMod(iperc,10)==0){
        LibePuts(stderr,"perc: ");
        LibePuti(stderr,iperc);
        LibePuts(stderr,"\n");
        LibeFlush(stderr);
      }
      oldperc=perc;
   }

    //Record wavefield
    RecReceiver(Rec,i,Ac2d.p); 

    // Record Snapshots
    RecSnap(Rec,i,Ac2d.p);
  }
  return(OK);
}
// Ac2vx computes the x-component of particle velocity
//
// Parameters:
//   Ac2d : Solver object 
//   Model: Model object
int Ac2dvx(struct ac2d Ac2d, struct model Model)
{
  int nx,ny;
  int i,j;

  nx = Model.Nx;
  ny = Model.Ny;
  
  // The derivative of stress in x-direction is stored in exx
  // Scale with inverse density and advance one time step
  parallel(i=0:nx,j=0:ny){
    Ac2d.vx[i,j] = Model.Dt*(1.0/Model.Rho[i,j])*Ac2d.exx[i,j] + Ac2d.vx[i,j]
                 + Model.Dt*Ac2d.thetax[i,j]*Model.Drhox[i,j];
    Ac2d.thetax[i,j]  = Model.Eta1x[i,j]*Ac2d.thetax[i,j] + Model.Eta2x[i,j]*Ac2d.exx[i,j];
  }
}
// Ac2vy computes the y-component of particle velocity
//
// Parameters:
//   Ac2d : Solver object 
//   Model: Model object
int Ac2dvy(struct ac2d Ac2d, struct model Model)
{
  int nx,ny;
  int i,j;

  nx = Model.Nx;
  ny = Model.Ny;
  
  // The derivative of stress in y-direction is stored in eyy
  // Scale with inverse density and advance one time step
  parallel(i=0:nx,j=0:ny){
    Ac2d.vy[i,j] = Model.Dt*(1.0/Model.Rho[i,j])*Ac2d.eyy[i,j] + Ac2d.vy[i,j]
                 + Model.Dt*Ac2d.thetay[i,j]*Model.Drhoy[i,j];
     Ac2d.thetay[i,j]  = Model.Eta1y[i,j]*Ac2d.thetay[i,j] + Model.Eta2y[i,j]*Ac2d.eyy[i,j];
  }
}
// Ac2dstress computes acoustic stress 
//
// Parameters:
//   Ac2d : Solver object 
//   Model: Model object
int Ac2dstress(struct ac2d Ac2d, struct model Model){
  int nx, ny;
  int i,j;

  nx = Model.Nx;
  ny = Model.Ny;

  parallel(i=0:nx,j=0:ny){
    Ac2d.p[i,j] = Model.Dt*Model.Kappa[i,j]*(Ac2d.exx[i,j]+Ac2d.eyy[i,j])  
                  + Ac2d.p[i,j]
                  + Model.Dt*(Ac2d.gammax[i,j]*Model.Dkappax[i,j]
                   +Ac2d.gammay[i,j]*Model.Dkappay[i,j]);
    Ac2d.gammax[i,j] = Model.Alpha1x[i,j]*Ac2d.gammax[i,j] + Model.Alpha2x[i,j]*Ac2d.exx[i,j];
    Ac2d.gammay[i,j] = Model.Alpha1y[i,j]*Ac2d.gammay[i,j] + Model.Alpha2y[i,j]*Ac2d.eyy[i,j];
  }
}
