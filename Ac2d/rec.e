// Rec object

// Imports
include <libe.i>
include "model.i"
include "rec.i"
// RecNew is the constructor for receiver objects.
//
// Arguments:
//   Model:  Model object
//   rx:     Integer array with position of receivers in the 
//           x-direction (gridpoints)
//   ry:     Integer array with position of receivers in the 
//           y-direction (gridpoints)
//   nt:     No of time samples in the receiver data
//   resamp: Resample factor relative to the modelling time sample interval
//   file:   File name for snap shots
//
//  Returns: Receiver object  
//----------------------------------------------------------------------------
struct rec RecNew(int [*] rx, int [*] ry, int nt, 
                  int resamp, int sresamp, char [*] file)
{
  struct rec Rec;

  Rec = new(struct rec);
  Rec.nr = len(rx,0);
  Rec.rx = rx;
  Rec.ry = ry;
  Rec.nt = nt;
  Rec.p = new(float [Rec.nr,Rec.nt]);
  Rec.resamp = resamp;
  Rec.sresamp = sresamp;
  Rec.pit = 0;
  if(Rec.sresamp > 0){
    Rec.fd = LibeOpen(file,"w");
  }
  
  return(Rec);
}  
// RecReciver records data at the receiver
//
// Arguments: 
//  Rec:    : Receiver object
//  it      : Current time step
//  p:      : Pressure data at time step no it
//
// Returns  : Integer (OK or ERR)
//-----------------------------------------------------------------------------
int RecReceiver(struct rec Rec,int it, float [*,*] p)
{
  int pos;
  int ixr,iyr;

  if(Rec.pit > Rec.nt-1){return(ERR);}

  if(LibeMod(it,Rec.resamp) == 0){
    for (pos=0;pos<Rec.nr; pos=pos+1){  
      ixr=Rec.rx[pos];
      iyr=Rec.ry[pos];
      Rec.p[pos,Rec.pit] = p[ixr,iyr];       
    } 
    Rec.pit = Rec.pit+1;
  }
  return(OK);
}
// Recsave stores receiver recording on file
//
// Arguments: 
//  Rec:    : Receiver object
//  file    : Output file name
//
// Returns  : Integer (OK or ERR)
//-----------------------------------------------------------------------------
int RecSave(struct rec Rec, char [*] file)
{
  int fd;
  int n;

  fd = LibeOpen(file,"w");
  n = len(Rec.p,0)*len(Rec.p,1);
  LibeWrite(fd,4*n,cast(char [4*n],Rec.p));
  LibeClose(fd);

  return(OK);
}
// RecSnap records snapshots
//
// Arguments: 
//  Rec:    : Receiver object
//  it      : Current time step       
//  snp     : Pressure data
// Returns  : Integer (OK or ERR)
int RecSnap(struct rec Rec,int it, float [*,*] snp)
{
  int n;
  int Nx, Ny;
  char [*] tmp;
  
  if (Rec.sresamp <= 0){
    return(OK);
  }
  Nx = len(snp,0);
  Ny = len(snp,1);
  n = Nx*Ny;
  if(LibeMod(it,Rec.sresamp) == 0){
    tmp = cast(char [4*n],snp);
    LibeWrite(Rec.fd,4*n,tmp);
  }
  return(OK);
}
