include <libe.i>                 /* Library interface                 */
include "model.i"
include "src.i"
include "rec.i"
include "ac2d.i"

int Main(struct MainArg [*] MainArgs)
{
  float [*] wavelet;  // Source pulse
  float [*,*] vp;         //
  float [*,*] rho;         //
  float [*,*] Q;         //
  float f0;

  struct model Model; // Model
  struct rec   Rec;   // Receiver
  struct src   Src;   // Source
  int [*] sx, sy;     // Source x,y-coordinates
  int [*] rx, ry;     // Receiver x,y-coordinates
  struct ac2d  Ac2d;  // FD solver
  int Nx,Ny;       // Model dimension in x- and y-directions.
  int nt,ntr;          // No of time steps
  int resamp, sresamp; // Resampling factors for data and snapshot
  float dt, dx;        // Time sampling and space sampling intervals
  int fd;              // File desriptor for source pulse              
  int i;               // Timestep no
  char  [*] tmp;       // Temporary workspace
  float W0;
  int Nb;
  int Nr,rx0;
  int l;
  float si;

  // Initialize library
  LibeInit();

  // Main modeling parameters
  Nx=201; // x-dimensiom
  Ny=201; // y-dimension
  dx=5.0; // grid interval
  dt=0.0005; // Time sampling
  nt=8001;   // No of timesteps
  l=4;      // Operator length
  f0=25.0;   // Peak frequency
  W0=f0*3.14159*2.0; // Central angular frequency
  Nb = 0;             // Border for PML attenuation

  // Read the velocity model
  fd=LibeOpen("vp.bin","r");
  vp= new(float [Nx,Ny]);
  tmp=cast(char [4*Nx*Ny], vp);
  LibeRead(fd,4*Nx*Ny,tmp); 
  LibeClose(fd);

  // Read the density model
  fd=LibeOpen("rho.bin","r");
  rho= new(float [Nx,Ny]);
  tmp=cast(char [4*Nx*Ny], rho);
  LibeRead(fd,4*Nx*Ny,tmp); 
  LibeClose(fd);

  // Read the attenuation model
  fd=LibeOpen("q.bin","r");
  Q= new(float [Nx,Ny]);
  tmp=cast(char [4*Nx*Ny], Q);
  LibeRead(fd,4*Nx*Ny,tmp); 
  LibeClose(fd);

  // Read a source signature from file
  fd=LibeOpen("src.bin","r");
  tmp = new(char [4*nt]);
  LibeRead(fd,4*nt,tmp); 
  wavelet=cast(float [nt], tmp);
  LibeClose(fd);

  /* Create a source */
  sx=new(int[1]);
  sy=new(int[1]);
  sx[0]= Nx/2;
  sy[0]= Ny/2;
  Src=SrcNew(wavelet,sx,sy);

  /* Create a model   */
  Model = ModelNew(vp,rho,Q,dx,dt,W0,Nb); 
  si=ModelStability(Model);
  LibePuts(stderr,"Stability index: ");
  LibePutf(stderr,si);
  LibePuts(stderr,"\n");
  LibeFlush(stderr);

  // Create a receiver
  Nr=740;
  rx=new(int[Nr]);
  ry=new(int[Nr]);
  rx0=0;
  for(i=0; i<Nr; i=i+1){
    rx[i] = rx0;
    ry[i] = 50;
    rx0=rx0+8;
  }
  resamp=1;   //Output receiver sampling
  sresamp=10; //Output snapshot resampling
  ntr = nt/resamp; //No of output samples per rec
  Rec= RecNew(rx,ry,ntr,resamp,sresamp,"snp.bin");

  /* Create solver    */
  Ac2d = Ac2dNew(Model);

  /* Run solver       */
  Ac2dSolve(Ac2d, Model, Src, Rec, nt,l);

  // Save recording
  RecSave(Rec,"p.bin");

  return(OK);
}
