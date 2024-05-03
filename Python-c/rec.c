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
nctempfloat2 *Qp;
nctempfloat2 *Qr;
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
struct model* ModelNew (nctempfloat2 *kappa,nctempfloat2 *rho,nctempfloat2 *Qp,nctempfloat2 *Qr,float Dx,float Dt,float W0,int Nb,int Rheol);
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
Rec->nt =nt;
int nctemp37=Rec->nr;
nctemp37=nctemp37*Rec->nt;
nctempfloat2 *nctemp36;
nctemp36=(nctempfloat2*)RunMalloc(sizeof(nctempfloat2));
nctemp36->d[0]=Rec->nr;
nctemp36->d[1]=Rec->nt;
nctemp36->a=(float *)RunMalloc(sizeof(float)*nctemp37);
Rec->p=nctemp36;
Rec->resamp =resamp;
Rec->sresamp =sresamp;
Rec->pit =0;
int nctemp54 = (Rec->sresamp > 0);
if(nctemp54)
{
nctempchar1* nctemp62= file;
struct nctempchar1 *nctemp67;
static struct nctempchar1 nctemp68 = {{ 2}, (char*)"w\0"};
nctemp67=&nctemp68;
nctempchar1* nctemp65= nctemp67;
int nctemp69=LibeOpen(nctemp62,nctemp65);
Rec->fd =nctemp69;
}
return Rec;
}
int RecReceiver (struct rec* Rec,int it,nctempfloat2 *p)
{
int pos;
int ixr;
int iyr;
int nctemp79 = Rec->nt - 1;
int nctemp71 = (Rec->pit > nctemp79);
if(nctemp71)
{
return 0;
}
int nctemp84= it;
int nctemp86= Rec->resamp;
int nctemp88=LibeMod(nctemp84,nctemp86);
int nctemp81 = (nctemp88 ==0);
if(nctemp81)
{
pos =0;
int nctemp94 = (pos < Rec->nr);
while(nctemp94){
{
int nctemp102=pos;
ixr =Rec->rx->a[nctemp102];
int nctemp108=pos;
iyr =Rec->ry->a[nctemp108];
int nctemp113=pos;
nctemp113=Rec->pit*Rec->p->d[0]+nctemp113;
int nctemp117=ixr;
nctemp117=iyr*p->d[0]+nctemp117;
Rec->p->a[nctemp113] =p->a[nctemp117];
}
int nctemp128 = pos + 1;
pos =nctemp128;
int nctemp129 = (pos < Rec->nr);
nctemp94=nctemp129;
}
int nctemp141 = Rec->pit + 1;
Rec->pit =nctemp141;
}
return 1;
}
int RecSave (struct rec* Rec,nctempchar1 *file)
{
int fd;
int n;
nctempchar1* nctemp147= file;
struct nctempchar1 *nctemp152;
static struct nctempchar1 nctemp153 = {{ 2}, (char*)"w\0"};
nctemp152=&nctemp153;
nctempchar1* nctemp150= nctemp152;
int nctemp154=LibeOpen(nctemp147,nctemp150);
fd =nctemp154;
int nctemp162=Rec->p->d[0];int nctemp167=Rec->p->d[1];int nctemp171 = nctemp162 * nctemp167;
n =nctemp171;
int nctemp173= fd;
int nctemp180 = 4 * n;
int nctemp175= nctemp180;
nctempchar1 nctemp184;
nctempchar1 *nctemp183;
nctemp184=*(nctempchar1*)(Rec->p);
int nctemp191 = 4 * n;
nctemp184.d[0]=nctemp191;
nctemp183=&nctemp184;
nctempchar1* nctemp181= nctemp183;
int nctemp192=LibeWrite(nctemp173,nctemp175,nctemp181);
int nctemp194= fd;
int nctemp196=LibeClose(nctemp194);
return 1;
}
int RecSnap (struct rec* Rec,int it,nctempfloat2 *snp)
{
int n;
int Nx;
int Ny;
nctempchar1 *tmp;
int nctemp198 = (Rec->sresamp <= 0);
if(nctemp198)
{
return 1;
}
int nctemp207=snp->d[0];Nx =nctemp207;
int nctemp215=snp->d[1];Ny =nctemp215;
int nctemp227 = Nx * Ny;
n =nctemp227;
int nctemp231= it;
int nctemp233= Rec->sresamp;
int nctemp235=LibeMod(nctemp231,nctemp233);
int nctemp228 = (nctemp235 ==0);
if(nctemp228)
{
nctempchar1 nctemp243;
nctempchar1 *nctemp242;
nctemp243=*(nctempchar1*)(snp);
int nctemp250 = 4 * n;
nctemp243.d[0]=nctemp250;
nctemp242=&nctemp243;
tmp=nctemp242;
int nctemp252= Rec->fd;
int nctemp259 = 4 * n;
int nctemp254= nctemp259;
nctempchar1* nctemp260= tmp;
int nctemp263=LibeWrite(nctemp252,nctemp254,nctemp260);
}
return 1;
}
