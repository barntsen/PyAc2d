// Ac2d object

// Imports
  include <libe.i>             
  include "diff.i"
  include "rec.i"
  include "src.i"
  include "model.i"
  include "ac2d.i"

// Internal functions

  int Ac2dax(struct ac2d Ac2d, struct model Model){}
  int Ac2day(struct ac2d Ac2d, struct model Model){}
int Ac2dpressure(struct ac2d Ac2d, struct model Model){} 

// Public functions

// Ac2dNew creates a new Ac2d object
//
// Arguments:
//   Model:  Model object
//
// Returns:  Ac2d object
//
struct ac2d Ac2dNew(struct model Model){
  struct ac2d Ac2d;
  int i,j;
  
  Ac2d = new(struct ac2d);
  Ac2d.p0=new(float [Model.Nx,Model.Ny]);
  Ac2d.p1=new(float [Model.Nx,Model.Ny]);
  Ac2d.p2=new(float [Model.Nx,Model.Ny]);
  Ac2d.ax=new(float [Model.Nx,Model.Ny]);
  Ac2d.ay=new(float [Model.Nx,Model.Ny]);
  Ac2d.ex=new(float [Model.Nx,Model.Ny]);
  Ac2d.ey=new(float [Model.Nx,Model.Ny]);
  Ac2d.gammax=new(float [Model.Nx,Model.Ny]);
  Ac2d.gammay=new(float [Model.Nx,Model.Ny]);
  Ac2d.gammasx=new(float [Model.Nx,Model.Ny]);
  Ac2d.gammasy=new(float [Model.Nx,Model.Ny]);
  
  for (i=0; i<Model.Nx; i=i+1){ 
    for (j=0; j<Model.Ny; j=j+1){ 
      Ac2d.p0[i,j] = 0.0;
      Ac2d.p1[i,j] = 0.0;
      Ac2d.p2[i,j] = 0.0;
      Ac2d.ax[i,j] = 0.0;
      Ac2d.ay[i,j] = 0.0;
      Ac2d.ex[i,j] = 0.0;
      Ac2d.ey[i,j] = 0.0;
      Ac2d.gammax[i,j]  = 0.0;
      Ac2d.gammay[i,j]  = 0.0;
      Ac2d.gammasx[i,j] = 0.0;
      Ac2d.gammasy[i,j] = 0.0;
      Ac2d.ts = 0;
    }
  }
  return(Ac2d);
}
// Ac2dSolve computes the solution of the acoustic wave equation
//
// Arguments:
//   Ac2d:   Ac2d object
//   Model:  Model object
//   Src:    Src object
//   nt:     No of time steps
//   l:      Length of differentiators
//
// Returns:  Ac2d object
//  
// The acoustic equation of motion are integrated using Virieux's (1986) stress-velocity scheme.
//
// v_x(\xx,t+dt) = dt/rho_x [d^+_x sigma(\xx,t)] + dt fx(\xx,t) + v_x(\xx,t)
// v_z(\xx,t+dt) = dt/rho_z [d^+_z sigma(\xx,t)] + dt fz(\xx,t) + v_z(\xx,t)
//
// \dot{s}igma(\xx,t+dt) = dt lambda(\xx)[d_x \dot{e}xx + d_z \dot{e}zz] + dt \dot{q}(\xx,t) 
//                       + sigma(\xx,t)
// \dot{e}xx             =  d^-_x vx 
// \dot{e}zz             =  d^-_z vz 
int Ac2dSolve(struct ac2d Ac2d, struct model Model, struct src Src, struct rec Rec,int nt,int l)
{
  int nx,ny;
  int sx,sy;
  int i,k;
  float [*,*] tmp;
  struct diff Diff;
  float perc,oldperc;
  int ns,ne;
  int iperc;

  Diff = DiffNew(l);

  oldperc=0.0;
  ns=Ac2d.ts; 
  ne = ns+nt;
  for(i=ns; i<ne; i=i+1){

    // Compute accelerations
    DiffDxplus(Diff,Ac2d.p1,Ac2d.ex,Model.Dx);       
    Ac2dax(Ac2d,Model);   
    DiffDyplus(Diff,Ac2d.p1,Ac2d.ey,Model.Dx);       
    Ac2day(Ac2d,Model);   

    // Compute strains
    DiffDxminus(Diff,Ac2d.ax,Ac2d.ex,Model.Dx);     
    DiffDyminus(Diff,Ac2d.ay,Ac2d.ey,Model.Dx);    

    // Update pressure

     Ac2dpressure(Ac2d,Model);  

    // Add source
    nx=Model.Nx;
    ny=Model.Ny;
    for (k=0; k<Src.Ns;k=k+1){
      sx=Src.Sx[k];
      sy=Src.Sy[k];
      Ac2d.p2[sx,sy] = Ac2d.p2[sx,sy]
                      +(Model.Dt*Model.Dt)*(Src.Src[i]/(Model.Dx*Model.Dx)) ; 
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
    RecReceiver(Rec,i,Ac2d.p2); 

    // Record Snapshots
    RecSnap(Rec,i,Ac2d.p2);

    /* Move present future pressure p2 to p1
       and present pressure p1 to p0       */ 
    tmp=Ac2d.p0;
    Ac2d.p0=Ac2d.p1;
    Ac2d.p1=Ac2d.p2;
    Ac2d.p2=tmp;
  }
  return(OK);
}
// Ac2ax computes the acceleration
//
int Ac2dax(struct ac2d Ac2d, struct model Model)
{
  int nx,ny;
  int i,j;

  nx = Model.Nx;
  ny = Model.Ny;
  
  parallel(i=0:nx,j=0:ny){
    Ac2d.ax[i,j] = (1.0/Model.Rho[i,j])*Ac2d.ex[i,j] 
                + (1.0/Model.Rho[i,j])*Ac2d.gammasx[i,j]*Model.Dsx[i,j];
    Ac2d.gammasx[i,j] = Ac2d.gammasx[i,j]*Model.Alpha1x[i,j] 
                       + Model.Alpha2x[i,j]*Ac2d.ax[i,j]*Model.Dt; 
  }
}
// Ac2ay computes the acceleration
//
int Ac2day(struct ac2d Ac2d, struct model Model)
{
  int nx,ny;
  int i,j;

  nx = Model.Nx;
  ny = Model.Ny;
  
  parallel(i=0:nx,j=0:ny){
    Ac2d.ay[i,j] = (1.0/Model.Rho[i,j])*Ac2d.ey[i,j] 
               + (1.0/Model.Rho[i,j])*Ac2d.gammasy[i,j]*Model.Dsy[i,j];
    Ac2d.gammasy[i,j] = Ac2d.gammasy[i,j]*Model.Alpha1y[i,j] 
                        + Model.Alpha2y[i,j]*Ac2d.ay[i,j]*Model.Dt; 
  }
}
// Ac2dpressure computes acoustic pressure at current time
//
// Arguments: 
//   Ac2d: Ac2d object
//   Model: Model object
//
// Returns: None 
//
int Ac2dpressure(struct ac2d Ac2d, struct model Model){
  int nx, ny;
  int i,j;

  nx = Model.Nx;
  ny = Model.Ny;

  parallel(i=0:nx,j=0:ny){
    Ac2d.p2[i,j] = 2.0*Ac2d.p1[i,j] - Ac2d.p0[i,j] 
                 + (Model.Dt*Model.Dt)*Model.Kappa[i,j]*(Ac2d.ex[i,j]+Ac2d.ey[i,j]) 
                 + (Model.Dt*Model.Dt)*(Model.Dkappax[i,j]*Ac2d.gammax[i,j]
                 +                      Model.Dkappay[i,j]*Ac2d.gammay[i,j]); 

   Ac2d.gammax[i,j] = Model.Alpha1x[i,j]*Ac2d.gammax[i,j] + Model.Alpha2x[i,j]*Model.Dt*Ac2d.ex[i,j];
   Ac2d.gammay[i,j] = Model.Alpha1y[i,j]*Ac2d.gammay[i,j] + Model.Alpha2y[i,j]*Model.Dt*Ac2d.ey[i,j];
  }
}
