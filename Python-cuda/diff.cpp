/*  Translated by epsc  version December 2021 */
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
extern "C" {
#include <stdlib.h>
#include <string.h>
}

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
struct diff* DiffNew (int l)
{
struct diff* Diff;
int i;
int j;
int k;
struct diff *nctemp5=(struct diff*)RunMalloc(sizeof(struct diff));
Diff =nctemp5;
Diff->lmax =8;
int nctemp11 = (l < 1);
if(nctemp11)
{
l =1;
}
int nctemp19 = (l > Diff->lmax);
if(nctemp19)
{
l =Diff->lmax;
}
Diff->l =l;
int nctemp37=Diff->lmax;
nctemp37=nctemp37*Diff->lmax;
nctempfloat2 *nctemp36;
nctemp36=(nctempfloat2*)RunMalloc(sizeof(nctempfloat2));
nctemp36->d[0]=Diff->lmax;
nctemp36->d[1]=Diff->lmax;
nctemp36->a=(float *)RunMalloc(sizeof(float)*nctemp37);
Diff->coeffs=nctemp36;
int nctemp48=l;
nctempfloat1 *nctemp47;
nctemp47=(nctempfloat1*)RunMalloc(sizeof(nctempfloat1));
nctemp47->d[0]=l;
nctemp47->a=(float *)RunMalloc(sizeof(float)*nctemp48);
Diff->w=nctemp47;
i =0;
int nctemp55 = (i < Diff->lmax);
while(nctemp55){
{
j =0;
int nctemp63 = (j < Diff->lmax);
while(nctemp63){
{
int nctemp70=i;
nctemp70=j*Diff->coeffs->d[0]+nctemp70;
Diff->coeffs->a[nctemp70] =0.0;
}
int nctemp82 = j + 1;
j =nctemp82;
int nctemp83 = (j < Diff->lmax);
nctemp63=nctemp83;
}
}
int nctemp95 = i + 1;
i =nctemp95;
int nctemp96 = (i < Diff->lmax);
nctemp55=nctemp96;
}
int nctemp103=0;
nctemp103=0*Diff->coeffs->d[0]+nctemp103;
Diff->coeffs->a[nctemp103] =1.0021;
int nctemp110=1;
nctemp110=0*Diff->coeffs->d[0]+nctemp110;
Diff->coeffs->a[nctemp110] =1.1452;
int nctemp117=1;
nctemp117=1*Diff->coeffs->d[0]+nctemp117;
float nctemp120= -0.0492;
Diff->coeffs->a[nctemp117] =nctemp120;
int nctemp124=2;
nctemp124=0*Diff->coeffs->d[0]+nctemp124;
Diff->coeffs->a[nctemp124] =1.2036;
int nctemp131=2;
nctemp131=1*Diff->coeffs->d[0]+nctemp131;
float nctemp134= -0.0833;
Diff->coeffs->a[nctemp131] =nctemp134;
int nctemp138=2;
nctemp138=2*Diff->coeffs->d[0]+nctemp138;
Diff->coeffs->a[nctemp138] =0.0097;
int nctemp145=3;
nctemp145=0*Diff->coeffs->d[0]+nctemp145;
Diff->coeffs->a[nctemp145] =1.2316;
int nctemp152=3;
nctemp152=1*Diff->coeffs->d[0]+nctemp152;
float nctemp155= -0.1041;
Diff->coeffs->a[nctemp152] =nctemp155;
int nctemp159=3;
nctemp159=2*Diff->coeffs->d[0]+nctemp159;
Diff->coeffs->a[nctemp159] =0.0206;
int nctemp166=3;
nctemp166=3*Diff->coeffs->d[0]+nctemp166;
float nctemp169= -0.0035;
Diff->coeffs->a[nctemp166] =nctemp169;
int nctemp173=4;
nctemp173=0*Diff->coeffs->d[0]+nctemp173;
Diff->coeffs->a[nctemp173] =1.2463;
int nctemp180=4;
nctemp180=1*Diff->coeffs->d[0]+nctemp180;
float nctemp183= -0.1163;
Diff->coeffs->a[nctemp180] =nctemp183;
int nctemp187=4;
nctemp187=2*Diff->coeffs->d[0]+nctemp187;
Diff->coeffs->a[nctemp187] =0.0290;
int nctemp194=4;
nctemp194=3*Diff->coeffs->d[0]+nctemp194;
float nctemp197= -0.0080;
Diff->coeffs->a[nctemp194] =nctemp197;
int nctemp201=4;
nctemp201=4*Diff->coeffs->d[0]+nctemp201;
Diff->coeffs->a[nctemp201] =0.0018;
int nctemp208=5;
nctemp208=0*Diff->coeffs->d[0]+nctemp208;
Diff->coeffs->a[nctemp208] =1.2542;
int nctemp215=5;
nctemp215=1*Diff->coeffs->d[0]+nctemp215;
float nctemp218= -0.1213;
Diff->coeffs->a[nctemp215] =nctemp218;
int nctemp222=5;
nctemp222=2*Diff->coeffs->d[0]+nctemp222;
Diff->coeffs->a[nctemp222] =0.0344;
int nctemp229=5;
nctemp229=3*Diff->coeffs->d[0]+nctemp229;
float nctemp232= -0.017;
Diff->coeffs->a[nctemp229] =nctemp232;
int nctemp236=5;
nctemp236=4*Diff->coeffs->d[0]+nctemp236;
Diff->coeffs->a[nctemp236] =0.0038;
int nctemp243=5;
nctemp243=5*Diff->coeffs->d[0]+nctemp243;
float nctemp246= -0.0011;
Diff->coeffs->a[nctemp243] =nctemp246;
int nctemp250=6;
nctemp250=0*Diff->coeffs->d[0]+nctemp250;
Diff->coeffs->a[nctemp250] =1.2593;
int nctemp257=6;
nctemp257=1*Diff->coeffs->d[0]+nctemp257;
float nctemp260= -0.1280;
Diff->coeffs->a[nctemp257] =nctemp260;
int nctemp264=6;
nctemp264=2*Diff->coeffs->d[0]+nctemp264;
Diff->coeffs->a[nctemp264] =0.0384;
int nctemp271=6;
nctemp271=3*Diff->coeffs->d[0]+nctemp271;
float nctemp274= -0.0147;
Diff->coeffs->a[nctemp271] =nctemp274;
int nctemp278=6;
nctemp278=4*Diff->coeffs->d[0]+nctemp278;
Diff->coeffs->a[nctemp278] =0.0059;
int nctemp285=6;
nctemp285=5*Diff->coeffs->d[0]+nctemp285;
float nctemp288= -0.0022;
Diff->coeffs->a[nctemp285] =nctemp288;
int nctemp292=6;
nctemp292=6*Diff->coeffs->d[0]+nctemp292;
Diff->coeffs->a[nctemp292] =0.0007;
int nctemp299=7;
nctemp299=0*Diff->coeffs->d[0]+nctemp299;
Diff->coeffs->a[nctemp299] =1.2626;
int nctemp306=7;
nctemp306=1*Diff->coeffs->d[0]+nctemp306;
float nctemp309= -0.1312;
Diff->coeffs->a[nctemp306] =nctemp309;
int nctemp313=7;
nctemp313=2*Diff->coeffs->d[0]+nctemp313;
Diff->coeffs->a[nctemp313] =0.0412;
int nctemp320=7;
nctemp320=3*Diff->coeffs->d[0]+nctemp320;
float nctemp323= -0.0170;
Diff->coeffs->a[nctemp320] =nctemp323;
int nctemp327=7;
nctemp327=4*Diff->coeffs->d[0]+nctemp327;
Diff->coeffs->a[nctemp327] =0.0076;
int nctemp334=7;
nctemp334=5*Diff->coeffs->d[0]+nctemp334;
float nctemp337= -0.0034;
Diff->coeffs->a[nctemp334] =nctemp337;
int nctemp341=7;
nctemp341=6*Diff->coeffs->d[0]+nctemp341;
Diff->coeffs->a[nctemp341] =0.0014;
int nctemp348=7;
nctemp348=7*Diff->coeffs->d[0]+nctemp348;
float nctemp351= -0.0005;
Diff->coeffs->a[nctemp348] =nctemp351;
k =0;
int nctemp356 = (k < l);
while(nctemp356){
{
int nctemp363=k;
int nctemp371 = l - 1;
int nctemp366=nctemp371;
nctemp366=k*Diff->coeffs->d[0]+nctemp366;
Diff->w->a[nctemp363] =Diff->coeffs->a[nctemp366];
}
int nctemp381 = k + 1;
k =nctemp381;
int nctemp382 = (k < l);
nctemp356=nctemp382;
}
return Diff;
}
__global__ void kernel_DiffDxminus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx);
__global__ void kernel_DiffDxminus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx)
{
int nx;
int ny;
int i;
int j;
int k;
float sum;
int l;
nctempfloat1 *w;
int nctemp391=A->d[0];nx =nctemp391;
int nctemp399=A->d[1];ny =nctemp399;
l =Diff->l;
w=Diff->w;
int nctemp415=0;
int nctemp417=ny;
int nctemp420=0;
int nctemp422=l;
int nctemp413=(nctemp417-nctemp415)*(nctemp422-nctemp420);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp413;nctempno+=blockDim.x*gridDim.x){
i=nctemp420+nctempno/(nctemp417-nctemp415);
j=nctemp415+nctempno%(nctemp417-nctemp415);
{
sum =0.0;
k =1;
int nctemp440 = i + 1;
int nctemp432 = (k < nctemp440);
while(nctemp432){
{
int nctemp456 = k - 1;
int nctemp451=nctemp456;
float nctemp450= -w->a[nctemp451];
int nctemp463 = i - k;
int nctemp458=nctemp463;
nctemp458=j*A->d[0]+nctemp458;
float nctemp465 = nctemp450 * A->a[nctemp458];
float nctemp467 = nctemp465 + sum;
sum =nctemp467;
}
int nctemp476 = k + 1;
k =nctemp476;
int nctemp485 = i + 1;
int nctemp477 = (k < nctemp485);
nctemp432=nctemp477;
}
k =1;
int nctemp498 = l + 1;
int nctemp490 = (k < nctemp498);
while(nctemp490){
{
int nctemp514 = k - 1;
int nctemp509=nctemp514;
int nctemp525 = k - 1;
int nctemp526 = i + nctemp525;
int nctemp516=nctemp526;
nctemp516=j*A->d[0]+nctemp516;
float nctemp528 = w->a[nctemp509] * A->a[nctemp516];
float nctemp530 = nctemp528 + sum;
sum =nctemp530;
}
int nctemp539 = k + 1;
k =nctemp539;
int nctemp548 = l + 1;
int nctemp540 = (k < nctemp548);
nctemp490=nctemp540;
}
int nctemp552=i;
nctemp552=j*dA->d[0]+nctemp552;
float nctemp560 = sum / dx;
dA->a[nctemp552] =nctemp560;
}
}
int nctemp563=0;
int nctemp565=ny;
int nctemp568=l;
int nctemp575 = nx - l;
int nctemp570=nctemp575;
int nctemp561=(nctemp565-nctemp563)*(nctemp570-nctemp568);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp561;nctempno+=blockDim.x*gridDim.x){
i=nctemp568+nctempno/(nctemp565-nctemp563);
j=nctemp563+nctempno%(nctemp565-nctemp563);
{
sum =0.0;
k =1;
int nctemp592 = l + 1;
int nctemp584 = (k < nctemp592);
while(nctemp584){
{
int nctemp608 = k - 1;
int nctemp603=nctemp608;
int nctemp618 = i - k;
int nctemp613=nctemp618;
nctemp613=j*A->d[0]+nctemp613;
float nctemp612= -A->a[nctemp613];
int nctemp630 = k - 1;
int nctemp631 = i + nctemp630;
int nctemp621=nctemp631;
nctemp621=j*A->d[0]+nctemp621;
float nctemp633 = nctemp612 + A->a[nctemp621];
float nctemp634 = w->a[nctemp603] * nctemp633;
float nctemp636 = nctemp634 + sum;
sum =nctemp636;
}
int nctemp645 = k + 1;
k =nctemp645;
int nctemp654 = l + 1;
int nctemp646 = (k < nctemp654);
nctemp584=nctemp646;
}
int nctemp658=i;
nctemp658=j*dA->d[0]+nctemp658;
float nctemp666 = sum / dx;
dA->a[nctemp658] =nctemp666;
}
}
int nctemp669=0;
int nctemp671=ny;
int nctemp680 = nx - l;
int nctemp674=nctemp680;
int nctemp681=nx;
int nctemp667=(nctemp671-nctemp669)*(nctemp681-nctemp674);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp667;nctempno+=blockDim.x*gridDim.x){
i=nctemp674+nctempno/(nctemp671-nctemp669);
j=nctemp669+nctempno%(nctemp671-nctemp669);
{
sum =0.0;
k =1;
int nctemp699 = l + 1;
int nctemp691 = (k < nctemp699);
while(nctemp691){
{
int nctemp715 = k - 1;
int nctemp710=nctemp715;
float nctemp709= -w->a[nctemp710];
int nctemp722 = i - k;
int nctemp717=nctemp722;
nctemp717=j*A->d[0]+nctemp717;
float nctemp724 = nctemp709 * A->a[nctemp717];
float nctemp726 = nctemp724 + sum;
sum =nctemp726;
}
int nctemp735 = k + 1;
k =nctemp735;
int nctemp744 = l + 1;
int nctemp736 = (k < nctemp744);
nctemp691=nctemp736;
}
k =1;
int nctemp760 = nx - i;
int nctemp762 = nctemp760 + 1;
int nctemp749 = (k < nctemp762);
while(nctemp749){
{
int nctemp778 = k - 1;
int nctemp773=nctemp778;
int nctemp789 = k - 1;
int nctemp790 = i + nctemp789;
int nctemp780=nctemp790;
nctemp780=j*A->d[0]+nctemp780;
float nctemp792 = w->a[nctemp773] * A->a[nctemp780];
float nctemp794 = nctemp792 + sum;
sum =nctemp794;
}
int nctemp803 = k + 1;
k =nctemp803;
int nctemp815 = nx - i;
int nctemp817 = nctemp815 + 1;
int nctemp804 = (k < nctemp817);
nctemp749=nctemp804;
}
int nctemp821=i;
nctemp821=j*dA->d[0]+nctemp821;
float nctemp829 = sum / dx;
dA->a[nctemp821] =nctemp829;
}
}
}
int DiffDxminus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx)
{
  kernel_DiffDxminus<<< RunGetnb(),RunGetnt() >>>(Diff,A,dA,dx);
GpuError();
return(1);
}
__global__ void kernel_DiffDxplus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx);
__global__ void kernel_DiffDxplus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx)
{
int nx;
int ny;
int i;
int j;
int k;
float sum;
int l;
nctempfloat1 *w;
int nctemp834=A->d[0];nx =nctemp834;
int nctemp842=A->d[1];ny =nctemp842;
l =Diff->l;
w=Diff->w;
int nctemp858=0;
int nctemp860=ny;
int nctemp863=0;
int nctemp865=l;
int nctemp856=(nctemp860-nctemp858)*(nctemp865-nctemp863);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp856;nctempno+=blockDim.x*gridDim.x){
i=nctemp863+nctempno/(nctemp860-nctemp858);
j=nctemp858+nctempno%(nctemp860-nctemp858);
{
sum =0.0;
k =1;
int nctemp883 = i + 2;
int nctemp875 = (k < nctemp883);
while(nctemp875){
{
int nctemp899 = k - 1;
int nctemp894=nctemp899;
float nctemp893= -w->a[nctemp894];
int nctemp910 = k - 1;
int nctemp911 = i - nctemp910;
int nctemp901=nctemp911;
nctemp901=j*A->d[0]+nctemp901;
float nctemp913 = nctemp893 * A->a[nctemp901];
float nctemp915 = nctemp913 + sum;
sum =nctemp915;
}
int nctemp924 = k + 1;
k =nctemp924;
int nctemp933 = i + 2;
int nctemp925 = (k < nctemp933);
nctemp875=nctemp925;
}
k =1;
int nctemp946 = l + 1;
int nctemp938 = (k < nctemp946);
while(nctemp938){
{
int nctemp962 = k - 1;
int nctemp957=nctemp962;
int nctemp969 = i + k;
int nctemp964=nctemp969;
nctemp964=j*A->d[0]+nctemp964;
float nctemp971 = w->a[nctemp957] * A->a[nctemp964];
float nctemp973 = nctemp971 + sum;
sum =nctemp973;
}
int nctemp982 = k + 1;
k =nctemp982;
int nctemp991 = l + 1;
int nctemp983 = (k < nctemp991);
nctemp938=nctemp983;
}
int nctemp995=i;
nctemp995=j*dA->d[0]+nctemp995;
float nctemp1003 = sum / dx;
dA->a[nctemp995] =nctemp1003;
}
}
int nctemp1006=0;
int nctemp1008=ny;
int nctemp1011=l;
int nctemp1018 = nx - l;
int nctemp1013=nctemp1018;
int nctemp1004=(nctemp1008-nctemp1006)*(nctemp1013-nctemp1011);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp1004;nctempno+=blockDim.x*gridDim.x){
i=nctemp1011+nctempno/(nctemp1008-nctemp1006);
j=nctemp1006+nctempno%(nctemp1008-nctemp1006);
{
sum =0.0;
k =1;
int nctemp1035 = l + 1;
int nctemp1027 = (k < nctemp1035);
while(nctemp1027){
{
int nctemp1051 = k - 1;
int nctemp1046=nctemp1051;
int nctemp1065 = k - 1;
int nctemp1066 = i - nctemp1065;
int nctemp1056=nctemp1066;
nctemp1056=j*A->d[0]+nctemp1056;
float nctemp1055= -A->a[nctemp1056];
int nctemp1074 = i + k;
int nctemp1069=nctemp1074;
nctemp1069=j*A->d[0]+nctemp1069;
float nctemp1076 = nctemp1055 + A->a[nctemp1069];
float nctemp1077 = w->a[nctemp1046] * nctemp1076;
float nctemp1079 = nctemp1077 + sum;
sum =nctemp1079;
}
int nctemp1088 = k + 1;
k =nctemp1088;
int nctemp1097 = l + 1;
int nctemp1089 = (k < nctemp1097);
nctemp1027=nctemp1089;
}
int nctemp1101=i;
nctemp1101=j*dA->d[0]+nctemp1101;
float nctemp1109 = sum / dx;
dA->a[nctemp1101] =nctemp1109;
}
}
int nctemp1112=0;
int nctemp1114=ny;
int nctemp1123 = nx - l;
int nctemp1117=nctemp1123;
int nctemp1124=nx;
int nctemp1110=(nctemp1114-nctemp1112)*(nctemp1124-nctemp1117);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp1110;nctempno+=blockDim.x*gridDim.x){
i=nctemp1117+nctempno/(nctemp1114-nctemp1112);
j=nctemp1112+nctempno%(nctemp1114-nctemp1112);
{
sum =0.0;
k =1;
int nctemp1142 = l + 1;
int nctemp1134 = (k < nctemp1142);
while(nctemp1134){
{
int nctemp1158 = k - 1;
int nctemp1153=nctemp1158;
float nctemp1152= -w->a[nctemp1153];
int nctemp1169 = k - 1;
int nctemp1170 = i - nctemp1169;
int nctemp1160=nctemp1170;
nctemp1160=j*A->d[0]+nctemp1160;
float nctemp1172 = nctemp1152 * A->a[nctemp1160];
float nctemp1174 = nctemp1172 + sum;
sum =nctemp1174;
}
int nctemp1183 = k + 1;
k =nctemp1183;
int nctemp1192 = l + 1;
int nctemp1184 = (k < nctemp1192);
nctemp1134=nctemp1184;
}
k =1;
int nctemp1205 = nx - i;
int nctemp1197 = (k < nctemp1205);
while(nctemp1197){
{
int nctemp1221 = k - 1;
int nctemp1216=nctemp1221;
int nctemp1228 = i + k;
int nctemp1223=nctemp1228;
nctemp1223=j*A->d[0]+nctemp1223;
float nctemp1230 = w->a[nctemp1216] * A->a[nctemp1223];
float nctemp1232 = nctemp1230 + sum;
sum =nctemp1232;
}
int nctemp1241 = k + 1;
k =nctemp1241;
int nctemp1250 = nx - i;
int nctemp1242 = (k < nctemp1250);
nctemp1197=nctemp1242;
}
int nctemp1254=i;
nctemp1254=j*dA->d[0]+nctemp1254;
float nctemp1262 = sum / dx;
dA->a[nctemp1254] =nctemp1262;
}
}
}
int DiffDxplus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx)
{
  kernel_DiffDxplus<<< RunGetnb(),RunGetnt() >>>(Diff,A,dA,dx);
GpuError();
return(1);
}
__global__ void kernel_DiffDyminus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx);
__global__ void kernel_DiffDyminus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx)
{
int nx;
int ny;
int i;
int j;
int k;
float sum;
int l;
nctempfloat1 *w;
int nctemp1267=A->d[0];nx =nctemp1267;
int nctemp1275=A->d[1];ny =nctemp1275;
l =Diff->l;
w=Diff->w;
int nctemp1291=0;
int nctemp1293=l;
int nctemp1296=0;
int nctemp1298=nx;
int nctemp1289=(nctemp1293-nctemp1291)*(nctemp1298-nctemp1296);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp1289;nctempno+=blockDim.x*gridDim.x){
i=nctemp1296+nctempno/(nctemp1293-nctemp1291);
j=nctemp1291+nctempno%(nctemp1293-nctemp1291);
{
sum =0.0;
k =1;
int nctemp1316 = j + 1;
int nctemp1308 = (k < nctemp1316);
while(nctemp1308){
{
int nctemp1332 = k - 1;
int nctemp1327=nctemp1332;
float nctemp1326= -w->a[nctemp1327];
int nctemp1334=i;
int nctemp1340 = j - k;
nctemp1334=nctemp1340*A->d[0]+nctemp1334;
float nctemp1341 = nctemp1326 * A->a[nctemp1334];
float nctemp1343 = nctemp1341 + sum;
sum =nctemp1343;
}
int nctemp1352 = k + 1;
k =nctemp1352;
int nctemp1361 = j + 1;
int nctemp1353 = (k < nctemp1361);
nctemp1308=nctemp1353;
}
k =1;
int nctemp1374 = l + 1;
int nctemp1366 = (k < nctemp1374);
while(nctemp1366){
{
int nctemp1390 = k - 1;
int nctemp1385=nctemp1390;
int nctemp1392=i;
int nctemp1402 = k - 1;
int nctemp1403 = j + nctemp1402;
nctemp1392=nctemp1403*A->d[0]+nctemp1392;
float nctemp1404 = w->a[nctemp1385] * A->a[nctemp1392];
float nctemp1406 = nctemp1404 + sum;
sum =nctemp1406;
}
int nctemp1415 = k + 1;
k =nctemp1415;
int nctemp1424 = l + 1;
int nctemp1416 = (k < nctemp1424);
nctemp1366=nctemp1416;
}
int nctemp1428=i;
nctemp1428=j*dA->d[0]+nctemp1428;
float nctemp1436 = sum / dx;
dA->a[nctemp1428] =nctemp1436;
}
}
int nctemp1439=l;
int nctemp1446 = ny - l;
int nctemp1441=nctemp1446;
int nctemp1448=0;
int nctemp1450=nx;
int nctemp1437=(nctemp1441-nctemp1439)*(nctemp1450-nctemp1448);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp1437;nctempno+=blockDim.x*gridDim.x){
i=nctemp1448+nctempno/(nctemp1441-nctemp1439);
j=nctemp1439+nctempno%(nctemp1441-nctemp1439);
{
sum =0.0;
k =1;
int nctemp1468 = l + 1;
int nctemp1460 = (k < nctemp1468);
while(nctemp1460){
{
int nctemp1484 = k - 1;
int nctemp1479=nctemp1484;
int nctemp1489=i;
int nctemp1495 = j - k;
nctemp1489=nctemp1495*A->d[0]+nctemp1489;
float nctemp1488= -A->a[nctemp1489];
int nctemp1497=i;
int nctemp1507 = k - 1;
int nctemp1508 = j + nctemp1507;
nctemp1497=nctemp1508*A->d[0]+nctemp1497;
float nctemp1509 = nctemp1488 + A->a[nctemp1497];
float nctemp1510 = w->a[nctemp1479] * nctemp1509;
float nctemp1512 = nctemp1510 + sum;
sum =nctemp1512;
}
int nctemp1521 = k + 1;
k =nctemp1521;
int nctemp1530 = l + 1;
int nctemp1522 = (k < nctemp1530);
nctemp1460=nctemp1522;
}
int nctemp1534=i;
nctemp1534=j*dA->d[0]+nctemp1534;
float nctemp1542 = sum / dx;
dA->a[nctemp1534] =nctemp1542;
}
}
int nctemp1551 = ny - l;
int nctemp1545=nctemp1551;
int nctemp1552=ny;
int nctemp1555=0;
int nctemp1557=nx;
int nctemp1543=(nctemp1552-nctemp1545)*(nctemp1557-nctemp1555);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp1543;nctempno+=blockDim.x*gridDim.x){
i=nctemp1555+nctempno/(nctemp1552-nctemp1545);
j=nctemp1545+nctempno%(nctemp1552-nctemp1545);
{
sum =0.0;
k =1;
int nctemp1575 = l + 1;
int nctemp1567 = (k < nctemp1575);
while(nctemp1567){
{
int nctemp1591 = k - 1;
int nctemp1586=nctemp1591;
float nctemp1585= -w->a[nctemp1586];
int nctemp1593=i;
int nctemp1599 = j - k;
nctemp1593=nctemp1599*A->d[0]+nctemp1593;
float nctemp1600 = nctemp1585 * A->a[nctemp1593];
float nctemp1602 = nctemp1600 + sum;
sum =nctemp1602;
}
int nctemp1611 = k + 1;
k =nctemp1611;
int nctemp1620 = l + 1;
int nctemp1612 = (k < nctemp1620);
nctemp1567=nctemp1612;
}
k =1;
int nctemp1636 = ny - j;
int nctemp1638 = nctemp1636 + 1;
int nctemp1625 = (k < nctemp1638);
while(nctemp1625){
{
int nctemp1654 = k - 1;
int nctemp1649=nctemp1654;
int nctemp1656=i;
int nctemp1666 = k - 1;
int nctemp1667 = j + nctemp1666;
nctemp1656=nctemp1667*A->d[0]+nctemp1656;
float nctemp1668 = w->a[nctemp1649] * A->a[nctemp1656];
float nctemp1670 = nctemp1668 + sum;
sum =nctemp1670;
}
int nctemp1679 = k + 1;
k =nctemp1679;
int nctemp1691 = ny - j;
int nctemp1693 = nctemp1691 + 1;
int nctemp1680 = (k < nctemp1693);
nctemp1625=nctemp1680;
}
int nctemp1697=i;
nctemp1697=j*dA->d[0]+nctemp1697;
float nctemp1705 = sum / dx;
dA->a[nctemp1697] =nctemp1705;
}
}
}
int DiffDyminus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx)
{
  kernel_DiffDyminus<<< RunGetnb(),RunGetnt() >>>(Diff,A,dA,dx);
GpuError();
return(1);
}
__global__ void kernel_DiffDyplus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx);
__global__ void kernel_DiffDyplus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx)
{
int nx;
int ny;
int i;
int j;
int k;
float sum;
int l;
nctempfloat1 *w;
int nctemp1710=A->d[0];nx =nctemp1710;
int nctemp1718=A->d[1];ny =nctemp1718;
l =Diff->l;
w=Diff->w;
int nctemp1734=0;
int nctemp1736=l;
int nctemp1739=0;
int nctemp1741=nx;
int nctemp1732=(nctemp1736-nctemp1734)*(nctemp1741-nctemp1739);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp1732;nctempno+=blockDim.x*gridDim.x){
i=nctemp1739+nctempno/(nctemp1736-nctemp1734);
j=nctemp1734+nctempno%(nctemp1736-nctemp1734);
{
sum =0.0;
k =1;
int nctemp1759 = j + 2;
int nctemp1751 = (k < nctemp1759);
while(nctemp1751){
{
int nctemp1775 = k - 1;
int nctemp1770=nctemp1775;
float nctemp1769= -w->a[nctemp1770];
int nctemp1777=i;
int nctemp1787 = k - 1;
int nctemp1788 = j - nctemp1787;
nctemp1777=nctemp1788*A->d[0]+nctemp1777;
float nctemp1789 = nctemp1769 * A->a[nctemp1777];
float nctemp1791 = nctemp1789 + sum;
sum =nctemp1791;
}
int nctemp1800 = k + 1;
k =nctemp1800;
int nctemp1809 = j + 2;
int nctemp1801 = (k < nctemp1809);
nctemp1751=nctemp1801;
}
k =1;
int nctemp1822 = l + 1;
int nctemp1814 = (k < nctemp1822);
while(nctemp1814){
{
int nctemp1838 = k - 1;
int nctemp1833=nctemp1838;
int nctemp1840=i;
int nctemp1846 = j + k;
nctemp1840=nctemp1846*A->d[0]+nctemp1840;
float nctemp1847 = w->a[nctemp1833] * A->a[nctemp1840];
float nctemp1849 = nctemp1847 + sum;
sum =nctemp1849;
}
int nctemp1858 = k + 1;
k =nctemp1858;
int nctemp1867 = l + 1;
int nctemp1859 = (k < nctemp1867);
nctemp1814=nctemp1859;
}
int nctemp1871=i;
nctemp1871=j*dA->d[0]+nctemp1871;
float nctemp1879 = sum / dx;
dA->a[nctemp1871] =nctemp1879;
}
}
int nctemp1882=l;
int nctemp1889 = ny - l;
int nctemp1884=nctemp1889;
int nctemp1891=0;
int nctemp1893=nx;
int nctemp1880=(nctemp1884-nctemp1882)*(nctemp1893-nctemp1891);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp1880;nctempno+=blockDim.x*gridDim.x){
i=nctemp1891+nctempno/(nctemp1884-nctemp1882);
j=nctemp1882+nctempno%(nctemp1884-nctemp1882);
{
sum =0.0;
k =1;
int nctemp1911 = l + 1;
int nctemp1903 = (k < nctemp1911);
while(nctemp1903){
{
int nctemp1927 = k - 1;
int nctemp1922=nctemp1927;
int nctemp1932=i;
int nctemp1942 = k - 1;
int nctemp1943 = j - nctemp1942;
nctemp1932=nctemp1943*A->d[0]+nctemp1932;
float nctemp1931= -A->a[nctemp1932];
int nctemp1945=i;
int nctemp1951 = j + k;
nctemp1945=nctemp1951*A->d[0]+nctemp1945;
float nctemp1952 = nctemp1931 + A->a[nctemp1945];
float nctemp1953 = w->a[nctemp1922] * nctemp1952;
float nctemp1955 = nctemp1953 + sum;
sum =nctemp1955;
}
int nctemp1964 = k + 1;
k =nctemp1964;
int nctemp1973 = l + 1;
int nctemp1965 = (k < nctemp1973);
nctemp1903=nctemp1965;
}
int nctemp1977=i;
nctemp1977=j*dA->d[0]+nctemp1977;
float nctemp1985 = sum / dx;
dA->a[nctemp1977] =nctemp1985;
}
}
int nctemp1994 = ny - l;
int nctemp1988=nctemp1994;
int nctemp1995=ny;
int nctemp1998=0;
int nctemp2000=nx;
int nctemp1986=(nctemp1995-nctemp1988)*(nctemp2000-nctemp1998);
for(int nctempno=blockIdx.x*blockDim.x + threadIdx.x; nctempno<nctemp1986;nctempno+=blockDim.x*gridDim.x){
i=nctemp1998+nctempno/(nctemp1995-nctemp1988);
j=nctemp1988+nctempno%(nctemp1995-nctemp1988);
{
sum =0.0;
k =1;
int nctemp2018 = l + 1;
int nctemp2010 = (k < nctemp2018);
while(nctemp2010){
{
int nctemp2034 = k - 1;
int nctemp2029=nctemp2034;
float nctemp2028= -w->a[nctemp2029];
int nctemp2036=i;
int nctemp2046 = k - 1;
int nctemp2047 = j - nctemp2046;
nctemp2036=nctemp2047*A->d[0]+nctemp2036;
float nctemp2048 = nctemp2028 * A->a[nctemp2036];
float nctemp2050 = nctemp2048 + sum;
sum =nctemp2050;
}
int nctemp2059 = k + 1;
k =nctemp2059;
int nctemp2068 = l + 1;
int nctemp2060 = (k < nctemp2068);
nctemp2010=nctemp2060;
}
k =1;
int nctemp2081 = ny - j;
int nctemp2073 = (k < nctemp2081);
while(nctemp2073){
{
int nctemp2097 = k - 1;
int nctemp2092=nctemp2097;
int nctemp2099=i;
int nctemp2105 = j + k;
nctemp2099=nctemp2105*A->d[0]+nctemp2099;
float nctemp2106 = w->a[nctemp2092] * A->a[nctemp2099];
float nctemp2108 = nctemp2106 + sum;
sum =nctemp2108;
}
int nctemp2117 = k + 1;
k =nctemp2117;
int nctemp2126 = ny - j;
int nctemp2118 = (k < nctemp2126);
nctemp2073=nctemp2118;
}
int nctemp2130=i;
nctemp2130=j*dA->d[0]+nctemp2130;
float nctemp2138 = sum / dx;
dA->a[nctemp2130] =nctemp2138;
}
}
}
int DiffDyplus (struct diff* Diff,nctempfloat2 *A,nctempfloat2 *dA,float dx)
{
  kernel_DiffDyplus<<< RunGetnb(),RunGetnt() >>>(Diff,A,dA,dx);
GpuError();
return(1);
}
