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
nctempchar1* PyepsCre1ds (int Nx);
int PyepsDel1ds (nctempchar1 *arr);
int PyepsSet1ds (nctempchar1 *arr,int i,char val);
nctempint1* PyepsCre1di (int Nx);
int PyepsDel1di (nctempint1 *arr);
int PyepsSet1di (nctempint1 *arr,int i,int val);
nctempfloat1* PyepsCre1df (int Nx);
int PyepsDel1df (nctempfloat1 *arr);
int PyepsSet1df (nctempfloat1 *arr,int i,float val);
nctempfloat2* PyepsCre2df (int Nx,int Ny);
int PyepsDel2df (nctempfloat2 *arr);
int PyepsSet2df (nctempfloat2 *arr,int i,int j,float val);
int Main (struct nctempMainArg1 *MainArgs)
{
return 1;
}
nctempchar1 * PyepsCre1ds (int Nx)
{
nctempchar1 *str;
int nctemp13 = Nx + 1;
int nctemp8=nctemp13;
nctempchar1 *nctemp7;
nctemp7=(nctempchar1*)RunMalloc(sizeof(nctempchar1));
int nctemp18 = Nx + 1;
nctemp7->d[0]=nctemp18;
nctemp7->a=(char *)RunMalloc(sizeof(char)*nctemp8);
str=nctemp7;
int nctemp22=Nx;
char nctemp25=(char)(0);
str->a[nctemp22] =nctemp25;
return str;
}
int PyepsDel1ds (nctempchar1 *arr)
{
RunFree(arr->a);
RunFree(arr);
return 1;
}
int PyepsSet1ds (nctempchar1 *arr,int i,char val)
{
int nctemp37=i;
arr->a[nctemp37] =val;
return 1;
}
nctempint1 * PyepsCre1di (int Nx)
{
nctempint1 *tmp;
int nctemp47=Nx;
nctempint1 *nctemp46;
nctemp46=(nctempint1*)RunMalloc(sizeof(nctempint1));
nctemp46->d[0]=Nx;
nctemp46->a=(int *)RunMalloc(sizeof(int)*nctemp47);
tmp=nctemp46;
return tmp;
}
int PyepsDel1di (nctempint1 *arr)
{
RunFree(arr->a);
RunFree(arr);
return 1;
}
int PyepsSet1di (nctempint1 *arr,int i,int val)
{
int nctemp59=i;
arr->a[nctemp59] =val;
return 1;
}
nctempfloat1 * PyepsCre1df (int Nx)
{
nctempfloat1 *tmp;
int nctemp69=Nx;
nctempfloat1 *nctemp68;
nctemp68=(nctempfloat1*)RunMalloc(sizeof(nctempfloat1));
nctemp68->d[0]=Nx;
nctemp68->a=(float *)RunMalloc(sizeof(float)*nctemp69);
tmp=nctemp68;
return tmp;
}
int PyepsDel1df (nctempfloat1 *arr)
{
RunFree(arr->a);
RunFree(arr);
return 1;
}
int PyepsSet1df (nctempfloat1 *arr,int i,float val)
{
int nctemp81=i;
arr->a[nctemp81] =val;
return 1;
}
nctempfloat2 * PyepsCre2df (int Nx,int Ny)
{
int nctemp87=Nx;
nctemp87=nctemp87*Ny;
nctempfloat2 *nctemp86;
nctemp86=(nctempfloat2*)RunMalloc(sizeof(nctempfloat2));
nctemp86->d[0]=Nx;
nctemp86->d[1]=Ny;
nctemp86->a=(float *)RunMalloc(sizeof(float)*nctemp87);
return nctemp86;
}
int PyepsDel2df (nctempfloat2 *arr)
{
RunFree(arr->a);
RunFree(arr);
return 1;
}
int PyepsSet2df (nctempfloat2 *arr,int i,int j,float val)
{
int nctemp99=i;
nctemp99=j*arr->d[0]+nctemp99;
arr->a[nctemp99] =val;
return 1;
}
