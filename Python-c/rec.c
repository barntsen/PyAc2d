/*  Translated by epsc  version today */
#include <stddef.h>
typedef struct { float r; float i;} complex; 
typedef struct nctempfloat1 { int d[1]; float *a;} nctempfloat1; 
typedef struct nctempint1 { int d[1]; int *a;} nctempint1; 
typedef struct nctempchar1 { int d[1]; char *a;} nctempchar1; 
typedef struct nctempcomplex1 { int d[1]; complex *a;} nctempcomplex1; 
typedef struct nctempfloat2 { int d[2]; float *a;} nctempfloat2; 
typedef struct nctempint2 { int d[2]; int *a;} nctempint2; 
typedef struct nctempchar2 { int d[2]; char *a;} nctempchar2; 
typedef struct nctempcomplex2 { int d[2]; complex *a;} nctempcomplex2; 
typedef struct nctempfloat3 { int d[3]; float *a;} nctempfloat3; 
typedef struct nctempint3 { int d[3]; int *a;} nctempint3; 
typedef struct nctempchar3 { int d[3]; char *a;} nctempchar3; 
typedef struct nctempcomplex3 { int d[3]; complex *a;} nctempcomplex3; 
typedef struct nctempfloat4 { int d[4]; float *a;} nctempfloat4; 
typedef struct nctempint4 { int d[4]; int *a;} nctempint4; 
typedef struct nctempchar4 { int d[4]; char *a;} nctempchar4; 
typedef struct nctempcomplex4 { int d[4]; complex *a;} nctempcomplex4; 
#include <stdlib.h>
#include <string.h>
void *RunMalloc(int n); 
int RunFree(void *n); 
int LibeArrayex (int line,nctempchar1 *name,int ival,int index,int bound);
int LibeClearerr ();
int LibeGeterrno ();
nctempchar1* LibeGeterrstr ();
struct MainArg {nctempchar1 *arg;
};
typedef struct nctempMainArg1 {int d[1]; struct MainArg *a; } nctempMainArg1;
struct nctempMainArg2 {int d[2]; struct MainArg *a; } ;
struct nctempMainArg3 {int d[3]; struct MainArg *a; } ;
struct nctempMainArg4 {int d[4]; struct MainArg *a; } ;
int Main (struct nctempMainArg1 *MainArgs);
int LibeInit ();
int LibeDelete ();
int LibeExit ();
nctempchar1* LibeGetenv (nctempchar1 *name);
int LibeOpen (nctempchar1 *name,nctempchar1 *mode);
int LibeClose (int fp);
int LibeGetc (int fp);
int LibeUngetc (int fp);
int LibeGetw (int fp,nctempchar1 *text);
int LibePs (nctempchar1 *s);
int LibePi (int n);
int LibePf (float r);
int LibePutf (int fp,float r,nctempchar1 *form);
int LibePutc (int fp,int c);
int LibePuts (int fp,nctempchar1 *s);
int LibePuti (int fp,int ival);
int LibeRead (int fp,int n,nctempchar1 *array);
int LibeWrite (int fp,int n,nctempchar1 *array);
int LibeSeek (int fp,int pos,int flag);
int LibeFlush (int fp);
int LibeStrlen (nctempchar1 *s);
int LibeStrcmp (nctempchar1 *s,nctempchar1 *t);
int LibeStrev (nctempchar1 *s);
nctempchar1* LibeStrsave (nctempchar1 *s);
int LibeStrcpy (nctempchar1 *s,nctempchar1 *t);
int LibeStrcat (nctempchar1 *s,nctempchar1 *t);
nctempchar1* LibeStradd (nctempchar1 *t,nctempchar1 *s);
int LibeIsalpha (int c);
int LibeIsdigit (int c);
int LibeIsalnum (int c);
int LibeAtoi (nctempchar1 *s);
int LibeItoa (int n,nctempchar1 *s);
int LibeItoh (int n,nctempchar1 *s);
float LibeAtof (nctempchar1 *s);
int LibeFtoa (float f,nctempchar1 *fmt,nctempchar1 *s);
float LibeMach (int flag);
float LibeFabs (float x);
float LibeFscale2 (float x,int n);
float LibeGetfman2 (float x);
int LibeGetfexp2 (float x);
float LibeFscale (float x,int n);
int LibeGetfman (float f,int maxdig);
float LibeGetffman (float f);
int LibeGetmaxdig (float f);
int LibeGetfexp (float f);
float LibeClock ();
int LibeSetnb (int n);
int LibeSetnt (int n);
int LibeGetnb ();
int LibeGetnt ();
int LibeMod (int n,int r);
float LibeSqrt (float x);
float LibeLn (float x);
float LibeExp (float x);
float LibeSin (float x);
float LibeCos (float x);
float LibeTan (float x);
float LibeArcsin (float x);
float LibeArccos (float x);
float LibeArctan (float x);
float LibePow (float base,float exponent);
int LibeSystem (nctempchar1 *cmd);
struct model {int Nx;
int Ny;
int Nb;
float W0;
nctempfloat2 *Q;
nctempfloat2 *Kappa;
nctempfloat2 *Dkappax;
nctempfloat2 *Dkappay;
nctempfloat2 *Drhox;
nctempfloat2 *Drhoy;
nctempfloat2 *Rho;
nctempfloat2 *Alpha1x;
nctempfloat2 *Alpha1y;
nctempfloat2 *Alpha2x;
nctempfloat2 *Alpha2y;
nctempfloat2 *Eta1x;
nctempfloat2 *Eta1y;
nctempfloat2 *Eta2x;
nctempfloat2 *Eta2y;
nctempfloat1 *dx;
nctempfloat1 *dy;
float Dx;
float Dt;
};
typedef struct nctempmodel1 {int d[1]; struct model *a; } nctempmodel1;
struct nctempmodel2 {int d[2]; struct model *a; } ;
struct nctempmodel3 {int d[3]; struct model *a; } ;
struct nctempmodel4 {int d[4]; struct model *a; } ;
struct model* ModelNew (nctempfloat2 *kappa,nctempfloat2 *rho,nctempfloat2 *Q,float Dx,float Dt,float W0,int Nb,int Rheol);
float ModelStability (struct model* Model);
struct rec {int nr;
nctempint1 *rx;
nctempint1 *ry;
int fd;
int nt;
nctempfloat2 *p;
nctempfloat2 *wrk;
int resamp;
int sresamp;
int pit;
};
typedef struct nctemprec1 {int d[1]; struct rec *a; } nctemprec1;
struct nctemprec2 {int d[2]; struct rec *a; } ;
struct nctemprec3 {int d[3]; struct rec *a; } ;
struct nctemprec4 {int d[4]; struct rec *a; } ;
struct rec* RecNew (nctempint1 *rx,nctempint1 *ry,int nt,int resamp,int sresamp,nctempchar1 *file);
int RecReceiver (struct rec* Rec,int it,nctempfloat2 *p);
int RecSave (struct rec* Rec,nctempchar1 *file);
int RecSnap (struct rec* Rec,int it,nctempfloat2 *snp);
struct rec* RecNew (nctempint1 *rx,nctempint1 *ry,int nt,int resamp,int sresamp,nctempchar1 *file)
{
struct rec* Rec;
struct rec *nctemp5=(struct rec*)RunMalloc(sizeof(struct rec));
Rec =nctemp5;
int nctemp11=rx->d[0];Rec->nr =nctemp11;
Rec->rx=rx;
Rec->ry=ry;
nctempchar1* nctemp31= file;
struct nctempchar1 *nctemp36;
static struct nctempchar1 nctemp37 = {{ 2}, (char*)"w\0"};
nctemp36=&nctemp37;
nctempchar1* nctemp34= nctemp36;
int nctemp38=LibeOpen(nctemp31,nctemp34);
Rec->fd =nctemp38;
Rec->nt =nt;
int nctemp49=Rec->nr;
nctemp49=nctemp49*Rec->nt;
nctempfloat2 *nctemp48;
nctemp48=(nctempfloat2*)RunMalloc(sizeof(nctempfloat2));
nctemp48->d[0]=Rec->nr;
nctemp48->d[1]=Rec->nt;
nctemp48->a=(float *)RunMalloc(sizeof(float)*nctemp49);
Rec->p=nctemp48;
Rec->resamp =resamp;
Rec->sresamp =sresamp;
Rec->pit =0;
return Rec;
}
int RecReceiver (struct rec* Rec,int it,nctempfloat2 *p)
{
int pos;
int ixr;
int iyr;
int nctemp75 = Rec->nt - 1;
int nctemp67 = (Rec->pit > nctemp75);
if(nctemp67)
{
return 0;
}
int nctemp80= it;
int nctemp82= Rec->resamp;
int nctemp84=LibeMod(nctemp80,nctemp82);
int nctemp77 = (nctemp84 ==0);
if(nctemp77)
{
pos =0;
int nctemp90 = (pos < Rec->nr);
while(nctemp90){
{
int nctemp98=pos;
ixr =Rec->rx->a[nctemp98];
int nctemp104=pos;
iyr =Rec->ry->a[nctemp104];
int nctemp109=pos;
nctemp109=Rec->pit*Rec->p->d[0]+nctemp109;
int nctemp113=ixr;
nctemp113=iyr*p->d[0]+nctemp113;
Rec->p->a[nctemp109] =p->a[nctemp113];
}
int nctemp124 = pos + 1;
pos =nctemp124;
int nctemp125 = (pos < Rec->nr);
nctemp90=nctemp125;
}
int nctemp137 = Rec->pit + 1;
Rec->pit =nctemp137;
}
return 1;
}
int RecSave (struct rec* Rec,nctempchar1 *file)
{
int fd;
int n;
nctempchar1* nctemp143= file;
struct nctempchar1 *nctemp148;
static struct nctempchar1 nctemp149 = {{ 2}, (char*)"w\0"};
nctemp148=&nctemp149;
nctempchar1* nctemp146= nctemp148;
int nctemp150=LibeOpen(nctemp143,nctemp146);
fd =nctemp150;
int nctemp158=Rec->p->d[0];int nctemp163=Rec->p->d[1];int nctemp167 = nctemp158 * nctemp163;
n =nctemp167;
int nctemp169= fd;
int nctemp176 = 4 * n;
int nctemp171= nctemp176;
nctempchar1 nctemp180;
nctempchar1 *nctemp179;
nctemp180=*(nctempchar1*)(Rec->p);
int nctemp187 = 4 * n;
nctemp180.d[0]=nctemp187;
nctemp179=&nctemp180;
nctempchar1* nctemp177= nctemp179;
int nctemp188=LibeWrite(nctemp169,nctemp171,nctemp177);
int nctemp190= fd;
int nctemp192=LibeClose(nctemp190);
return 1;
}
int RecSnap (struct rec* Rec,int it,nctempfloat2 *snp)
{
int n;
int Nx;
int Ny;
nctempchar1 *tmp;
int nctemp194 = (Rec->sresamp <= 0);
if(nctemp194)
{
return 1;
}
int nctemp203=snp->d[0];Nx =nctemp203;
int nctemp211=snp->d[1];Ny =nctemp211;
int nctemp223 = Nx * Ny;
n =nctemp223;
int nctemp227= it;
int nctemp229= Rec->sresamp;
int nctemp231=LibeMod(nctemp227,nctemp229);
int nctemp224 = (nctemp231 ==0);
if(nctemp224)
{
nctempchar1 nctemp239;
nctempchar1 *nctemp238;
nctemp239=*(nctempchar1*)(snp);
int nctemp246 = 4 * n;
nctemp239.d[0]=nctemp246;
nctemp238=&nctemp239;
tmp=nctemp238;
int nctemp248= Rec->fd;
int nctemp255 = 4 * n;
int nctemp250= nctemp255;
nctempchar1* nctemp256= tmp;
int nctemp259=LibeWrite(nctemp248,nctemp250,nctemp256);
}
return 1;
}
