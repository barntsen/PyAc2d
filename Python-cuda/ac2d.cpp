/*  Translated by epsc  version December 2021 */
extern "C" {
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *GpuNew(int n);
void *GpuDelete(void *f);
void *GpuError();
void *RunMalloc(int n);
int RunFree(void * );
int RunSync();
int RunGetnt();
int RunGetnb();
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
struct diff {int l;
int lmax;
nctempfloat2 *coeffs;
nctempfloat1 *w;
};
typedef struct nctempdiff1 {int d[1]; struct diff *a; } nctempdiff1;
struct nctempdiff2 {int d[2]; struct diff *a; } ;
struct nctempdiff3 {int d[3]; struct diff *a; } ;
struct nctempdiff4 {int d[4]; struct diff *a; } ;
struct diff* DiffNew (int l);
int DiffDxminus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx);
int DiffDyminus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx);
int DiffDxplus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx);
int DiffDyplus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx);
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
struct src {nctempfloat1 *Src;
nctempint1 *Sx;
nctempint1 *Sy;
int Ns;
};
typedef struct nctempsrc1 {int d[1]; struct src *a; } nctempsrc1;
struct nctempsrc2 {int d[2]; struct src *a; } ;
struct nctempsrc3 {int d[3]; struct src *a; } ;
struct nctempsrc4 {int d[4]; struct src *a; } ;
struct src* SrcNew (nctempfloat1 *source,nctempint1 *sx,nctempint1 *sy);
int SrcDel (struct src* Src);
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
struct ac2d {nctempfloat2 *p;
nctempfloat2 *vx;
nctempfloat2 *vy;
nctempfloat2 *exx;
nctempfloat2 *eyy;
nctempfloat2 *gammax;
nctempfloat2 *gammay;
nctempfloat2 *thetax;
nctempfloat2 *thetay;
int ts;
};
typedef struct nctempac2d1 {int d[1]; struct ac2d *a; } nctempac2d1;
struct nctempac2d2 {int d[2]; struct ac2d *a; } ;
struct nctempac2d3 {int d[3]; struct ac2d *a; } ;
struct nctempac2d4 {int d[4]; struct ac2d *a; } ;
struct ac2d* Ac2dNew (struct model* Model);
int Ac2dSolve (struct ac2d* Ac2d,struct model* Model,struct src* Src,struct rec* Rec,int nt,int l);
int Ac2dvx (struct ac2d* Ac2d,struct model* Model);
int Ac2dvy (struct ac2d* Ac2d,struct model* Model);
int Ac2dstress (struct ac2d* Ac2d,struct model* Model);
struct ac2d* Ac2dNew (struct model* Model)
{
struct ac2d* Ac2d;
int i;
int j;
struct ac2d *nctemp5=(struct ac2d*)RunMalloc(sizeof(struct ac2d));
Ac2d =nctemp5;
int nctemp13=Model->Nx;
nctemp13=nctemp13*Model->Ny;
nctempfloat2 *nctemp12;
nctemp12=(nctempfloat2*)RunMalloc(sizeof(nctempfloat2));
nctemp12->d[0]=Model->Nx;
nctemp12->d[1]=Model->Ny;
nctemp12->a=(float *)RunMalloc(sizeof(float)*nctemp13);
Ac2d->p=nctemp12;
int nctemp24=Model->Nx;
nctemp24=nctemp24*Model->Ny;
nctempfloat2 *nctemp23;
nctemp23=(nctempfloat2*)RunMalloc(sizeof(nctempfloat2));
nctemp23->d[0]=Model->Nx;
nctemp23->d[1]=Model->Ny;
nctemp23->a=(float *)RunMalloc(sizeof(float)*nctemp24);
Ac2d->vx=nctemp23;
int nctemp35=Model->Nx;
nctemp35=nctemp35*Model->Ny;
nctempfloat2 *nctemp34;
nctemp34=(nctempfloat2*)RunMalloc(sizeof(nctempfloat2));
nctemp34->d[0]=Model->Nx;
nctemp34->d[1]=Model->Ny;
nctemp34->a=(float *)RunMalloc(sizeof(float)*nctemp35);
Ac2d->vy=nctemp34;
int nctemp46=Model->Nx;
nctemp46=nctemp46*Model->Ny;
nctempfloat2 *nctemp45;
nctemp45=(nctempfloat2*)RunMalloc(sizeof(nctempfloat2));
nctemp45->d[0]=Model->Nx;
nctemp45->d[1]=Model->Ny;
nctemp45->a=(float *)RunMalloc(sizeof(float)*nctemp46);
Ac2d->exx=nctemp45;
int nctemp57=Model->Nx;
nctemp57=nctemp57*Model->Ny;
nctempfloat2 *nctemp56;
nctemp56=(nctempfloat2*)RunMalloc(sizeof(nctempfloat2));
nctemp56->d[0]=Model->Nx;
nctemp56->d[1]=Model->Ny;
nctemp56->a=(float *)RunMalloc(sizeof(float)*nctemp57);
Ac2d->eyy=nctemp56;
int nctemp68=Model->Nx;
nctemp68=nctemp68*Model->Ny;
nctempfloat2 *nctemp67;
nctemp67=(nctempfloat2*)RunMalloc(sizeof(nctempfloat2));
nctemp67->d[0]=Model->Nx;
nctemp67->d[1]=Model->Ny;
nctemp67->a=(float *)RunMalloc(sizeof(float)*nctemp68);
Ac2d->gammax=nctemp67;
int nctemp79=Model->Nx;
nctemp79=nctemp79*Model->Ny;
nctempfloat2 *nctemp78;
nctemp78=(nctempfloat2*)RunMalloc(sizeof(nctempfloat2));
nctemp78->d[0]=Model->Nx;
nctemp78->d[1]=Model->Ny;
nctemp78->a=(float *)RunMalloc(sizeof(float)*nctemp79);
Ac2d->gammay=nctemp78;
int nctemp90=Model->Nx;
nctemp90=nctemp90*Model->Ny;
nctempfloat2 *nctemp89;
nctemp89=(nctempfloat2*)RunMalloc(sizeof(nctempfloat2));
nctemp89->d[0]=Model->Nx;
nctemp89->d[1]=Model->Ny;
nctemp89->a=(float *)RunMalloc(sizeof(float)*nctemp90);
Ac2d->thetax=nctemp89;
int nctemp101=Model->Nx;
nctemp101=nctemp101*Model->Ny;
nctempfloat2 *nctemp100;
nctemp100=(nctempfloat2*)RunMalloc(sizeof(nctempfloat2));
nctemp100->d[0]=Model->Nx;
nctemp100->d[1]=Model->Ny;
nctemp100->a=(float *)RunMalloc(sizeof(float)*nctemp101);
Ac2d->thetay=nctemp100;
i =0;
int nctemp110 = (i < Model->Nx);
while(nctemp110){
{
j =0;
int nctemp118 = (j < Model->Ny);
while(nctemp118){
{
int nctemp125=i;
nctemp125=j*Ac2d->p->d[0]+nctemp125;
Ac2d->p->a[nctemp125] =0.0;
int nctemp132=i;
nctemp132=j*Ac2d->vx->d[0]+nctemp132;
Ac2d->vx->a[nctemp132] =0.0;
int nctemp139=i;
nctemp139=j*Ac2d->vy->d[0]+nctemp139;
Ac2d->vy->a[nctemp139] =0.0;
int nctemp146=i;
nctemp146=j*Ac2d->exx->d[0]+nctemp146;
Ac2d->exx->a[nctemp146] =0.0;
int nctemp153=i;
nctemp153=j*Ac2d->eyy->d[0]+nctemp153;
Ac2d->eyy->a[nctemp153] =0.0;
int nctemp160=i;
nctemp160=j*Ac2d->gammax->d[0]+nctemp160;
Ac2d->gammax->a[nctemp160] =0.0;
int nctemp167=i;
nctemp167=j*Ac2d->gammay->d[0]+nctemp167;
Ac2d->gammay->a[nctemp167] =0.0;
int nctemp174=i;
nctemp174=j*Ac2d->thetax->d[0]+nctemp174;
Ac2d->thetax->a[nctemp174] =0.0;
int nctemp181=i;
nctemp181=j*Ac2d->thetay->d[0]+nctemp181;
Ac2d->thetay->a[nctemp181] =0.0;
Ac2d->ts =0;
}
int nctemp197 = j + 1;
j =nctemp197;
int nctemp198 = (j < Model->Ny);
nctemp118=nctemp198;
}
}
int nctemp210 = i + 1;
i =nctemp210;
int nctemp211 = (i < Model->Nx);
nctemp110=nctemp211;
}
return Ac2d;
}
int Ac2dSolve (struct ac2d* Ac2d,struct model* Model,struct src* Src,struct rec* Rec,int nt,int l)
{
int sx;
int sy;
struct diff* Diff;
int ns;
int ne;
int i;
int k;
float perc;
float oldperc;
int iperc;
int nctemp220= l;
struct diff* nctemp222=DiffNew(nctemp220);
Diff =nctemp222;
oldperc =0.0;
ns =Ac2d->ts;
int nctemp239 = ns + nt;
ne =nctemp239;
i =ns;
int nctemp244 = (i < ne);
while(nctemp244){
{
struct diff* nctemp249= Diff;
nctempfloat2* nctemp251= Ac2d->p;
nctempfloat2* nctemp254= Ac2d->exx;
float nctemp257= Model->Dx;
int nctemp259=DiffDxplus(nctemp249,nctemp251,nctemp254,nctemp257);
struct ac2d* nctemp261= Ac2d;
struct model* nctemp263= Model;
int nctemp265=Ac2dvx(nctemp261,nctemp263);
struct diff* nctemp267= Diff;
nctempfloat2* nctemp269= Ac2d->p;
nctempfloat2* nctemp272= Ac2d->eyy;
float nctemp275= Model->Dx;
int nctemp277=DiffDyplus(nctemp267,nctemp269,nctemp272,nctemp275);
struct ac2d* nctemp279= Ac2d;
struct model* nctemp281= Model;
int nctemp283=Ac2dvy(nctemp279,nctemp281);
struct diff* nctemp285= Diff;
nctempfloat2* nctemp287= Ac2d->vx;
nctempfloat2* nctemp290= Ac2d->exx;
float nctemp293= Model->Dx;
int nctemp295=DiffDxminus(nctemp285,nctemp287,nctemp290,nctemp293);
struct diff* nctemp297= Diff;
nctempfloat2* nctemp299= Ac2d->vy;
nctempfloat2* nctemp302= Ac2d->eyy;
float nctemp305= Model->Dx;
int nctemp307=DiffDyminus(nctemp297,nctemp299,nctemp302,nctemp305);
struct ac2d* nctemp309= Ac2d;
struct model* nctemp311= Model;
int nctemp313=Ac2dstress(nctemp309,nctemp311);
k =0;
int nctemp318 = (k < Src->Ns);
while(nctemp318){
{
int nctemp326=k;
sx =Src->Sx->a[nctemp326];
int nctemp332=k;
sy =Src->Sy->a[nctemp332];
int nctemp337=sx;
nctemp337=sy*Ac2d->p->d[0]+nctemp337;
int nctemp344=sx;
nctemp344=sy*Ac2d->p->d[0]+nctemp344;
int nctemp355=i;
float nctemp362 = Model->Dx * Model->Dx;
float nctemp363 = Src->Src->a[nctemp355] / nctemp362;
float nctemp364 = Model->Dt * nctemp363;
float nctemp365 = Ac2d->p->a[nctemp344] + nctemp364;
Ac2d->p->a[nctemp337] =nctemp365;
}
int nctemp374 = k + 1;
k =nctemp374;
int nctemp375 = (k < Src->Ns);
nctemp318=nctemp375;
}
float nctemp390=(float)(i);
int nctemp403 = ne - ns;
int nctemp405 = nctemp403 - 1;
float nctemp394=(float)(nctemp405);
float nctemp406 = nctemp390 / nctemp394;
float nctemp407 = 1000.0 * nctemp406;
perc =nctemp407;
float nctemp415 = perc - oldperc;
int nctemp408 = (nctemp415 >= 10.0);
if(nctemp408)
{
int nctemp424=(int)(perc);
int nctemp428 = nctemp424 / 10;
iperc =nctemp428;
int nctemp432= iperc;
int nctemp434= 10;
int nctemp436=LibeMod(nctemp432,nctemp434);
int nctemp429 = (nctemp436 ==0);
if(nctemp429)
{
int nctemp439= 4;
int nctemp441= iperc;
int nctemp443=LibePuti(nctemp439,nctemp441);
int nctemp445= 4;
struct nctempchar1 *nctemp449;
static struct nctempchar1 nctemp450 = {{ 3}, (char*)"\n\0"};
nctemp449=&nctemp450;
nctempchar1* nctemp447= nctemp449;
int nctemp451=LibePuts(nctemp445,nctemp447);
int nctemp453= 4;
int nctemp455=LibeFlush(nctemp453);
}
oldperc =perc;
}
struct rec* nctemp461= Rec;
int nctemp463= i;
nctempfloat2* nctemp465= Ac2d->p;
int nctemp468=RecReceiver(nctemp461,nctemp463,nctemp465);
struct rec* nctemp470= Rec;
int nctemp472= i;
nctempfloat2* nctemp474= Ac2d->p;
int nctemp477=RecSnap(nctemp470,nctemp472,nctemp474);
}
int nctemp486 = i + 1;
i =nctemp486;
int nctemp487 = (i < ne);
nctemp244=nctemp487;
}
return 1;
}
__global__ void kernel_Ac2dvx (struct ac2d* Ac2d,struct model* Model);
__global__ void kernel_Ac2dvx (struct ac2d* Ac2d,struct model* Model)
{
int nx;
int ny;
int i;
int j;
nx =Model->Nx;
ny =Model->Ny;
int nctemp502=0;
int nctemp504=nx;
int nctemp507=0;
int nctemp509=ny;
int nctemp500=(nctemp504-nctemp502)*(nctemp509-nctemp507);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp500;nctempno+=blockDim.x*gridDim.x){
j=nctemp507+nctempno/(nctemp504-nctemp502);
i=nctemp502+nctempno%(nctemp504-nctemp502);
{
int nctemp514=i;
nctemp514=j*Ac2d->vx->d[0]+nctemp514;
int nctemp531=i;
nctemp531=j*Model->Rho->d[0]+nctemp531;
float nctemp534 = Model->Dt * Model->Rho->a[nctemp531];
int nctemp536=i;
nctemp536=j*Ac2d->exx->d[0]+nctemp536;
float nctemp539 = nctemp534 * Ac2d->exx->a[nctemp536];
int nctemp541=i;
nctemp541=j*Ac2d->vx->d[0]+nctemp541;
float nctemp544 = nctemp539 + Ac2d->vx->a[nctemp541];
int nctemp553=i;
nctemp553=j*Ac2d->thetax->d[0]+nctemp553;
float nctemp556 = Model->Dt * Ac2d->thetax->a[nctemp553];
int nctemp558=i;
nctemp558=j*Model->Drhox->d[0]+nctemp558;
float nctemp561 = nctemp556 * Model->Drhox->a[nctemp558];
float nctemp562 = nctemp544 + nctemp561;
Ac2d->vx->a[nctemp514] =nctemp562;
int nctemp566=i;
nctemp566=j*Ac2d->thetax->d[0]+nctemp566;
int nctemp576=i;
nctemp576=j*Model->Eta1x->d[0]+nctemp576;
int nctemp580=i;
nctemp580=j*Ac2d->thetax->d[0]+nctemp580;
float nctemp583 = Model->Eta1x->a[nctemp576] * Ac2d->thetax->a[nctemp580];
int nctemp588=i;
nctemp588=j*Model->Eta2x->d[0]+nctemp588;
int nctemp592=i;
nctemp592=j*Ac2d->exx->d[0]+nctemp592;
float nctemp595 = Model->Eta2x->a[nctemp588] * Ac2d->exx->a[nctemp592];
float nctemp596 = nctemp583 + nctemp595;
Ac2d->thetax->a[nctemp566] =nctemp596;
}
}
}
int Ac2dvx (struct ac2d* Ac2d,struct model* Model)
{
  kernel_Ac2dvx<<< RunGetnb(),RunGetnt() >>>(Ac2d,Model);
GpuError();
return(1);
}
__global__ void kernel_Ac2dvy (struct ac2d* Ac2d,struct model* Model);
__global__ void kernel_Ac2dvy (struct ac2d* Ac2d,struct model* Model)
{
int nx;
int ny;
int i;
int j;
nx =Model->Nx;
ny =Model->Ny;
int nctemp607=0;
int nctemp609=nx;
int nctemp612=0;
int nctemp614=ny;
int nctemp605=(nctemp609-nctemp607)*(nctemp614-nctemp612);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp605;nctempno+=blockDim.x*gridDim.x){
j=nctemp612+nctempno/(nctemp609-nctemp607);
i=nctemp607+nctempno%(nctemp609-nctemp607);
{
int nctemp619=i;
nctemp619=j*Ac2d->vy->d[0]+nctemp619;
int nctemp636=i;
nctemp636=j*Model->Rho->d[0]+nctemp636;
float nctemp639 = Model->Dt * Model->Rho->a[nctemp636];
int nctemp641=i;
nctemp641=j*Ac2d->eyy->d[0]+nctemp641;
float nctemp644 = nctemp639 * Ac2d->eyy->a[nctemp641];
int nctemp646=i;
nctemp646=j*Ac2d->vy->d[0]+nctemp646;
float nctemp649 = nctemp644 + Ac2d->vy->a[nctemp646];
int nctemp658=i;
nctemp658=j*Ac2d->thetay->d[0]+nctemp658;
float nctemp661 = Model->Dt * Ac2d->thetay->a[nctemp658];
int nctemp663=i;
nctemp663=j*Model->Drhoy->d[0]+nctemp663;
float nctemp666 = nctemp661 * Model->Drhoy->a[nctemp663];
float nctemp667 = nctemp649 + nctemp666;
Ac2d->vy->a[nctemp619] =nctemp667;
int nctemp671=i;
nctemp671=j*Ac2d->thetay->d[0]+nctemp671;
int nctemp681=i;
nctemp681=j*Model->Eta1y->d[0]+nctemp681;
int nctemp685=i;
nctemp685=j*Ac2d->thetay->d[0]+nctemp685;
float nctemp688 = Model->Eta1y->a[nctemp681] * Ac2d->thetay->a[nctemp685];
int nctemp693=i;
nctemp693=j*Model->Eta2y->d[0]+nctemp693;
int nctemp697=i;
nctemp697=j*Ac2d->eyy->d[0]+nctemp697;
float nctemp700 = Model->Eta2y->a[nctemp693] * Ac2d->eyy->a[nctemp697];
float nctemp701 = nctemp688 + nctemp700;
Ac2d->thetay->a[nctemp671] =nctemp701;
}
}
}
int Ac2dvy (struct ac2d* Ac2d,struct model* Model)
{
  kernel_Ac2dvy<<< RunGetnb(),RunGetnt() >>>(Ac2d,Model);
GpuError();
return(1);
}
__global__ void kernel_Ac2dstress (struct ac2d* Ac2d,struct model* Model);
__global__ void kernel_Ac2dstress (struct ac2d* Ac2d,struct model* Model)
{
int nx;
int ny;
int i;
int j;
nx =Model->Nx;
ny =Model->Ny;
int nctemp712=0;
int nctemp714=nx;
int nctemp717=0;
int nctemp719=ny;
int nctemp710=(nctemp714-nctemp712)*(nctemp719-nctemp717);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp710;nctempno+=blockDim.x*gridDim.x){
j=nctemp717+nctempno/(nctemp714-nctemp712);
i=nctemp712+nctempno%(nctemp714-nctemp712);
{
int nctemp724=i;
nctemp724=j*Ac2d->p->d[0]+nctemp724;
int nctemp741=i;
nctemp741=j*Model->Kappa->d[0]+nctemp741;
float nctemp744 = Model->Dt * Model->Kappa->a[nctemp741];
int nctemp749=i;
nctemp749=j*Ac2d->exx->d[0]+nctemp749;
int nctemp753=i;
nctemp753=j*Ac2d->eyy->d[0]+nctemp753;
float nctemp756 = Ac2d->exx->a[nctemp749] + Ac2d->eyy->a[nctemp753];
float nctemp757 = nctemp744 * nctemp756;
int nctemp759=i;
nctemp759=j*Ac2d->p->d[0]+nctemp759;
float nctemp762 = nctemp757 + Ac2d->p->a[nctemp759];
int nctemp774=i;
nctemp774=j*Ac2d->gammax->d[0]+nctemp774;
int nctemp778=i;
nctemp778=j*Model->Dkappax->d[0]+nctemp778;
float nctemp781 = Ac2d->gammax->a[nctemp774] * Model->Dkappax->a[nctemp778];
int nctemp786=i;
nctemp786=j*Ac2d->gammay->d[0]+nctemp786;
int nctemp790=i;
nctemp790=j*Model->Dkappay->d[0]+nctemp790;
float nctemp793 = Ac2d->gammay->a[nctemp786] * Model->Dkappay->a[nctemp790];
float nctemp794 = nctemp781 + nctemp793;
float nctemp795 = Model->Dt * nctemp794;
float nctemp796 = nctemp762 + nctemp795;
Ac2d->p->a[nctemp724] =nctemp796;
int nctemp800=i;
nctemp800=j*Ac2d->gammax->d[0]+nctemp800;
int nctemp810=i;
nctemp810=j*Model->Alpha1x->d[0]+nctemp810;
int nctemp814=i;
nctemp814=j*Ac2d->gammax->d[0]+nctemp814;
float nctemp817 = Model->Alpha1x->a[nctemp810] * Ac2d->gammax->a[nctemp814];
int nctemp822=i;
nctemp822=j*Model->Alpha2x->d[0]+nctemp822;
int nctemp826=i;
nctemp826=j*Ac2d->exx->d[0]+nctemp826;
float nctemp829 = Model->Alpha2x->a[nctemp822] * Ac2d->exx->a[nctemp826];
float nctemp830 = nctemp817 + nctemp829;
Ac2d->gammax->a[nctemp800] =nctemp830;
int nctemp834=i;
nctemp834=j*Ac2d->gammay->d[0]+nctemp834;
int nctemp844=i;
nctemp844=j*Model->Alpha1y->d[0]+nctemp844;
int nctemp848=i;
nctemp848=j*Ac2d->gammay->d[0]+nctemp848;
float nctemp851 = Model->Alpha1y->a[nctemp844] * Ac2d->gammay->a[nctemp848];
int nctemp856=i;
nctemp856=j*Model->Alpha2y->d[0]+nctemp856;
int nctemp860=i;
nctemp860=j*Ac2d->eyy->d[0]+nctemp860;
float nctemp863 = Model->Alpha2y->a[nctemp856] * Ac2d->eyy->a[nctemp860];
float nctemp864 = nctemp851 + nctemp863;
Ac2d->gammay->a[nctemp834] =nctemp864;
}
}
}
int Ac2dstress (struct ac2d* Ac2d,struct model* Model)
{
  kernel_Ac2dstress<<< RunGetnb(),RunGetnt() >>>(Ac2d,Model);
GpuError();
return(1);
}
}
