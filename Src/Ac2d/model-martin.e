// Methods for the model struct

include <libe.i>
include "model.i"


// ModelNew creates a new model.
//
//
//@article{Komatitsch2007,
//   title={An unsplit convolutional perfectly matched layer improved 
//          at grazing incidence for the seismic wave equation},
//  author={Komatitsch, Dimitri and Martin, Roland},
//  journal={Geophysics},
//  volume={72},
//  number={5},
//  pages={SM155--SM167},
//  year={2007},
//  publisher={Society of Exploration Geophysicists}
//}

struct model ModelNew(float [*,*] vp, float [*,*] rho, float [*,*] Q, 
                      float Dx, float Dt, float W0, int Nb)
{
  struct model Model;  // Model object of type model
  int Nx,Ny;           // No of Model gridpoints in x and y-directions
                       // (Same as Model.Nx, Model.Ny)
  float d0;            // PML parameter
  float alphamax;      // PML parameter
  float bx,by;         // PML temporaries
  float dx,dy;         // PML temporaries
  float L;             // Length of border zone
  float x,y;           // Distances from edge of model
  
  // Loop indices
  int i,j;

  // DEBUG
  int fd;
  int n;

  Model= new(struct model);
  Model.Dx = Dx;
  Model.Dt = Dt;
  Model.Nx = len(vp,0);
  Model.Ny = len(vp,1);
  Nx = Model.Nx;
  Ny = Model.Ny;
  Model.Nb = Nb;
  Model.W0 = W0;
  Model.Kappa   = new(float [Nx,Ny]);
  Model.Dkappax = new(float [Nx,Ny]);
  Model.Dkappay = new(float [Nx,Ny]);
  Model.Drhox     = new(float [Nx,Ny]);
  Model.Drhoy     = new(float [Nx,Ny]);
  Model.Rho     =  new(float [Nx,Ny]);
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
  Model.alphax   =  new(float [Nx]);
  Model.alphay   =  new(float [Ny]);

  // Store the model
  for(i=0; i<Nx;i=i+1){
    for(j=0; j<Ny;j=j+1){
      Model.Kappa[i,j] = rho[i,j]*vp[i,j]*vp[i,j];
      Model.Rho[i,j]   = rho[i,j];
    }
  }

  // Set the profile functions

  d0 = 341.9;
  alphamax = W0/2.0;
  L = (cast(float,Nb)-1.0)*Dx;

  for(i=0; i<Nx;i=i+1){
      Model.dx[i] = d0;
      Model.alphax[i] = alphamax;
  }
  for(j=0; j<Ny;j=j+1){
      Model.dy[j] = d0;
      Model.alphay[j] = alphamax;
  }
  
  // profile functions left border
  for(i=0; i<Nb;i=i+1){
      x = cast(float,i)*Dx;
      Model.dx[i] = d0*(x/L)*(x/L);
      Model.alphax[i] = alphamax*(x/L);
  }

  // profile functions right border
  for(i=Nx-1-Nb+1; i<Nx;i=i+1){
      x=cast(float,Nx-1-i)*Dx;
      Model.dx[i] = d0*(x/L)*(x/L);
      Model.alphax[i] = alphamax*(x/L);
  }
  // profile functions top border
  for(j=0; j<Nb;j=j+1){
      y = cast(float,j)*Dx;
      Model.dy[j] = d0*(y/L)*(y/L);
      Model.alphay[j] = alphamax*(y/L);
  }
  // profile functions bottom border
  for(j=Ny-1-Nb+1; j<Ny;j=j+1){
      y=cast(float,Ny-1-j)*Dx;
      Model.dy[j] = d0*(y/L)*(y/L);
      Model.alphay[j] = alphamax*(y/L);
  }

  // Compute alpha coefficients
  for(i=0; i<Nx;i=i+1){
    for(j=0; j<Ny;j=j+1){
      bx                   = LibeExp(-Model.dx[i]*Dt)*LibeExp(-Model.alphax[i]*Dt); 
      by                   = LibeExp(-Model.dy[j]*Dt)*LibeExp(-Model.alphay[j]*Dt); 
      Model.Alpha1x[i,j]   = bx;
      Model.Eta1x[i,j]     = bx;
      Model.Alpha1y[i,j]   = by;
      Model.Eta1y[i,j]     = by;
      dx                   = Model.dx[i];
      dy                   = Model.dy[j];
      Model.Alpha2x[i,j]   = dx/(dx+Model.alphax[i])*(bx-1.0);
      Model.Eta2x[i,j]     = dx/(dx+Model.alphax[i])*(bx-1.0);
      Model.Alpha2y[i,j]   = dy/(dy+Model.alphay[j])*(by-1.0);
      Model.Eta2y[i,j]     = dy/(dy+Model.alphay[j])*(by-1.0);
      Model.Dkappax[i,j]   = 1.0;
      Model.Dkappay[i,j]   = 1.0;
      Model.Drhox[i,j]     = Model.Rho[i,j];
      Model.Drhoy[i,j]     = Model.Rho[i,j];
    }
  }
  fd = LibeOpen("dx.bin","w");
  n = Nx;
  LibeWrite(fd,4*n,cast(char [4*n],Model.dx));
  LibeClose(fd);

  fd = LibeOpen("dy.bin","w");
  n = Ny;
  LibeWrite(fd,4*n,cast(char [4*n],Model.dy));
  LibeClose(fd);

  fd = LibeOpen("alphax.bin","w");
  n = Nx;
  LibeWrite(fd,4*n,cast(char [4*n],Model.alphax));
  LibeClose(fd);

  fd = LibeOpen("alphay.bin","w");
  n = Ny;
  LibeWrite(fd,4*n,cast(char [4*n],Model.alphay));
  LibeClose(fd);

  fd = LibeOpen("Alpha1x.bin","w");
  n = Nx*Ny;
  LibeWrite(fd,4*n,cast(char [4*n],Model.Alpha1x));
  LibeClose(fd);

  fd = LibeOpen("Alpha1y.bin","w");
  n = Nx*Ny;
  LibeWrite(fd,4*n,cast(char [4*n],Model.Alpha1y));
  LibeClose(fd);

  fd = LibeOpen("Alpha2x.bin","w");
  n = Nx*Ny;
  LibeWrite(fd,4*n,cast(char [4*n],Model.Alpha2x));
  LibeClose(fd);

  fd = LibeOpen("Alpha2y.bin","w");
  n = Nx*Ny;
  LibeWrite(fd,4*n,cast(char [4*n],Model.Alpha2y));
  LibeClose(fd);
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
