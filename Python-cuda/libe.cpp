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
int RunCreate (nctempchar1 *name);
float RunClock ();
int RunOpen (nctempchar1 *name,nctempchar1 *mode);
int RunClose (int fd);
int RunRead (int fd,int lbuff,nctempchar1 *buffer);
int RunWrite (int fd,int lbuff,nctempchar1 *buffer);
int RunSeek (int fd,int pos,int flag);
nctempchar1* RunGetenv (nctempchar1 *name);
int RunStrcmp (nctempchar1 *s,nctempchar1 *t);
int RunStrlen (nctempchar1 *s);
int RunExit ();
int RunSystem (nctempchar1 *cmd);
int LibeErrno;
nctempchar1 *LibeErrstr;
int LibeErrinit ();
int LibeErrinit ()
{
LibeErrno =1;
LibeErrstr=(0);
return 1;
}
int LibeGeterrno ()
{
return LibeErrno;
}
int LibeClearerr ()
{
LibeErrno =1;
return 1;
}
nctempchar1 * LibeGeterrstr ()
{
return LibeErrstr;
}
nctempchar1 * LibeGetenv (nctempchar1 *name)
{
nctempchar1* nctemp20= name;
nctempchar1* nctemp23=RunGetenv(nctemp20);
return nctemp23;
}
int LibeArrayex (int line,nctempchar1 *name,int ival,int index,int bound)
{
int nctemp25= 4;
struct nctempchar1 *nctemp29;
static struct nctempchar1 nctemp30 = {{ 37}, (char*)"Array index out of bond at line no: \0"};
nctemp29=&nctemp30;
nctempchar1* nctemp27= nctemp29;
int nctemp31=LibePuts(nctemp25,nctemp27);
int nctemp33= 4;
int nctemp35= line;
int nctemp37=LibePuti(nctemp33,nctemp35);
int nctemp39= 4;
struct nctempchar1 *nctemp43;
static struct nctempchar1 nctemp44 = {{ 3}, (char*)"\n\0"};
nctemp43=&nctemp44;
nctempchar1* nctemp41= nctemp43;
int nctemp45=LibePuts(nctemp39,nctemp41);
int nctemp47= 4;
struct nctempchar1 *nctemp51;
static struct nctempchar1 nctemp52 = {{ 13}, (char*)"Array name: \0"};
nctemp51=&nctemp52;
nctempchar1* nctemp49= nctemp51;
int nctemp53=LibePuts(nctemp47,nctemp49);
int nctemp55= 4;
nctempchar1* nctemp57= name;
int nctemp60=LibePuts(nctemp55,nctemp57);
int nctemp62= 4;
struct nctempchar1 *nctemp66;
static struct nctempchar1 nctemp67 = {{ 3}, (char*)"\n\0"};
nctemp66=&nctemp67;
nctempchar1* nctemp64= nctemp66;
int nctemp68=LibePuts(nctemp62,nctemp64);
int nctemp70= 4;
struct nctempchar1 *nctemp74;
static struct nctempchar1 nctemp75 = {{ 11}, (char*)"Index no: \0"};
nctemp74=&nctemp75;
nctempchar1* nctemp72= nctemp74;
int nctemp76=LibePuts(nctemp70,nctemp72);
int nctemp78= 4;
int nctemp80= index;
int nctemp82=LibePuti(nctemp78,nctemp80);
int nctemp84= 4;
struct nctempchar1 *nctemp88;
static struct nctempchar1 nctemp89 = {{ 3}, (char*)"\n\0"};
nctemp88=&nctemp89;
nctempchar1* nctemp86= nctemp88;
int nctemp90=LibePuts(nctemp84,nctemp86);
int nctemp92= 4;
struct nctempchar1 *nctemp96;
static struct nctempchar1 nctemp97 = {{ 14}, (char*)"Index value: \0"};
nctemp96=&nctemp97;
nctempchar1* nctemp94= nctemp96;
int nctemp98=LibePuts(nctemp92,nctemp94);
int nctemp100= 4;
int nctemp102= ival;
int nctemp104=LibePuti(nctemp100,nctemp102);
int nctemp106= 4;
struct nctempchar1 *nctemp110;
static struct nctempchar1 nctemp111 = {{ 3}, (char*)"\n\0"};
nctemp110=&nctemp111;
nctempchar1* nctemp108= nctemp110;
int nctemp112=LibePuts(nctemp106,nctemp108);
int nctemp114= 4;
struct nctempchar1 *nctemp118;
static struct nctempchar1 nctemp119 = {{ 16}, (char*)"Index bound: 0-\0"};
nctemp118=&nctemp119;
nctempchar1* nctemp116= nctemp118;
int nctemp120=LibePuts(nctemp114,nctemp116);
int nctemp122= 4;
int nctemp129 = bound - 1;
int nctemp124= nctemp129;
int nctemp130=LibePuti(nctemp122,nctemp124);
int nctemp132= 4;
struct nctempchar1 *nctemp136;
static struct nctempchar1 nctemp137 = {{ 3}, (char*)"\n\0"};
nctemp136=&nctemp137;
nctempchar1* nctemp134= nctemp136;
int nctemp138=LibePuts(nctemp132,nctemp134);
int nctemp140= 4;
int nctemp142=LibeFlush(nctemp140);
int nctemp144=RunExit();
return 1;
}
int LibeIoinit ();
int LibeMathinit ();
int LibeInit ()
{
int rval;
int nctemp150=LibeErrinit();
rval =nctemp150;
int nctemp155=LibeIoinit();
rval =nctemp155;
int nctemp160=LibeMathinit();
rval =nctemp160;
int nctemp165= 1024;
int nctemp167=LibeSetnb(nctemp165);
rval =nctemp167;
int nctemp172= 1024;
int nctemp174=LibeSetnt(nctemp172);
rval =nctemp174;
return rval;
}
int LibeIodelete ();
int LibeDelete ()
{
int nctemp177=LibeIodelete();
return 1;
}
int LibeExit ()
{
int nctemp180=RunExit();
return 1;
}
struct LibeFdescr {int cnt;
int ptr;
int bufsize;
nctempchar1 *base;
int readflg;
int writflg;
int unbflg;
int errflg;
int eoflg;
int fd;
};
typedef struct nctempLibeFdescr1 {int d[1]; struct LibeFdescr *a; } nctempLibeFdescr1;
struct nctempLibeFdescr2 {int d[2]; struct LibeFdescr *a; } ;
struct nctempLibeFdescr3 {int d[3]; struct LibeFdescr *a; } ;
struct nctempLibeFdescr4 {int d[4]; struct LibeFdescr *a; } ;
struct nctempLibeFdescr1 *LibeFarr;
int LibeFillbuff (int fp);
int LibeFlushbuff (int fp);
nctempchar1 *LibeTmpstr;
int LibeIoinit ()
{
int i;
int nctemp188=40;
struct nctempLibeFdescr1 *nctemp187;
nctemp187=(struct nctempLibeFdescr1*)RunMalloc(sizeof(struct nctempLibeFdescr1));
nctemp187->d[0]=40;
nctemp187->a=(struct LibeFdescr*)RunMalloc(sizeof(struct LibeFdescr)*nctemp188);
LibeFarr=nctemp187;
nctempLibeFdescr1 *nctemp192 =LibeFarr;
int nctemp191 =(nctemp192==0);
if(nctemp191)
{
LibeErrno =(-100);
return 0;
}
i =0;
int nctemp205 = (i < 40);
while(nctemp205){
{
int nctemp212=i;
LibeFarr->a[nctemp212].cnt =0;
int nctemp218=i;
LibeFarr->a[nctemp218].ptr =0;
int nctemp224=i;
LibeFarr->a[nctemp224].bufsize =0;
int nctemp230=i;
LibeFarr->a[nctemp230].base=(0);
int nctemp237=i;
LibeFarr->a[nctemp237].readflg =0;
int nctemp243=i;
LibeFarr->a[nctemp243].writflg =0;
int nctemp249=i;
LibeFarr->a[nctemp249].unbflg =0;
int nctemp255=i;
LibeFarr->a[nctemp255].errflg =1;
int nctemp261=i;
LibeFarr->a[nctemp261].eoflg =0;
int nctemp267=i;
LibeFarr->a[nctemp267].fd =0;
}
int nctemp278 = i + 1;
i =nctemp278;
int nctemp279 = (i < 40);
nctemp205=nctemp279;
}
int nctemp286=0;
int nctemp288= -1;
LibeFarr->a[nctemp286].fd =nctemp288;
int nctemp292=0;
LibeFarr->a[nctemp292].readflg =1;
int nctemp298=1;
int nctemp300= -1;
LibeFarr->a[nctemp298].fd =nctemp300;
int nctemp304=1;
LibeFarr->a[nctemp304].readflg =1;
int nctemp310=2;
LibeFarr->a[nctemp310].fd =0;
int nctemp316=2;
LibeFarr->a[nctemp316].readflg =1;
int nctemp322=3;
LibeFarr->a[nctemp322].fd =1;
int nctemp328=3;
LibeFarr->a[nctemp328].writflg =1;
int nctemp334=4;
LibeFarr->a[nctemp334].fd =2;
int nctemp340=4;
LibeFarr->a[nctemp340].writflg =1;
int nctemp349=64;
nctempchar1 *nctemp348;
nctemp348=(nctempchar1*)RunMalloc(sizeof(nctempchar1));
nctemp348->d[0]=64;
nctemp348->a=(char *)RunMalloc(sizeof(char)*nctemp349);
LibeTmpstr=nctemp348;
nctempchar1 *nctemp353 =LibeTmpstr;
int nctemp352 =(nctemp353==0);
if(nctemp352)
{
LibeErrno =(-100);
return 0;
}
return 1;
}
int LibeIodelete ()
{
int stat;
int fd;
int i;
RunFree(LibeTmpstr->a);
RunFree(LibeTmpstr);
stat =1;
i =0;
int nctemp374 = (i < 40);
while(nctemp374){
{
int nctemp381=i;
nctempchar1 *nctemp379 =LibeFarr->a[nctemp381].base;
int nctemp378 =(nctemp379!=0);
if(nctemp378)
{
int nctemp385 = (i > 4);
if(nctemp385)
{
int nctemp393=i;
fd =LibeFarr->a[nctemp393].fd;
int nctemp399= fd;
int nctemp401=RunClose(nctemp399);
stat =nctemp401;
int nctemp402 = (stat ==0);
if(nctemp402)
{
struct nctempchar1 *nctemp411;
static struct nctempchar1 nctemp412 = {{ 21}, (char*)"Could not close file\0"};
nctemp411=&nctemp412;
LibeErrstr=nctemp411;
LibeErrno =(-106);
}
}
int nctemp421= i;
int nctemp423=LibeFlush(nctemp421);
stat =nctemp423;
int nctemp426=i;
RunFree(LibeFarr->a[nctemp426].base->a);
RunFree(LibeFarr->a[nctemp426].base);
}
}
int nctemp437 = i + 1;
i =nctemp437;
int nctemp438 = (i < 40);
nctemp374=nctemp438;
}
RunFree(LibeFarr->a);
RunFree(LibeFarr);
return stat;
}
int LibeOpen (nctempchar1 *name,nctempchar1 *mode)
{
int fd;
int slot;
int i;
int nctemp449=0;
char nctemp452=(char)('r');
int nctemp446 = (mode->a[nctemp449] !=nctemp452);
if(nctemp446)
{
int nctemp458=0;
char nctemp461=(char)('w');
int nctemp455 = (mode->a[nctemp458] !=nctemp461);
if(nctemp455)
{
int nctemp467=0;
char nctemp470=(char)('a');
int nctemp464 = (mode->a[nctemp467] !=nctemp470);
if(nctemp464)
{
struct nctempchar1 *nctemp478;
static struct nctempchar1 nctemp479 = {{ 20}, (char*)"Unknown file mode\n\0"};
nctemp478=&nctemp479;
LibeErrstr=nctemp478;
LibeErrno =(-103);
return 0;
}
}
}
i =0;
int nctemp492= -1;
slot =nctemp492;
int nctemp496 = (slot < 0);
int nctemp501 = (i < 40);
int nctemp493 = (nctemp496 && nctemp501);
int nctemp505=nctemp493;
while(nctemp505)
{{
int nctemp512=i;
int nctemp509 = (LibeFarr->a[nctemp512].readflg ==0);
int nctemp519=i;
int nctemp516 = (LibeFarr->a[nctemp519].writflg ==0);
int nctemp506 = (nctemp509 && nctemp516);
if(nctemp506)
{
slot =i;
}
int nctemp534 = i + 1;
i =nctemp534;
}
int nctemp538 = (slot < 0);
int nctemp543 = (i < 40);
int nctemp535 = (nctemp538 && nctemp543);
nctemp505=nctemp535;}int nctemp547 = (slot < 0);
if(nctemp547)
{
struct nctempchar1 *nctemp556;
static struct nctempchar1 nctemp557 = {{ 22}, (char*)"Too many open files\n\0"};
nctemp556=&nctemp557;
LibeErrstr=nctemp556;
LibeErrno =(-104);
return 0;
}
int nctemp569=0;
int nctemp566=(int)(mode->a[nctemp569]);
int nctemp563 = (nctemp566 =='w');
if(nctemp563)
{
nctempchar1* nctemp576= name;
int nctemp579=RunCreate(nctemp576);
fd =nctemp579;
}
else{
int nctemp586=0;
int nctemp583=(int)(mode->a[nctemp586]);
int nctemp580 = (nctemp583 =='a');
if(nctemp580)
{
nctempchar1* nctemp596= name;
nctempchar1* nctemp599= mode;
int nctemp602=RunOpen(nctemp596,nctemp599);
fd =nctemp602;
int nctemp589 = (fd ==0);
if(nctemp589)
{
nctempchar1* nctemp608= name;
int nctemp611=RunCreate(nctemp608);
fd =nctemp611;
}
else{
nctempchar1* nctemp616= name;
nctempchar1* nctemp619= mode;
int nctemp622=RunOpen(nctemp616,nctemp619);
fd =nctemp622;
}
}
else{
int nctemp629=0;
int nctemp626=(int)(mode->a[nctemp629]);
int nctemp623 = (nctemp626 =='r');
if(nctemp623)
{
nctempchar1* nctemp636= name;
nctempchar1* nctemp639= mode;
int nctemp642=RunOpen(nctemp636,nctemp639);
fd =nctemp642;
}
else{
struct nctempchar1 *nctemp648;
static struct nctempchar1 nctemp649 = {{ 20}, (char*)"Unknown file mode\n\0"};
nctemp648=&nctemp649;
LibeErrstr=nctemp648;
LibeErrno =(-103);
return 0;
}
}
}
int nctemp655 = (fd ==0);
if(nctemp655)
{
struct nctempchar1 *nctemp664;
static struct nctempchar1 nctemp665 = {{ 20}, (char*)"Could not open file\0"};
nctemp664=&nctemp665;
LibeErrstr=nctemp664;
LibeErrno =(-105);
return 0;
}
int nctemp674=slot;
LibeFarr->a[nctemp674].fd =fd;
int nctemp680=slot;
LibeFarr->a[nctemp680].cnt =0;
int nctemp686=slot;
LibeFarr->a[nctemp686].base=(0);
int nctemp696=0;
int nctemp693=(int)(mode->a[nctemp696]);
int nctemp690 = (nctemp693 =='r');
if(nctemp690)
{
int nctemp702=slot;
LibeFarr->a[nctemp702].readflg =1;
}
else{
int nctemp708=slot;
LibeFarr->a[nctemp708].writflg =1;
}
return slot;
}
int LibeClose (int fp)
{
int fd;
int stat;
int nctemp715=fp;
nctempchar1 *nctemp713 =LibeFarr->a[nctemp715].base;
int nctemp712 =(nctemp713!=0);
if(nctemp712)
{
int nctemp720= fp;
int nctemp722=LibeFlush(nctemp720);
}
int nctemp727=fp;
fd =LibeFarr->a[nctemp727].fd;
int nctemp733= fd;
int nctemp735=RunClose(nctemp733);
stat =nctemp735;
int nctemp736 = (stat ==0);
if(nctemp736)
{
int nctemp743=fp;
LibeFarr->a[nctemp743].errflg =1;
struct nctempchar1 *nctemp751;
static struct nctempchar1 nctemp752 = {{ 21}, (char*)"Could not close file\0"};
nctemp751=&nctemp752;
LibeErrstr=nctemp751;
LibeErrno =(-106);
return 0;
}
int nctemp761=fp;
LibeFarr->a[nctemp761].cnt =0;
int nctemp767=fp;
LibeFarr->a[nctemp767].ptr =0;
int nctemp773=fp;
LibeFarr->a[nctemp773].bufsize =0;
int nctemp779=fp;
nctempchar1 *nctemp777 =LibeFarr->a[nctemp779].base;
int nctemp776 =(nctemp777!=0);
if(nctemp776)
{
int nctemp785=fp;
RunFree(LibeFarr->a[nctemp785].base->a);
RunFree(LibeFarr->a[nctemp785].base);
}
int nctemp791=fp;
LibeFarr->a[nctemp791].base=(0);
int nctemp798=fp;
LibeFarr->a[nctemp798].readflg =0;
int nctemp804=fp;
LibeFarr->a[nctemp804].writflg =0;
int nctemp810=fp;
LibeFarr->a[nctemp810].unbflg =0;
int nctemp816=fp;
LibeFarr->a[nctemp816].errflg =0;
int nctemp822=fp;
LibeFarr->a[nctemp822].eoflg =0;
int nctemp828=fp;
LibeFarr->a[nctemp828].fd =0;
return 1;
}
int LibeGetc (int fp)
{
int nctemp835=fp;
int nctemp832 = (LibeFarr->a[nctemp835].cnt ==0);
if(nctemp832)
{
int nctemp839= fp;
int nctemp841=LibeFillbuff(nctemp839);
return nctemp841;
}
else{
int nctemp845=fp;
int nctemp851=fp;
int nctemp854 = LibeFarr->a[nctemp851].cnt - 1;
LibeFarr->a[nctemp845].cnt =nctemp854;
int nctemp858=fp;
int nctemp864=fp;
int nctemp867 = LibeFarr->a[nctemp864].ptr + 1;
LibeFarr->a[nctemp858].ptr =nctemp867;
int nctemp872=fp;
int nctemp878=fp;
int nctemp881 = LibeFarr->a[nctemp878].ptr - 1;
int nctemp874=nctemp881;
int nctemp869=(int)(LibeFarr->a[nctemp872].base->a[nctemp874]);
return nctemp869;
}
}
int LibeUngetc (int fp)
{
int nctemp885=fp;
int nctemp882 = (LibeFarr->a[nctemp885].eoflg ==1);
if(nctemp882)
{
return (-1);
}
int nctemp892=fp;
int nctemp895=fp;
int nctemp889 = (LibeFarr->a[nctemp892].cnt < LibeFarr->a[nctemp895].bufsize);
if(nctemp889)
{
int nctemp900=fp;
int nctemp906=fp;
int nctemp909 = LibeFarr->a[nctemp906].cnt + 1;
LibeFarr->a[nctemp900].cnt =nctemp909;
int nctemp913=fp;
int nctemp919=fp;
int nctemp922 = LibeFarr->a[nctemp919].ptr - 1;
LibeFarr->a[nctemp913].ptr =nctemp922;
int nctemp926=fp;
int nctemp932=fp;
int nctemp935 = LibeFarr->a[nctemp932].bufsize - 1;
int nctemp923 = (LibeFarr->a[nctemp926].ptr ==nctemp935);
if(nctemp923)
{
int nctemp940=fp;
int nctemp944=fp;
int nctemp942=LibeFarr->a[nctemp944].ptr;
int nctemp937=(int)(LibeFarr->a[nctemp940].base->a[nctemp942]);
return nctemp937;
}
else{
int nctemp950=fp;
int nctemp956=fp;
int nctemp959 = LibeFarr->a[nctemp956].ptr + 1;
int nctemp952=nctemp959;
int nctemp947=(int)(LibeFarr->a[nctemp950].base->a[nctemp952]);
return nctemp947;
}
}
else{
struct nctempchar1 *nctemp965;
static struct nctempchar1 nctemp966 = {{ 15}, (char*)"Pushback error\0"};
nctemp965=&nctemp966;
LibeErrstr=nctemp965;
LibeErrno =(-107);
return (-1);
}
}
int LibeGetw (int fp,nctempchar1 *text)
{
int p;
int ch;
int lim;
int nctemp976=text->d[0];lim =nctemp976;
p =0;
int nctemp985=LibeClearerr();
int nctemp999= fp;
int nctemp1001=LibeGetc(nctemp999);
ch =nctemp1001;
int nctemp992 = (ch ==32);
int nctemp1004 = (ch ==9);
int nctemp989 = (nctemp992 || nctemp1004);
int nctemp1009 = (ch ==10);
int nctemp986 = (nctemp989 || nctemp1009);
int nctemp1013=nctemp986;
while(nctemp1013)
{{
p =0;
}
int nctemp1031= fp;
int nctemp1033=LibeGetc(nctemp1031);
ch =nctemp1033;
int nctemp1024 = (ch ==32);
int nctemp1036 = (ch ==9);
int nctemp1021 = (nctemp1024 || nctemp1036);
int nctemp1041 = (ch ==10);
int nctemp1018 = (nctemp1021 || nctemp1041);
nctemp1013=nctemp1018;}int nctemp1046= fp;
int nctemp1048=LibeUngetc(nctemp1046);
int nctemp1059= fp;
int nctemp1061=LibeGetc(nctemp1059);
ch =nctemp1061;
int nctemp1052 = (ch !=(-1));
int nctemp1064 = (p < lim);
int nctemp1049 = (nctemp1052 && nctemp1064);
int nctemp1068=nctemp1049;
while(nctemp1068)
{{
int nctemp1075 = (ch ==32);
int nctemp1080 = (ch ==9);
int nctemp1072 = (nctemp1075 || nctemp1080);
int nctemp1085 = (ch ==10);
int nctemp1069 = (nctemp1072 || nctemp1085);
if(nctemp1069)
{
int nctemp1090= fp;
int nctemp1092=LibeUngetc(nctemp1090);
int nctemp1096=p;
char nctemp1099=(char)(0);
text->a[nctemp1096] =nctemp1099;
return 1;
}
else{
int nctemp1106=p;
char nctemp1109=(char)(ch);
text->a[nctemp1106] =nctemp1109;
int nctemp1120 = p + 1;
p =nctemp1120;
}
}
int nctemp1131= fp;
int nctemp1133=LibeGetc(nctemp1131);
ch =nctemp1133;
int nctemp1124 = (ch !=(-1));
int nctemp1136 = (p < lim);
int nctemp1121 = (nctemp1124 && nctemp1136);
nctemp1068=nctemp1121;}int nctemp1140 = (p >= lim);
if(nctemp1140)
{
return 0;
}
else{
int nctemp1145 = (ch ==(-1));
if(nctemp1145)
{
return (-1);
}
else{
return 1;
}
}
}
int LibePutc (int fp,int c)
{
int rval;
int nctemp1154=fp;
int nctemp1151 = (LibeFarr->a[nctemp1154].cnt ==0);
if(nctemp1151)
{
int nctemp1158= fp;
int nctemp1160=LibeFlushbuff(nctemp1158);
}
int nctemp1164=fp;
int nctemp1167=fp;
int nctemp1161 = (LibeFarr->a[nctemp1164].cnt ==LibeFarr->a[nctemp1167].bufsize);
if(nctemp1161)
{
int nctemp1173= fp;
int nctemp1175=LibeFlushbuff(nctemp1173);
rval =nctemp1175;
int nctemp1179=fp;
int nctemp1183=fp;
int nctemp1181=LibeFarr->a[nctemp1183].ptr;
char nctemp1186=(char)(c);
LibeFarr->a[nctemp1179].base->a[nctemp1181] =nctemp1186;
int nctemp1192=fp;
int nctemp1198=fp;
int nctemp1201 = LibeFarr->a[nctemp1198].ptr + 1;
LibeFarr->a[nctemp1192].ptr =nctemp1201;
int nctemp1205=fp;
int nctemp1211=fp;
int nctemp1214 = LibeFarr->a[nctemp1211].cnt + 1;
LibeFarr->a[nctemp1205].cnt =nctemp1214;
return rval;
}
else{
int nctemp1219=fp;
int nctemp1223=fp;
int nctemp1221=LibeFarr->a[nctemp1223].ptr;
char nctemp1226=(char)(c);
LibeFarr->a[nctemp1219].base->a[nctemp1221] =nctemp1226;
int nctemp1232=fp;
int nctemp1238=fp;
int nctemp1241 = LibeFarr->a[nctemp1238].cnt + 1;
LibeFarr->a[nctemp1232].cnt =nctemp1241;
int nctemp1245=fp;
int nctemp1251=fp;
int nctemp1254 = LibeFarr->a[nctemp1251].ptr + 1;
LibeFarr->a[nctemp1245].ptr =nctemp1254;
return 1;
}
}
int LibePs (nctempchar1 *s)
{
int nctemp1257= 3;
nctempchar1* nctemp1259= s;
int nctemp1262=LibePuts(nctemp1257,nctemp1259);
return 1;
}
int LibePi (int n)
{
int nctemp1265= 3;
int nctemp1267= n;
int nctemp1269=LibePuti(nctemp1265,nctemp1267);
return 1;
}
int LibePf (float r)
{
int nctemp1272= 3;
float nctemp1274= r;
struct nctempchar1 *nctemp1278;
static struct nctempchar1 nctemp1279 = {{ 2}, (char*)"g\0"};
nctemp1278=&nctemp1279;
nctempchar1* nctemp1276= nctemp1278;
int nctemp1280=LibePutf(nctemp1272,nctemp1274,nctemp1276);
return 1;
}
int LibePuts (int fp,nctempchar1 *s)
{
int ls;
int i;
int nctemp1286=s->d[0];ls =nctemp1286;
i =0;
int nctemp1303=i;
int nctemp1300=(int)(s->a[nctemp1303]);
int nctemp1297 = (nctemp1300 !=0);
int nctemp1307 = (i < ls);
int nctemp1294 = (nctemp1297 && nctemp1307);
int nctemp1311=nctemp1294;
while(nctemp1311)
{{
int nctemp1315= fp;
int nctemp1322=i;
int nctemp1319=(int)(s->a[nctemp1322]);
int nctemp1317= nctemp1319;
int nctemp1324=LibePutc(nctemp1315,nctemp1317);
int nctemp1312 = (nctemp1324 ==0);
if(nctemp1312)
{
struct nctempchar1 *nctemp1331;
static struct nctempchar1 nctemp1332 = {{ 12}, (char*)"write error\0"};
nctemp1331=&nctemp1332;
LibeErrstr=nctemp1331;
LibeErrno =0;
return 0;
}
else{
int nctemp1346 = i + 1;
i =nctemp1346;
}
}
int nctemp1356=i;
int nctemp1353=(int)(s->a[nctemp1356]);
int nctemp1350 = (nctemp1353 !=0);
int nctemp1360 = (i < ls);
int nctemp1347 = (nctemp1350 && nctemp1360);
nctemp1311=nctemp1347;}int nctemp1365= fp;
int nctemp1367=LibeFlushbuff(nctemp1365);
return 1;
}
int LibePuti (int fp,int ival)
{
int nctemp1370= ival;
nctempchar1* nctemp1372= LibeTmpstr;
int nctemp1375=LibeItoa(nctemp1370,nctemp1372);
int nctemp1377= fp;
nctempchar1* nctemp1379= LibeTmpstr;
int nctemp1382=LibePuts(nctemp1377,nctemp1379);
return nctemp1382;
}
int LibePutf (int fp,float fval,nctempchar1 *form)
{
float nctemp1384= fval;
nctempchar1* nctemp1386= form;
nctempchar1* nctemp1389= LibeTmpstr;
int nctemp1392=LibeFtoa(nctemp1384,nctemp1386,nctemp1389);
int nctemp1394= fp;
nctempchar1* nctemp1396= LibeTmpstr;
int nctemp1399=LibePuts(nctemp1394,nctemp1396);
return nctemp1399;
}
int LibeRead (int fp,int n,nctempchar1 *buffer)
{
int rval;
int nctemp1403=fp;
int nctemp1400 = (LibeFarr->a[nctemp1403].readflg !=1);
if(nctemp1400)
{
struct nctempchar1 *nctemp1411;
static struct nctempchar1 nctemp1412 = {{ 26}, (char*)"File not open for reading\0"};
nctemp1411=&nctemp1412;
LibeErrstr=nctemp1411;
LibeErrno =(-109);
return (-1);
}
int nctemp1422=buffer->d[0];int nctemp1418 = (n > nctemp1422);
if(nctemp1418)
{
LibeErrno =(-108);
struct nctempchar1 *nctemp1435;
static struct nctempchar1 nctemp1436 = {{ 30}, (char*)"The buffer array is too small\0"};
nctemp1435=&nctemp1436;
LibeErrstr=nctemp1435;
return 0;
}
int nctemp1444=fp;
int nctemp1442= LibeFarr->a[nctemp1444].fd;
int nctemp1446= n;
nctempchar1* nctemp1448= buffer;
int nctemp1451=RunRead(nctemp1442,nctemp1446,nctemp1448);
rval =nctemp1451;
int nctemp1452 = (rval ==(-1));
if(nctemp1452)
{
int nctemp1459=fp;
LibeFarr->a[nctemp1459].eoflg =1;
rval =(-1);
}
else{
int nctemp1466 = (rval ==0);
if(nctemp1466)
{
int nctemp1473=fp;
LibeFarr->a[nctemp1473].errflg =1;
struct nctempchar1 *nctemp1481;
static struct nctempchar1 nctemp1482 = {{ 11}, (char*)"read error\0"};
nctemp1481=&nctemp1482;
LibeErrstr=nctemp1481;
LibeErrno =0;
int nctemp1490=fp;
LibeFarr->a[nctemp1490].errflg =0;
rval =0;
}
}
return rval;
}
int LibeWrite (int fp,int n,nctempchar1 *buffer)
{
int rval;
int nctemp1502=buffer->d[0];int nctemp1498 = (n > nctemp1502);
if(nctemp1498)
{
LibeErrno =(-108);
struct nctempchar1 *nctemp1515;
static struct nctempchar1 nctemp1516 = {{ 30}, (char*)"The buffer array is too small\0"};
nctemp1515=&nctemp1516;
LibeErrstr=nctemp1515;
return 0;
}
int nctemp1521=fp;
int nctemp1518 = (LibeFarr->a[nctemp1521].writflg !=1);
if(nctemp1518)
{
struct nctempchar1 *nctemp1529;
static struct nctempchar1 nctemp1530 = {{ 26}, (char*)"file not open for writing\0"};
nctemp1529=&nctemp1530;
LibeErrstr=nctemp1529;
LibeErrno =(-110);
return 0;
}
int nctemp1542=fp;
int nctemp1540= LibeFarr->a[nctemp1542].fd;
int nctemp1544= n;
nctempchar1* nctemp1546= buffer;
int nctemp1549=RunWrite(nctemp1540,nctemp1544,nctemp1546);
rval =nctemp1549;
int nctemp1550 = (rval ==0);
if(nctemp1550)
{
int nctemp1557=fp;
LibeFarr->a[nctemp1557].errflg =1;
struct nctempchar1 *nctemp1565;
static struct nctempchar1 nctemp1566 = {{ 12}, (char*)"write error\0"};
nctemp1565=&nctemp1566;
LibeErrstr=nctemp1565;
LibeErrno =0;
int nctemp1574=fp;
LibeFarr->a[nctemp1574].errflg =0;
rval =0;
}
return rval;
}
int LibeSeek (int fp,int pos,int flag)
{
int rval;
int nctemp1588=fp;
int nctemp1586= LibeFarr->a[nctemp1588].fd;
int nctemp1590= pos;
int nctemp1592= flag;
int nctemp1594=RunSeek(nctemp1586,nctemp1590,nctemp1592);
rval =nctemp1594;
int nctemp1595 = (rval ==0);
if(nctemp1595)
{
int nctemp1602=fp;
LibeFarr->a[nctemp1602].errflg =1;
struct nctempchar1 *nctemp1610;
static struct nctempchar1 nctemp1611 = {{ 11}, (char*)"Seek error\0"};
nctemp1610=&nctemp1611;
LibeErrstr=nctemp1610;
LibeErrno =0;
int nctemp1619=fp;
LibeFarr->a[nctemp1619].errflg =0;
rval =0;
}
return rval;
}
int LibeFlush (int fp)
{
int nctemp1628= fp;
int nctemp1630=LibeFlushbuff(nctemp1628);
return nctemp1630;
}
int LibeFillbuff (int fp)
{
int size;
int rval;
int nctemp1634=fp;
int nctemp1631 = (LibeFarr->a[nctemp1634].readflg !=1);
if(nctemp1631)
{
struct nctempchar1 *nctemp1642;
static struct nctempchar1 nctemp1643 = {{ 28}, (char*)"file not open for reading\n\0"};
nctemp1642=&nctemp1643;
LibeErrstr=nctemp1642;
LibeErrno =(-110);
return (-1);
}
int nctemp1652=fp;
int nctemp1649 = (LibeFarr->a[nctemp1652].unbflg ==1);
if(nctemp1649)
{
int nctemp1658=fp;
LibeFarr->a[nctemp1658].bufsize =1;
}
else{
int nctemp1664=fp;
LibeFarr->a[nctemp1664].bufsize =1024;
}
int nctemp1670=fp;
nctempchar1 *nctemp1668 =LibeFarr->a[nctemp1670].base;
int nctemp1667 =(nctemp1668==0);
if(nctemp1667)
{
int nctemp1678=fp;
size =LibeFarr->a[nctemp1678].bufsize;
int nctemp1686=fp;
int nctemp1691=size;
nctempchar1 *nctemp1690;
nctemp1690=(nctempchar1*)RunMalloc(sizeof(nctempchar1));
nctemp1690->d[0]=size;
nctemp1690->a=(char *)RunMalloc(sizeof(char)*nctemp1691);
LibeFarr->a[nctemp1686].base=nctemp1690;
nctempchar1 *nctemp1681 =LibeFarr->a[nctemp1686].base;
int nctemp1680 =(nctemp1681==0);
if(nctemp1680)
{
struct nctempchar1 *nctemp1700;
static struct nctempchar1 nctemp1701 = {{ 24}, (char*)"Can not allocate buffer\0"};
nctemp1700=&nctemp1701;
LibeErrstr=nctemp1700;
LibeErrno =(-113);
return (-1);
}
}
int nctemp1710=fp;
LibeFarr->a[nctemp1710].ptr =0;
int nctemp1716=fp;
int nctemp1721=fp;
int nctemp1719= LibeFarr->a[nctemp1721].fd;
int nctemp1725=fp;
int nctemp1723= LibeFarr->a[nctemp1725].bufsize;
int nctemp1729=fp;
nctempchar1* nctemp1727= LibeFarr->a[nctemp1729].base;
int nctemp1732=RunRead(nctemp1719,nctemp1723,nctemp1727);
LibeFarr->a[nctemp1716].cnt =nctemp1732;
int nctemp1736=fp;
int nctemp1733 = (LibeFarr->a[nctemp1736].cnt <= 0);
if(nctemp1733)
{
int nctemp1742=fp;
int nctemp1739 = (LibeFarr->a[nctemp1742].cnt ==(-1));
if(nctemp1739)
{
int nctemp1748=fp;
LibeFarr->a[nctemp1748].eoflg =1;
rval =(-1);
}
else{
int nctemp1758=fp;
LibeFarr->a[nctemp1758].errflg =1;
struct nctempchar1 *nctemp1766;
static struct nctempchar1 nctemp1767 = {{ 11}, (char*)"read error\0"};
nctemp1766=&nctemp1767;
LibeErrstr=nctemp1766;
LibeErrno =(-111);
rval =(-1);
}
int nctemp1779=fp;
LibeFarr->a[nctemp1779].cnt =0;
return rval;
}
int nctemp1786=fp;
int nctemp1792=fp;
int nctemp1795 = LibeFarr->a[nctemp1792].ptr + 1;
LibeFarr->a[nctemp1786].ptr =nctemp1795;
int nctemp1799=fp;
int nctemp1805=fp;
int nctemp1808 = LibeFarr->a[nctemp1805].cnt - 1;
LibeFarr->a[nctemp1799].cnt =nctemp1808;
int nctemp1813=fp;
int nctemp1819=fp;
int nctemp1822 = LibeFarr->a[nctemp1819].ptr - 1;
int nctemp1815=nctemp1822;
int nctemp1810=(int)(LibeFarr->a[nctemp1813].base->a[nctemp1815]);
return nctemp1810;
}
int LibeFlushbuff (int fp)
{
int st;
int size;
int nctemp1826=fp;
int nctemp1823 = (LibeFarr->a[nctemp1826].writflg !=1);
if(nctemp1823)
{
struct nctempchar1 *nctemp1834;
static struct nctempchar1 nctemp1835 = {{ 28}, (char*)"file not open for writing\n\0"};
nctemp1834=&nctemp1835;
LibeErrstr=nctemp1834;
LibeErrno =(-110);
return 0;
}
int nctemp1844=fp;
int nctemp1841 = (LibeFarr->a[nctemp1844].unbflg ==1);
if(nctemp1841)
{
int nctemp1850=fp;
LibeFarr->a[nctemp1850].bufsize =1;
}
else{
int nctemp1856=fp;
LibeFarr->a[nctemp1856].bufsize =1024;
}
int nctemp1862=fp;
nctempchar1 *nctemp1860 =LibeFarr->a[nctemp1862].base;
int nctemp1859 =(nctemp1860==0);
if(nctemp1859)
{
int nctemp1870=fp;
size =LibeFarr->a[nctemp1870].bufsize;
int nctemp1878=fp;
int nctemp1883=size;
nctempchar1 *nctemp1882;
nctemp1882=(nctempchar1*)RunMalloc(sizeof(nctempchar1));
nctemp1882->d[0]=size;
nctemp1882->a=(char *)RunMalloc(sizeof(char)*nctemp1883);
LibeFarr->a[nctemp1878].base=nctemp1882;
nctempchar1 *nctemp1873 =LibeFarr->a[nctemp1878].base;
int nctemp1872 =(nctemp1873==0);
if(nctemp1872)
{
struct nctempchar1 *nctemp1892;
static struct nctempchar1 nctemp1893 = {{ 24}, (char*)"can not allocate buffer\0"};
nctemp1892=&nctemp1893;
LibeErrstr=nctemp1892;
LibeErrno =(-113);
return 0;
}
}
int nctemp1902=fp;
LibeFarr->a[nctemp1902].ptr =0;
int nctemp1911=fp;
int nctemp1909= LibeFarr->a[nctemp1911].fd;
int nctemp1915=fp;
int nctemp1913= LibeFarr->a[nctemp1915].cnt;
int nctemp1919=fp;
nctempchar1* nctemp1917= LibeFarr->a[nctemp1919].base;
int nctemp1922=RunWrite(nctemp1909,nctemp1913,nctemp1917);
st =nctemp1922;
int nctemp1927=fp;
int nctemp1923 = (st !=LibeFarr->a[nctemp1927].cnt);
if(nctemp1923)
{
int nctemp1932=fp;
LibeFarr->a[nctemp1932].errflg =1;
struct nctempchar1 *nctemp1940;
static struct nctempchar1 nctemp1941 = {{ 12}, (char*)"write error\0"};
nctemp1940=&nctemp1941;
LibeErrstr=nctemp1940;
LibeErrno =(-112);
int nctemp1949=fp;
LibeFarr->a[nctemp1949].cnt =0;
int nctemp1955=fp;
LibeFarr->a[nctemp1955].ptr =0;
return 0;
}
else{
int nctemp1962=fp;
LibeFarr->a[nctemp1962].cnt =0;
int nctemp1968=fp;
LibeFarr->a[nctemp1968].ptr =0;
return 1;
}
}
int LibeStrlen (nctempchar1 *s)
{
int ls;
int i;
int nctemp1976=s->d[0];ls =nctemp1976;
i =0;
int nctemp1993=i;
int nctemp1990=(int)(s->a[nctemp1993]);
int nctemp1987 = (nctemp1990 !=0);
int nctemp1997 = (i < ls);
int nctemp1984 = (nctemp1987 && nctemp1997);
int nctemp2001=nctemp1984;
while(nctemp2001)
{{
int nctemp2010 = i + 1;
i =nctemp2010;
}
int nctemp2020=i;
int nctemp2017=(int)(s->a[nctemp2020]);
int nctemp2014 = (nctemp2017 !=0);
int nctemp2024 = (i < ls);
int nctemp2011 = (nctemp2014 && nctemp2024);
nctemp2001=nctemp2011;}return i;
}
int LibeStrcmp (nctempchar1 *s,nctempchar1 *t)
{
int ls;
int i;
int nctemp2033=s->d[0];ls =nctemp2033;
i =0;
int nctemp2047=i;
int nctemp2050=i;
int nctemp2044 = (s->a[nctemp2047] ==t->a[nctemp2050]);
int nctemp2053 = (i < ls);
int nctemp2041 = (nctemp2044 && nctemp2053);
int nctemp2057=nctemp2041;
while(nctemp2057)
{{
int nctemp2064=i;
int nctemp2061=(int)(s->a[nctemp2064]);
int nctemp2058 = (nctemp2061 ==0);
if(nctemp2058)
{
return 1;
}
int nctemp2076 = i + 1;
i =nctemp2076;
}
int nctemp2083=i;
int nctemp2086=i;
int nctemp2080 = (s->a[nctemp2083] ==t->a[nctemp2086]);
int nctemp2089 = (i < ls);
int nctemp2077 = (nctemp2080 && nctemp2089);
nctemp2057=nctemp2077;}return 0;
}
int LibeStrev (nctempchar1 *s)
{
char c;
int i;
int j;
i =0;
nctempchar1* nctemp2105= s;
int nctemp2108=LibeStrlen(nctemp2105);
int nctemp2110 = nctemp2108 - 1;
j =nctemp2110;
int nctemp2111 = (i < j);
int nctemp2115=nctemp2111;
while(nctemp2115)
{{
int nctemp2120=i;
c =s->a[nctemp2120];
int nctemp2125=i;
int nctemp2128=j;
s->a[nctemp2125] =s->a[nctemp2128];
int nctemp2133=j;
s->a[nctemp2133] =c;
int nctemp2144 = i + 1;
i =nctemp2144;
int nctemp2153 = j - 1;
j =nctemp2153;
}
int nctemp2154 = (i < j);
nctemp2115=nctemp2154;}return 1;
}
int LibeStrcpy (nctempchar1 *s,nctempchar1 *t)
{
int ls;
int i;
nctempchar1* nctemp2163= s;
int nctemp2166=LibeStrlen(nctemp2163);
ls =nctemp2166;
int nctemp2167 = (ls ==0);
if(nctemp2167)
{
return 1;
}
int nctemp2175=t->d[0];int nctemp2172 = (nctemp2175 <= ls);
if(nctemp2172)
{
return 0;
}
i =0;
int nctemp2185 = (i <= ls);
while(nctemp2185){
{
int nctemp2192=i;
int nctemp2195=i;
t->a[nctemp2192] =s->a[nctemp2195];
}
int nctemp2205 = i + 1;
i =nctemp2205;
int nctemp2206 = (i <= ls);
nctemp2185=nctemp2206;
}
return 1;
}
int LibeStrcat (nctempchar1 *s,nctempchar1 *t)
{
int ls;
int lt;
int i;
nctempchar1* nctemp2215= s;
int nctemp2218=LibeStrlen(nctemp2215);
ls =nctemp2218;
nctempchar1* nctemp2223= t;
int nctemp2226=LibeStrlen(nctemp2223);
lt =nctemp2226;
int nctemp2230=t->d[0];int nctemp2239 = lt + ls;
int nctemp2227 = (nctemp2230 < nctemp2239);
if(nctemp2227)
{
return 0;
}
i =lt;
int nctemp2253 = ls + lt;
int nctemp2245 = (i < nctemp2253);
while(nctemp2245){
{
int nctemp2257=i;
int nctemp2265 = i - lt;
int nctemp2260=nctemp2265;
t->a[nctemp2257] =s->a[nctemp2260];
}
int nctemp2274 = i + 1;
i =nctemp2274;
int nctemp2283 = ls + lt;
int nctemp2275 = (i < nctemp2283);
nctemp2245=nctemp2275;
}
int nctemp2292 = ls + lt;
int nctemp2287=nctemp2292;
char nctemp2294=(char)(0);
t->a[nctemp2287] =nctemp2294;
return 1;
}
nctempchar1 * LibeStradd (nctempchar1 *t,nctempchar1 *s)
{
int ls;
int lt;
nctempchar1 *r;
int i;
nctempchar1* nctemp2302= s;
int nctemp2305=LibeStrlen(nctemp2302);
ls =nctemp2305;
nctempchar1* nctemp2310= t;
int nctemp2313=LibeStrlen(nctemp2310);
lt =nctemp2313;
int nctemp2328 = lt + ls;
int nctemp2330 = nctemp2328 + 1;
int nctemp2320=nctemp2330;
nctempchar1 *nctemp2319;
nctemp2319=(nctempchar1*)RunMalloc(sizeof(nctempchar1));
int nctemp2338 = lt + ls;
int nctemp2340 = nctemp2338 + 1;
nctemp2319->d[0]=nctemp2340;
nctemp2319->a=(char *)RunMalloc(sizeof(char)*nctemp2320);
r=nctemp2319;
i =0;
int nctemp2345 = (i < lt);
while(nctemp2345){
{
int nctemp2352=i;
int nctemp2355=i;
r->a[nctemp2352] =t->a[nctemp2355];
}
int nctemp2365 = i + 1;
i =nctemp2365;
int nctemp2366 = (i < lt);
nctemp2345=nctemp2366;
}
i =lt;
int nctemp2382 = ls + lt;
int nctemp2374 = (i < nctemp2382);
while(nctemp2374){
{
int nctemp2386=i;
int nctemp2394 = i - lt;
int nctemp2389=nctemp2394;
r->a[nctemp2386] =s->a[nctemp2389];
}
int nctemp2403 = i + 1;
i =nctemp2403;
int nctemp2412 = ls + lt;
int nctemp2404 = (i < nctemp2412);
nctemp2374=nctemp2404;
}
int nctemp2421 = ls + lt;
int nctemp2416=nctemp2421;
char nctemp2423=(char)(0);
r->a[nctemp2416] =nctemp2423;
return r;
}
nctempchar1 * LibeStrsave (nctempchar1 *s)
{
int l;
nctempchar1 *tmp;
tmp=(0);
l =0;
nctempchar1* nctemp2441= s;
int nctemp2444=LibeStrlen(nctemp2441);
l =nctemp2444;
int nctemp2456 = l + 1;
int nctemp2451=nctemp2456;
nctempchar1 *nctemp2450;
nctemp2450=(nctempchar1*)RunMalloc(sizeof(nctempchar1));
int nctemp2461 = l + 1;
nctemp2450->d[0]=nctemp2461;
nctemp2450->a=(char *)RunMalloc(sizeof(char)*nctemp2451);
tmp=nctemp2450;
nctempchar1 *nctemp2463 =tmp;
int nctemp2462 =(nctemp2463!=0);
if(nctemp2462)
{
nctempchar1* nctemp2468= s;
nctempchar1* nctemp2471= tmp;
int nctemp2474=LibeStrcpy(nctemp2468,nctemp2471);
}
return tmp;
}
int LibeIsalpha (int c)
{
int nctemp2483 = (c >= 'a');
int nctemp2488 = (c <= 'z');
int nctemp2480 = (nctemp2483 && nctemp2488);
int nctemp2496 = (c >= 'A');
int nctemp2501 = (c <= 'Z');
int nctemp2493 = (nctemp2496 && nctemp2501);
int nctemp2477 = (nctemp2480 || nctemp2493);
if(nctemp2477)
{
return 1;
}
else{
return 0;
}
}
int LibeIsdigit (int c)
{
int nctemp2510 = (c >= '0');
int nctemp2515 = (c <= '9');
int nctemp2507 = (nctemp2510 && nctemp2515);
if(nctemp2507)
{
return 1;
}
else{
return 0;
}
}
int LibeIsalnum (int c)
{
int nctemp2527 = (c >= 'a');
int nctemp2532 = (c <= 'z');
int nctemp2524 = (nctemp2527 && nctemp2532);
int nctemp2540 = (c >= 'A');
int nctemp2545 = (c <= 'Z');
int nctemp2537 = (nctemp2540 && nctemp2545);
int nctemp2521 = (nctemp2524 || nctemp2537);
if(nctemp2521)
{
return 1;
}
else{
int nctemp2553 = (c >= '0');
int nctemp2558 = (c <= '9');
int nctemp2550 = (nctemp2553 && nctemp2558);
if(nctemp2550)
{
return 1;
}
else{
return 0;
}
}
}
int LibeFtoaf (int mant,int nexp,int nfield,int nfrac,nctempchar1 *s);
int LibeFtoae (int mant,int nexp,int nfield,int nfrac,nctempchar1 *s);
int LibeAtoi (nctempchar1 *s)
{
int sign;
int i;
int n;
i =0;
int nctemp2577=i;
char nctemp2580=(char)(' ');
int nctemp2574 = (s->a[nctemp2577] ==nctemp2580);
int nctemp2587=i;
char nctemp2590=(char)(10);
int nctemp2584 = (s->a[nctemp2587] ==nctemp2590);
int nctemp2571 = (nctemp2574 || nctemp2584);
int nctemp2597=i;
char nctemp2600=(char)(9);
int nctemp2594 = (s->a[nctemp2597] ==nctemp2600);
int nctemp2568 = (nctemp2571 || nctemp2594);
int nctemp2603=nctemp2568;
while(nctemp2603)
{{
int nctemp2612 = i + 1;
i =nctemp2612;
}
int nctemp2622=i;
char nctemp2625=(char)(' ');
int nctemp2619 = (s->a[nctemp2622] ==nctemp2625);
int nctemp2632=i;
char nctemp2635=(char)(10);
int nctemp2629 = (s->a[nctemp2632] ==nctemp2635);
int nctemp2616 = (nctemp2619 || nctemp2629);
int nctemp2642=i;
char nctemp2645=(char)(9);
int nctemp2639 = (s->a[nctemp2642] ==nctemp2645);
int nctemp2613 = (nctemp2616 || nctemp2639);
nctemp2603=nctemp2613;}int nctemp2651=i;
char nctemp2654=(char)('-');
int nctemp2648 = (s->a[nctemp2651] ==nctemp2654);
if(nctemp2648)
{
int nctemp2660= -1;
sign =nctemp2660;
int nctemp2669 = i + 1;
i =nctemp2669;
}
else{
int nctemp2673=i;
char nctemp2676=(char)('+');
int nctemp2670 = (s->a[nctemp2673] ==nctemp2676);
if(nctemp2670)
{
sign =1;
int nctemp2691 = i + 1;
i =nctemp2691;
}
else{
sign =1;
}
}
n =0;
int nctemp2706=i;
int nctemp2703=(int)(s->a[nctemp2706]);
int nctemp2701= nctemp2703;
int nctemp2708=LibeIsdigit(nctemp2701);
while(nctemp2708){
{
int nctemp2723 = 10 * n;
int nctemp2728=i;
int nctemp2725=(int)(s->a[nctemp2728]);
int nctemp2730 = nctemp2723 + nctemp2725;
int nctemp2732 = nctemp2730 - '0';
n =nctemp2732;
}
int nctemp2741 = i + 1;
i =nctemp2741;
int nctemp2748=i;
int nctemp2745=(int)(s->a[nctemp2748]);
int nctemp2743= nctemp2745;
int nctemp2750=LibeIsdigit(nctemp2743);
nctemp2708=nctemp2750;
}
int nctemp2755 = sign * n;
return nctemp2755;
}
int LibeItoa (int n,nctempchar1 *s)
{
int sign;
int i;
nctempchar1 *nctemp2757 =s;
int nctemp2756 =(nctemp2757==0);
if(nctemp2756)
{
return 0;
}
sign =n;
int nctemp2762 = (sign < 0);
if(nctemp2762)
{
int nctemp2773= -n;
n =nctemp2773;
}
i =0;
int nctemp2781=0;
int nctemp2789= n;
int nctemp2791= 10;
int nctemp2793=LibeMod(nctemp2789,nctemp2791);
int nctemp2795 = nctemp2793 + 48;
char nctemp2784=(char)(nctemp2795);
s->a[nctemp2781] =nctemp2784;
int nctemp2807 = n / 10;
n =nctemp2807;
int nctemp2796 = (n > 0);
int nctemp2809=nctemp2796;
while(nctemp2809)
{{
int nctemp2817 = i + 1;
int nctemp2822=s->d[0];int nctemp2827 = nctemp2822 - 1;
int nctemp2810 = (nctemp2817 > nctemp2827);
if(nctemp2810)
{
return 0;
}
int nctemp2841 = i + 1;
i =nctemp2841;
int nctemp2832=i;
int nctemp2848= n;
int nctemp2850= 10;
int nctemp2852=LibeMod(nctemp2848,nctemp2850);
int nctemp2854 = nctemp2852 + 48;
char nctemp2843=(char)(nctemp2854);
s->a[nctemp2832] =nctemp2843;
}
int nctemp2866 = n / 10;
n =nctemp2866;
int nctemp2855 = (n > 0);
nctemp2809=nctemp2855;}int nctemp2868 = (sign < 0);
if(nctemp2868)
{
int nctemp2879 = i + 1;
int nctemp2884=s->d[0];int nctemp2889 = nctemp2884 - 1;
int nctemp2872 = (nctemp2879 > nctemp2889);
if(nctemp2872)
{
return 0;
}
int nctemp2903 = i + 1;
i =nctemp2903;
int nctemp2894=i;
char nctemp2905=(char)(45);
s->a[nctemp2894] =nctemp2905;
}
int nctemp2915 = i + 1;
int nctemp2920=s->d[0];int nctemp2925 = nctemp2920 - 1;
int nctemp2908 = (nctemp2915 > nctemp2925);
if(nctemp2908)
{
return 0;
}
int nctemp2939 = i + 1;
i =nctemp2939;
int nctemp2930=i;
char nctemp2941=(char)(0);
s->a[nctemp2930] =nctemp2941;
nctempchar1* nctemp2945= s;
int nctemp2948=LibeStrev(nctemp2945);
return 1;
}
int LibeItoh (int n,nctempchar1 *s)
{
int i;
int sign;
sign =n;
int nctemp2950 = (sign < 0);
if(nctemp2950)
{
int nctemp2961= -n;
n =nctemp2961;
}
i =0;
int nctemp2969= n;
int nctemp2971= 16;
int nctemp2973=LibeMod(nctemp2969,nctemp2971);
int nctemp2966 = (nctemp2973 <= 9);
if(nctemp2966)
{
int nctemp2978=0;
int nctemp2986= n;
int nctemp2988= 16;
int nctemp2990=LibeMod(nctemp2986,nctemp2988);
int nctemp2992 = nctemp2990 + 48;
char nctemp2981=(char)(nctemp2992);
s->a[nctemp2978] =nctemp2981;
}
else{
int nctemp2996=0;
int nctemp3007= n;
int nctemp3009= 16;
int nctemp3011=LibeMod(nctemp3007,nctemp3009);
int nctemp3013 = nctemp3011 + 'a';
int nctemp3015 = nctemp3013 - 10;
char nctemp2999=(char)(nctemp3015);
s->a[nctemp2996] =nctemp2999;
}
int nctemp3027 = n / 16;
n =nctemp3027;
int nctemp3016 = (n > 0);
int nctemp3029=nctemp3016;
while(nctemp3029)
{{
int nctemp3033= n;
int nctemp3035= 16;
int nctemp3037=LibeMod(nctemp3033,nctemp3035);
int nctemp3030 = (nctemp3037 <= 9);
if(nctemp3030)
{
int nctemp3051 = i + 1;
i =nctemp3051;
int nctemp3042=i;
int nctemp3058= n;
int nctemp3060= 16;
int nctemp3062=LibeMod(nctemp3058,nctemp3060);
int nctemp3064 = nctemp3062 + 48;
char nctemp3053=(char)(nctemp3064);
s->a[nctemp3042] =nctemp3053;
}
else{
int nctemp3077 = i + 1;
i =nctemp3077;
int nctemp3068=i;
int nctemp3087= n;
int nctemp3089= 16;
int nctemp3091=LibeMod(nctemp3087,nctemp3089);
int nctemp3093 = nctemp3091 + 'a';
int nctemp3095 = nctemp3093 - 10;
char nctemp3079=(char)(nctemp3095);
s->a[nctemp3068] =nctemp3079;
}
}
int nctemp3107 = n / 16;
n =nctemp3107;
int nctemp3096 = (n > 0);
nctemp3029=nctemp3096;}int nctemp3109 = (sign < 0);
if(nctemp3109)
{
int nctemp3125 = i + 1;
i =nctemp3125;
int nctemp3116=i;
char nctemp3127=(char)(45);
s->a[nctemp3116] =nctemp3127;
}
int nctemp3142 = i + 1;
i =nctemp3142;
int nctemp3133=i;
char nctemp3144=(char)(0);
s->a[nctemp3133] =nctemp3144;
nctempchar1* nctemp3148= s;
int nctemp3151=LibeStrev(nctemp3148);
return 0;
}
float LibeAtof (nctempchar1 *s)
{
float val;
float power;
int exponent;
int sign;
int esign;
int i;
sign =1;
val =0.0;
power =1.0;
exponent =0;
esign =1;
i =0;
int nctemp3180=i;
char nctemp3183=(char)(' ');
int nctemp3177 = (s->a[nctemp3180] ==nctemp3183);
int nctemp3186=nctemp3177;
while(nctemp3186)
{{
int nctemp3195 = i + 1;
i =nctemp3195;
}
int nctemp3199=i;
char nctemp3202=(char)(' ');
int nctemp3196 = (s->a[nctemp3199] ==nctemp3202);
nctemp3186=nctemp3196;}int nctemp3211=i;
char nctemp3214=(char)('+');
int nctemp3208 = (s->a[nctemp3211] ==nctemp3214);
int nctemp3221=i;
char nctemp3224=(char)('-');
int nctemp3218 = (s->a[nctemp3221] ==nctemp3224);
int nctemp3205 = (nctemp3208 || nctemp3218);
if(nctemp3205)
{
int nctemp3230=i;
char nctemp3233=(char)('-');
int nctemp3227 = (s->a[nctemp3230] ==nctemp3233);
if(nctemp3227)
{
int nctemp3239= -1;
sign =nctemp3239;
}
int nctemp3248 = i + 1;
i =nctemp3248;
}
int nctemp3255=i;
int nctemp3252=(int)(s->a[nctemp3255]);
int nctemp3250= nctemp3252;
int nctemp3257=LibeIsdigit(nctemp3250);
int nctemp3258=nctemp3257;
while(nctemp3258)
{{
float nctemp3270 = 10.0 * val;
int nctemp3280=i;
int nctemp3277=(int)(s->a[nctemp3280]);
int nctemp3283 = nctemp3277 - '0';
float nctemp3272=(float)(nctemp3283);
float nctemp3284 = nctemp3270 + nctemp3272;
val =nctemp3284;
int nctemp3293 = i + 1;
i =nctemp3293;
}
int nctemp3300=i;
int nctemp3297=(int)(s->a[nctemp3300]);
int nctemp3295= nctemp3297;
int nctemp3302=LibeIsdigit(nctemp3295);
nctemp3258=nctemp3302;}int nctemp3306=i;
char nctemp3309=(char)('.');
int nctemp3303 = (s->a[nctemp3306] ==nctemp3309);
if(nctemp3303)
{
int nctemp3320 = i + 1;
i =nctemp3320;
int nctemp3327=i;
int nctemp3324=(int)(s->a[nctemp3327]);
int nctemp3322= nctemp3324;
int nctemp3329=LibeIsdigit(nctemp3322);
int nctemp3330=nctemp3329;
while(nctemp3330)
{{
float nctemp3342 = 10.0 * val;
int nctemp3352=i;
int nctemp3349=(int)(s->a[nctemp3352]);
int nctemp3355 = nctemp3349 - '0';
float nctemp3344=(float)(nctemp3355);
float nctemp3356 = nctemp3342 + nctemp3344;
val =nctemp3356;
int nctemp3365 = i + 1;
i =nctemp3365;
float nctemp3374 = 10.0 * power;
power =nctemp3374;
}
int nctemp3381=i;
int nctemp3378=(int)(s->a[nctemp3381]);
int nctemp3376= nctemp3378;
int nctemp3383=LibeIsdigit(nctemp3376);
nctemp3330=nctemp3383;}}
int nctemp3390=i;
char nctemp3393=(char)('e');
int nctemp3387 = (s->a[nctemp3390] ==nctemp3393);
int nctemp3400=i;
char nctemp3403=(char)('E');
int nctemp3397 = (s->a[nctemp3400] ==nctemp3403);
int nctemp3384 = (nctemp3387 || nctemp3397);
if(nctemp3384)
{
int nctemp3414 = i + 1;
i =nctemp3414;
int nctemp3421=i;
char nctemp3424=(char)('+');
int nctemp3418 = (s->a[nctemp3421] ==nctemp3424);
int nctemp3431=i;
char nctemp3434=(char)('-');
int nctemp3428 = (s->a[nctemp3431] ==nctemp3434);
int nctemp3415 = (nctemp3418 || nctemp3428);
if(nctemp3415)
{
int nctemp3440=i;
char nctemp3443=(char)('-');
int nctemp3437 = (s->a[nctemp3440] ==nctemp3443);
if(nctemp3437)
{
int nctemp3449= -1;
esign =nctemp3449;
}
int nctemp3458 = i + 1;
i =nctemp3458;
}
int nctemp3465=i;
int nctemp3462=(int)(s->a[nctemp3465]);
int nctemp3460= nctemp3462;
int nctemp3467=LibeIsdigit(nctemp3460);
int nctemp3468=nctemp3467;
while(nctemp3468)
{{
int nctemp3483 = 10 * exponent;
int nctemp3488=i;
int nctemp3485=(int)(s->a[nctemp3488]);
int nctemp3490 = nctemp3483 + nctemp3485;
int nctemp3492 = nctemp3490 - '0';
exponent =nctemp3492;
int nctemp3501 = i + 1;
i =nctemp3501;
}
int nctemp3508=i;
int nctemp3505=(int)(s->a[nctemp3508]);
int nctemp3503= nctemp3505;
int nctemp3510=LibeIsdigit(nctemp3503);
nctemp3468=nctemp3510;}}
float nctemp3519=(float)(sign);
float nctemp3523 = nctemp3519 * val;
float nctemp3525=(float)(power);
float nctemp3528 = nctemp3523 / nctemp3525;
float nctemp3512= nctemp3528;
int nctemp3534 = esign * exponent;
int nctemp3529= nctemp3534;
float nctemp3535=LibeFscale(nctemp3512,nctemp3529);
return nctemp3535;
}
int LibeFtoa (float f,nctempchar1 *fmt,nctempchar1 *s)
{
int nexp;
int mant;
int c;
int p;
int q;
int l;
int mode;
int ndigit;
int nfield;
int nfrac;
int nctemp3539=s->d[0];int nctemp3544=fmt->d[0];int nctemp3536 = (nctemp3539 < nctemp3544);
if(nctemp3536)
{
return 0;
}
int nctemp3556=fmt->d[0];int nctemp3561 = nctemp3556 - 2;
l =nctemp3561;
p =0;
q =0;
int nctemp3577=p;
int nctemp3574=(int)(fmt->a[nctemp3577]);
c =nctemp3574;
int nctemp3579 = (c =='g');
if(nctemp3579)
{
mode ='g';
}
else{
int nctemp3590= c;
int nctemp3592=LibeIsdigit(nctemp3590);
int nctemp3587 = (nctemp3592 ==1);
if(nctemp3587)
{
int nctemp3597= c;
int nctemp3599=LibeIsdigit(nctemp3597);
int nctemp3594 = (nctemp3599 ==1);
int nctemp3601=nctemp3594;
while(nctemp3601)
{{
int nctemp3605=q;
int nctemp3608=p;
s->a[nctemp3605] =fmt->a[nctemp3608];
int nctemp3621 = p + 1;
p =nctemp3621;
int nctemp3610 = (p > l);
if(nctemp3610)
{
return 0;
}
int nctemp3632 = q + 1;
q =nctemp3632;
int nctemp3640=p;
int nctemp3637=(int)(fmt->a[nctemp3640]);
c =nctemp3637;
}
int nctemp3645= c;
int nctemp3647=LibeIsdigit(nctemp3645);
int nctemp3642 = (nctemp3647 ==1);
nctemp3601=nctemp3642;}int nctemp3652=q;
char nctemp3655=(char)(0);
s->a[nctemp3652] =nctemp3655;
nctempchar1* nctemp3662= s;
int nctemp3665=LibeAtoi(nctemp3662);
nfield =nctemp3665;
}
else{
return 0;
}
int nctemp3667 = (c !='.');
if(nctemp3667)
{
return 0;
}
int nctemp3683 = p + 1;
p =nctemp3683;
int nctemp3672 = (p > l);
if(nctemp3672)
{
return 0;
}
int nctemp3693=p;
int nctemp3690=(int)(fmt->a[nctemp3693]);
c =nctemp3690;
q =0;
int nctemp3702= c;
int nctemp3704=LibeIsdigit(nctemp3702);
int nctemp3699 = (nctemp3704 ==1);
if(nctemp3699)
{
int nctemp3709= c;
int nctemp3711=LibeIsdigit(nctemp3709);
int nctemp3706 = (nctemp3711 ==1);
int nctemp3713=nctemp3706;
while(nctemp3713)
{{
int nctemp3717=q;
int nctemp3720=p;
s->a[nctemp3717] =fmt->a[nctemp3720];
int nctemp3733 = p + 1;
p =nctemp3733;
int nctemp3722 = (p > l);
if(nctemp3722)
{
return 0;
}
int nctemp3744 = q + 1;
q =nctemp3744;
int nctemp3752=p;
int nctemp3749=(int)(fmt->a[nctemp3752]);
c =nctemp3749;
}
int nctemp3757= c;
int nctemp3759=LibeIsdigit(nctemp3757);
int nctemp3754 = (nctemp3759 ==1);
nctemp3713=nctemp3754;}int nctemp3764=q;
char nctemp3767=(char)(0);
s->a[nctemp3764] =nctemp3767;
nctempchar1* nctemp3774= s;
int nctemp3777=LibeAtoi(nctemp3774);
nfrac =nctemp3777;
}
else{
return 0;
}
int nctemp3779 = (c =='f');
if(nctemp3779)
{
mode ='f';
}
else{
int nctemp3787 = (c =='e');
if(nctemp3787)
{
mode ='e';
}
else{
return 0;
}
}
}
int nctemp3796 = (mode =='g');
if(nctemp3796)
{
float nctemp3804= f;
int nctemp3806=LibeGetmaxdig(nctemp3804);
nfrac =nctemp3806;
int nctemp3833 = 1 + 1;
int nctemp3835 = nctemp3833 + 1;
int nctemp3837 = nctemp3835 + 1;
int nctemp3839 = nctemp3837 + nfrac;
int nctemp3841 = nctemp3839 + 1;
int nctemp3843 = nctemp3841 + 1;
int nctemp3845 = nctemp3843 + 2;
nfield =nctemp3845;
int nctemp3854 = nfrac + 1;
ndigit =nctemp3854;
float nctemp3859= f;
int nctemp3861= ndigit;
int nctemp3863=LibeGetfman(nctemp3859,nctemp3861);
mant =nctemp3863;
float nctemp3868= f;
int nctemp3870=LibeGetfexp(nctemp3868);
nexp =nctemp3870;
int nctemp3872= mant;
int nctemp3874= nexp;
int nctemp3876= nfield;
int nctemp3878= nfrac;
nctempchar1* nctemp3880= s;
int nctemp3883=LibeFtoae(nctemp3872,nctemp3874,nctemp3876,nctemp3878,nctemp3880);
}
else{
int nctemp3884 = (mode =='e');
if(nctemp3884)
{
int nctemp3896 = nfrac + 1;
ndigit =nctemp3896;
float nctemp3901= f;
int nctemp3903= ndigit;
int nctemp3905=LibeGetfman(nctemp3901,nctemp3903);
mant =nctemp3905;
float nctemp3910= f;
int nctemp3912=LibeGetfexp(nctemp3910);
nexp =nctemp3912;
int nctemp3914= mant;
int nctemp3916= nexp;
int nctemp3918= nfield;
int nctemp3920= nfrac;
nctempchar1* nctemp3922= s;
int nctemp3925=LibeFtoae(nctemp3914,nctemp3916,nctemp3918,nctemp3920,nctemp3922);
}
else{
int nctemp3926 = (mode =='f');
if(nctemp3926)
{
float nctemp3934= f;
int nctemp3936=LibeGetfexp(nctemp3934);
nexp =nctemp3936;
int nctemp3948 = nexp + nfrac;
int nctemp3950 = nctemp3948 + 1;
ndigit =nctemp3950;
float nctemp3955= f;
int nctemp3957= ndigit;
int nctemp3959=LibeGetfman(nctemp3955,nctemp3957);
mant =nctemp3959;
int nctemp3961= mant;
int nctemp3963= nexp;
int nctemp3965= nfield;
int nctemp3967= nfrac;
nctempchar1* nctemp3969= s;
int nctemp3972=LibeFtoaf(nctemp3961,nctemp3963,nctemp3965,nctemp3967,nctemp3969);
}
}
}
return 1;
}
int LibeFtoae (int mant,int nexp,int nfield,int nfrac,nctempchar1 *s)
{
int tp;
int sign;
int i;
int l;
nctempchar1 *t;
int nctemp3974 = (mant < 0);
if(nctemp3974)
{
int nctemp3981= -mant;
mant =nctemp3981;
int nctemp3985= -1;
sign =nctemp3985;
}
else{
sign =1;
}
int nctemp3993=s->d[0];int nctemp4020 = 1 + 1;
int nctemp4022 = nctemp4020 + 1;
int nctemp4024 = nctemp4022 + nfrac;
int nctemp4026 = nctemp4024 + 1;
int nctemp4028 = nctemp4026 + 1;
int nctemp4030 = nctemp4028 + 2;
int nctemp4032 = nctemp4030 + 1;
int nctemp3990 = (nctemp3993 < nctemp4032);
if(nctemp3990)
{
return 0;
}
int nctemp4042=s->d[0];int nctemp4040=nctemp4042;
nctempchar1 *nctemp4039;
nctemp4039=(nctempchar1*)RunMalloc(sizeof(nctempchar1));
int nctemp4047=s->d[0];nctemp4039->d[0]=nctemp4047;
nctemp4039->a=(char *)RunMalloc(sizeof(char)*nctemp4040);
t=nctemp4039;
int nctemp4074 = 1 + 1;
int nctemp4076 = nctemp4074 + nfrac;
int nctemp4078 = nctemp4076 + 1;
int nctemp4080 = nctemp4078 + 1;
int nctemp4082 = nctemp4080 + 2;
int nctemp4084 = nctemp4082 + 1;
l =nctemp4084;
int nctemp4085 = (sign < 0);
if(nctemp4085)
{
int nctemp4097 = l + 1;
l =nctemp4097;
}
int nctemp4098 = (nfield < l);
if(nctemp4098)
{
i =0;
int nctemp4106 = (i < nfield);
while(nctemp4106){
{
int nctemp4113=i;
char nctemp4116=(char)('*');
s->a[nctemp4113] =nctemp4116;
}
int nctemp4127 = i + 1;
i =nctemp4127;
int nctemp4128 = (i < nfield);
nctemp4106=nctemp4128;
}
int nctemp4135=nfield;
char nctemp4138=(char)(0);
s->a[nctemp4135] =nctemp4138;
return 0;
}
else{
int nctemp4150 = nfield - l;
tp =nctemp4150;
}
i =0;
int nctemp4155 = (i < tp);
while(nctemp4155){
{
int nctemp4162=i;
char nctemp4165=(char)(' ');
s->a[nctemp4162] =nctemp4165;
}
int nctemp4176 = i + 1;
i =nctemp4176;
int nctemp4177 = (i < tp);
nctemp4155=nctemp4177;
}
int nctemp4182= mant;
nctempchar1* nctemp4184= t;
int nctemp4187=LibeItoa(nctemp4182,nctemp4184);
int nctemp4188 = (sign < 0);
if(nctemp4188)
{
int nctemp4195=tp;
char nctemp4198=(char)('-');
s->a[nctemp4195] =nctemp4198;
int nctemp4209 = tp + 1;
tp =nctemp4209;
}
int nctemp4213=tp;
int nctemp4216=0;
s->a[nctemp4213] =t->a[nctemp4216];
int nctemp4226 = tp + 1;
int nctemp4221=nctemp4226;
char nctemp4228=(char)('.');
s->a[nctemp4221] =nctemp4228;
i =0;
int nctemp4235 = (i < nfrac);
while(nctemp4235){
{
int nctemp4250 = tp + 2;
int nctemp4252 = nctemp4250 + i;
int nctemp4242=nctemp4252;
int nctemp4259 = i + 1;
int nctemp4254=nctemp4259;
s->a[nctemp4242] =t->a[nctemp4254];
}
int nctemp4268 = i + 1;
i =nctemp4268;
int nctemp4269 = (i < nfrac);
nctemp4235=nctemp4269;
}
int nctemp4284 = tp + 2;
int nctemp4286 = nctemp4284 + nfrac;
int nctemp4276=nctemp4286;
char nctemp4288=(char)(0);
s->a[nctemp4276] =nctemp4288;
sign =1;
int nctemp4295 = (nexp < 0);
if(nctemp4295)
{
int nctemp4302= -1;
sign =nctemp4302;
int nctemp4306= -nexp;
nexp =nctemp4306;
}
struct nctempchar1 *nctemp4310;
static struct nctempchar1 nctemp4311 = {{ 2}, (char*)"e\0"};
nctemp4310=&nctemp4311;
nctempchar1* nctemp4308= nctemp4310;
nctempchar1* nctemp4312= s;
int nctemp4315=LibeStrcat(nctemp4308,nctemp4312);
int nctemp4316 = (sign > 0);
if(nctemp4316)
{
struct nctempchar1 *nctemp4323;
static struct nctempchar1 nctemp4324 = {{ 2}, (char*)"+\0"};
nctemp4323=&nctemp4324;
nctempchar1* nctemp4321= nctemp4323;
nctempchar1* nctemp4325= s;
int nctemp4328=LibeStrcat(nctemp4321,nctemp4325);
}
else{
struct nctempchar1 *nctemp4332;
static struct nctempchar1 nctemp4333 = {{ 2}, (char*)"-\0"};
nctemp4332=&nctemp4333;
nctempchar1* nctemp4330= nctemp4332;
nctempchar1* nctemp4334= s;
int nctemp4337=LibeStrcat(nctemp4330,nctemp4334);
}
int nctemp4339= nexp;
nctempchar1* nctemp4341= t;
int nctemp4344=LibeItoa(nctemp4339,nctemp4341);
nctempchar1* nctemp4348= t;
int nctemp4351=LibeStrlen(nctemp4348);
int nctemp4345 = (nctemp4351 ==1);
if(nctemp4345)
{
struct nctempchar1 *nctemp4356;
static struct nctempchar1 nctemp4357 = {{ 2}, (char*)"0\0"};
nctemp4356=&nctemp4357;
nctempchar1* nctemp4354= nctemp4356;
nctempchar1* nctemp4358= s;
int nctemp4361=LibeStrcat(nctemp4354,nctemp4358);
}
nctempchar1* nctemp4363= t;
nctempchar1* nctemp4366= s;
int nctemp4369=LibeStrcat(nctemp4363,nctemp4366);
RunFree(t->a);
RunFree(t);
return 1;
}
int LibeFtoaf (int mant,int nexp,int nfield,int nfrac,nctempchar1 *s)
{
nctempchar1 *t;
int sign;
int i;
int tp;
int l;
int nctemp4374 = (mant < 0);
if(nctemp4374)
{
int nctemp4381= -1;
sign =nctemp4381;
int nctemp4385= -mant;
mant =nctemp4385;
}
else{
sign =1;
}
int nctemp4393=s->d[0];int nctemp4402 = nfield + 1;
int nctemp4390 = (nctemp4393 < nctemp4402);
if(nctemp4390)
{
return 0;
}
int nctemp4418 = nexp + 1;
int nctemp4420 = nctemp4418 + 1;
int nctemp4422 = nctemp4420 + nfrac;
l =nctemp4422;
int nctemp4423 = (sign < 0);
if(nctemp4423)
{
int nctemp4435 = l + 1;
l =nctemp4435;
}
int nctemp4436 = (nfield < l);
if(nctemp4436)
{
i =0;
int nctemp4444 = (i < nfield);
while(nctemp4444){
{
int nctemp4451=i;
char nctemp4454=(char)('*');
s->a[nctemp4451] =nctemp4454;
}
int nctemp4465 = i + 1;
i =nctemp4465;
int nctemp4466 = (i < nfield);
nctemp4444=nctemp4466;
}
int nctemp4473=nfield;
char nctemp4476=(char)(0);
s->a[nctemp4473] =nctemp4476;
return 0;
}
else{
int nctemp4488 = nfield - l;
tp =nctemp4488;
}
int nctemp4500 = 6 + 1;
int nctemp4495=nctemp4500;
nctempchar1 *nctemp4494;
nctemp4494=(nctempchar1*)RunMalloc(sizeof(nctempchar1));
int nctemp4505 = 6 + 1;
nctemp4494->d[0]=nctemp4505;
nctemp4494->a=(char *)RunMalloc(sizeof(char)*nctemp4495);
t=nctemp4494;
int nctemp4507= mant;
nctempchar1* nctemp4509= t;
int nctemp4512=LibeItoa(nctemp4507,nctemp4509);
i =0;
int nctemp4517 = (i < tp);
while(nctemp4517){
{
int nctemp4524=i;
char nctemp4527=(char)(' ');
s->a[nctemp4524] =nctemp4527;
}
int nctemp4538 = i + 1;
i =nctemp4538;
int nctemp4539 = (i < tp);
nctemp4517=nctemp4539;
}
int nctemp4543 = (nexp >= 0);
if(nctemp4543)
{
int nctemp4550= -1;
int nctemp4547 = (sign ==nctemp4550);
if(nctemp4547)
{
int nctemp4554=tp;
char nctemp4557=(char)('-');
s->a[nctemp4554] =nctemp4557;
int nctemp4568 = tp + 1;
tp =nctemp4568;
}
i =0;
int nctemp4573 = (i <= nexp);
while(nctemp4573){
{
int nctemp4585 = i + tp;
int nctemp4580=nctemp4585;
int nctemp4587=i;
s->a[nctemp4580] =t->a[nctemp4587];
}
int nctemp4597 = i + 1;
i =nctemp4597;
int nctemp4598 = (i <= nexp);
nctemp4573=nctemp4598;
}
int nctemp4602 = (nfrac > 0);
if(nctemp4602)
{
int nctemp4617 = tp + nexp;
int nctemp4619 = nctemp4617 + 1;
int nctemp4609=nctemp4619;
char nctemp4621=(char)('.');
s->a[nctemp4609] =nctemp4621;
}
i =0;
int nctemp4628 = (i < nfrac);
while(nctemp4628){
{
int nctemp4632 = (mant ==0);
if(nctemp4632)
{
int nctemp4653 = tp + nexp;
int nctemp4655 = nctemp4653 + 1;
int nctemp4657 = nctemp4655 + 1;
int nctemp4659 = nctemp4657 + i;
int nctemp4639=nctemp4659;
char nctemp4661=(char)('0');
s->a[nctemp4639] =nctemp4661;
}
else{
int nctemp4681 = tp + nexp;
int nctemp4683 = nctemp4681 + 1;
int nctemp4685 = nctemp4683 + 1;
int nctemp4687 = nctemp4685 + i;
int nctemp4667=nctemp4687;
int nctemp4697 = nexp + 1;
int nctemp4699 = nctemp4697 + i;
int nctemp4689=nctemp4699;
s->a[nctemp4667] =t->a[nctemp4689];
}
}
int nctemp4708 = i + 1;
i =nctemp4708;
int nctemp4709 = (i < nfrac);
nctemp4628=nctemp4709;
}
int nctemp4713 = (nfrac > 0);
if(nctemp4713)
{
int nctemp4734 = tp + nexp;
int nctemp4736 = nctemp4734 + 1;
int nctemp4738 = nctemp4736 + 1;
int nctemp4740 = nctemp4738 + nfrac;
int nctemp4720=nctemp4740;
char nctemp4742=(char)(0);
s->a[nctemp4720] =nctemp4742;
}
else{
int nctemp4756 = tp + nexp;
int nctemp4758 = nctemp4756 + 1;
int nctemp4748=nctemp4758;
char nctemp4760=(char)(0);
s->a[nctemp4748] =nctemp4760;
}
}
else{
int nctemp4766= -nexp;
nexp =nctemp4766;
int nctemp4770= -1;
int nctemp4767 = (sign ==nctemp4770);
if(nctemp4767)
{
int nctemp4774=tp;
char nctemp4777=(char)('-');
s->a[nctemp4774] =nctemp4777;
int nctemp4788 = tp + 1;
tp =nctemp4788;
}
int nctemp4792=tp;
char nctemp4795=(char)('0');
s->a[nctemp4792] =nctemp4795;
int nctemp4806 = tp + 1;
int nctemp4801=nctemp4806;
char nctemp4808=(char)('.');
s->a[nctemp4801] =nctemp4808;
i =0;
int nctemp4823 = nexp - 1;
int nctemp4815 = (i < nctemp4823);
while(nctemp4815){
{
int nctemp4835 = i + tp;
int nctemp4837 = nctemp4835 + 2;
int nctemp4827=nctemp4837;
char nctemp4839=(char)('0');
s->a[nctemp4827] =nctemp4839;
}
int nctemp4850 = i + 1;
i =nctemp4850;
int nctemp4859 = nexp - 1;
int nctemp4851 = (i < nctemp4859);
nctemp4815=nctemp4851;
}
i =0;
int nctemp4875 = nfrac - nexp;
int nctemp4877 = nctemp4875 + 1;
int nctemp4864 = (i < nctemp4877);
while(nctemp4864){
{
int nctemp4895 = tp + 2;
int nctemp4897 = nctemp4895 + i;
int nctemp4899 = nctemp4897 + nexp;
int nctemp4901 = nctemp4899 - 1;
int nctemp4881=nctemp4901;
int nctemp4903=i;
s->a[nctemp4881] =t->a[nctemp4903];
}
int nctemp4913 = i + 1;
i =nctemp4913;
int nctemp4925 = nfrac - nexp;
int nctemp4927 = nctemp4925 + 1;
int nctemp4914 = (i < nctemp4927);
nctemp4864=nctemp4914;
}
int nctemp4939 = tp + 2;
int nctemp4941 = nctemp4939 + nfrac;
int nctemp4931=nctemp4941;
char nctemp4943=(char)(0);
s->a[nctemp4931] =nctemp4943;
}
return 1;
}
float LibeMach (int flag)
{
int nctemp4947 = (flag ==1);
if(nctemp4947)
{
return 1.1754943508222875e-38;
}
else{
int nctemp4952 = (flag ==2);
if(nctemp4952)
{
return 3.4028234663852886e+38;
}
else{
int nctemp4957 = (flag ==3);
if(nctemp4957)
{
return 5.9604644775390625e-08;
}
else{
int nctemp4962 = (flag ==4);
if(nctemp4962)
{
return 1.1920928955078125e-07;
}
else{
int nctemp4967 = (flag ==5);
if(nctemp4967)
{
return 0.6931471805599453;
}
else{
float nctemp4973=(float)(0);
return nctemp4973;
}
}
}
}
}
}
float LibeFabs (float x)
{
int nctemp4976 = (x < 0.0);
if(nctemp4976)
{
float nctemp4980= -x;
return nctemp4980;
}
else{
return x;
}
}
float LibeFscale2 (float x,int n)
{
int i;
float rval;
int nctemp4982 = (n ==0);
if(nctemp4982)
{
return x;
}
rval =1.0;
int nctemp4991 = (n > 0);
if(nctemp4991)
{
i =0;
int nctemp4999 = (i < n);
while(nctemp4999){
{
float nctemp5011 = rval * 2.0;
rval =nctemp5011;
}
int nctemp5020 = i + 1;
i =nctemp5020;
int nctemp5021 = (i < n);
nctemp4999=nctemp5021;
}
}
else{
int nctemp5028= -n;
n =nctemp5028;
i =0;
int nctemp5033 = (i < n);
while(nctemp5033){
{
float nctemp5045 = rval * 0.5;
rval =nctemp5045;
}
int nctemp5054 = i + 1;
i =nctemp5054;
int nctemp5055 = (i < n);
nctemp5033=nctemp5055;
}
}
float nctemp5063 = rval * x;
return nctemp5063;
}
float LibeGetfman2 (float x)
{
float absx;
int n;
float nctemp5068= x;
float nctemp5070=LibeFabs(nctemp5068);
absx =nctemp5070;
n =0;
int nctemp5075 = (x ==0.0);
if(nctemp5075)
{
return 0.0;
}
int nctemp5080 = (absx < 0.5);
int nctemp5084=nctemp5080;
while(nctemp5084)
{{
int nctemp5093 = n - 1;
n =nctemp5093;
float nctemp5102 = absx * 2.0;
absx =nctemp5102;
}
int nctemp5103 = (absx < 0.5);
nctemp5084=nctemp5103;}int nctemp5107 = (absx >= 1.0);
int nctemp5111=nctemp5107;
while(nctemp5111)
{{
int nctemp5120 = n + 1;
n =nctemp5120;
float nctemp5129 = absx * 0.5;
absx =nctemp5129;
}
int nctemp5130 = (absx >= 1.0);
nctemp5111=nctemp5130;}int nctemp5134 = (x < 0.0);
if(nctemp5134)
{
float nctemp5138= -absx;
return nctemp5138;
}
else{
return absx;
}
}
int LibeGetfexp2 (float x)
{
float absx;
int n;
float nctemp5144= x;
float nctemp5146=LibeFabs(nctemp5144);
absx =nctemp5146;
n =0;
int nctemp5151 = (x ==0.0);
if(nctemp5151)
{
return 0;
}
int nctemp5156 = (absx < 0.5);
int nctemp5160=nctemp5156;
while(nctemp5160)
{{
int nctemp5169 = n - 1;
n =nctemp5169;
float nctemp5178 = absx * 2.0;
absx =nctemp5178;
}
int nctemp5179 = (absx < 0.5);
nctemp5160=nctemp5179;}int nctemp5183 = (absx >= 1.0);
int nctemp5187=nctemp5183;
while(nctemp5187)
{{
int nctemp5196 = n + 1;
n =nctemp5196;
float nctemp5205 = absx * 0.5;
absx =nctemp5205;
}
int nctemp5206 = (absx >= 1.0);
nctemp5187=nctemp5206;}return n;
}
float LibeFscale (float x,int n)
{
int i;
float rval;
rval =1.0;
int nctemp5215 = (n ==0);
if(nctemp5215)
{
return x;
}
int nctemp5220 = (n > 0);
if(nctemp5220)
{
i =0;
int nctemp5228 = (i < n);
while(nctemp5228){
{
float nctemp5240 = rval * 10.0;
rval =nctemp5240;
}
int nctemp5249 = i + 1;
i =nctemp5249;
int nctemp5250 = (i < n);
nctemp5228=nctemp5250;
}
}
else{
int nctemp5257= -n;
n =nctemp5257;
i =0;
int nctemp5262 = (i < n);
while(nctemp5262){
{
float nctemp5274 = rval * 0.1;
rval =nctemp5274;
}
int nctemp5283 = i + 1;
i =nctemp5283;
int nctemp5284 = (i < n);
nctemp5262=nctemp5284;
}
}
float nctemp5292 = rval * x;
return nctemp5292;
}
int LibeGetfman (float f,int maxdig)
{
int sign;
int nexp;
int n;
int i;
int nctemp5293 = (f ==0.0);
if(nctemp5293)
{
return 0;
}
sign =1;
int nctemp5302 = (f < 0.0);
if(nctemp5302)
{
float nctemp5309= -f;
f =nctemp5309;
int nctemp5313= -sign;
sign =nctemp5313;
}
nexp =0;
float nctemp5328 = f / 10.0;
float nctemp5330 = nctemp5328 + 1.1920928955078125e-07;
int nctemp5318 = (nctemp5330 >= 1.0);
if(nctemp5318)
{
float nctemp5342 = f / 10.0;
float nctemp5344 = nctemp5342 + 1.1920928955078125e-07;
int nctemp5332 = (nctemp5344 >= 1.0);
int nctemp5346=nctemp5332;
while(nctemp5346)
{{
float nctemp5355 = f / 10.0;
f =nctemp5355;
int nctemp5364 = nexp + 1;
nexp =nctemp5364;
}
float nctemp5375 = f / 10.0;
float nctemp5377 = nctemp5375 + 1.1920928955078125e-07;
int nctemp5365 = (nctemp5377 >= 1.0);
nctemp5346=nctemp5365;}}
else{
float nctemp5386 = f + 1.1920928955078125e-07;
int nctemp5379 = (nctemp5386 < 1.0);
if(nctemp5379)
{
float nctemp5395 = f + 1.1920928955078125e-07;
int nctemp5388 = (nctemp5395 < 1.0);
int nctemp5397=nctemp5388;
while(nctemp5397)
{{
float nctemp5406 = f * 10.0;
f =nctemp5406;
int nctemp5415 = nexp - 1;
nexp =nctemp5415;
}
float nctemp5423 = f + 1.1920928955078125e-07;
int nctemp5416 = (nctemp5423 < 1.0);
nctemp5397=nctemp5416;}}
}
i =0;
int nctemp5437 = maxdig - 1;
int nctemp5429 = (i < nctemp5437);
while(nctemp5429){
{
float nctemp5446 = f * 10.0;
f =nctemp5446;
}
int nctemp5455 = i + 1;
i =nctemp5455;
int nctemp5464 = maxdig - 1;
int nctemp5456 = (i < nctemp5464);
nctemp5429=nctemp5456;
}
float nctemp5475 = f + 0.5;
int nctemp5469=(int)(nctemp5475);
n =nctemp5469;
int nctemp5476 = (sign < 0);
if(nctemp5476)
{
int nctemp5483= -n;
n =nctemp5483;
}
return n;
}
float LibeGetffman (float f)
{
int sign;
int nexp;
int nctemp5485 = (f ==0.0);
if(nctemp5485)
{
return 0.0;
}
sign =1;
int nctemp5494 = (f < 0.0);
if(nctemp5494)
{
float nctemp5501= -f;
f =nctemp5501;
int nctemp5505= -sign;
sign =nctemp5505;
}
nexp =0;
float nctemp5520 = f / 10.0;
float nctemp5522 = nctemp5520 + 1.1920928955078125e-07;
int nctemp5510 = (nctemp5522 >= 1.0);
if(nctemp5510)
{
float nctemp5534 = f / 10.0;
float nctemp5536 = nctemp5534 + 1.1920928955078125e-07;
int nctemp5524 = (nctemp5536 >= 1.0);
int nctemp5538=nctemp5524;
while(nctemp5538)
{{
float nctemp5547 = f / 10.0;
f =nctemp5547;
int nctemp5556 = nexp + 1;
nexp =nctemp5556;
}
float nctemp5567 = f / 10.0;
float nctemp5569 = nctemp5567 + 1.1920928955078125e-07;
int nctemp5557 = (nctemp5569 >= 1.0);
nctemp5538=nctemp5557;}}
else{
float nctemp5578 = f + 1.1920928955078125e-07;
int nctemp5571 = (nctemp5578 < 1.0);
if(nctemp5571)
{
float nctemp5587 = f + 1.1920928955078125e-07;
int nctemp5580 = (nctemp5587 < 1.0);
int nctemp5589=nctemp5580;
while(nctemp5589)
{{
float nctemp5598 = f * 10.0;
f =nctemp5598;
int nctemp5607 = nexp - 1;
nexp =nctemp5607;
}
float nctemp5615 = f + 1.1920928955078125e-07;
int nctemp5608 = (nctemp5615 < 1.0);
nctemp5589=nctemp5608;}}
}
return f;
}
int LibeGetmaxdig (float f)
{
int sign;
int nexp;
int i;
int loop;
float r;
int nctemp5618 = (f ==0.0);
if(nctemp5618)
{
return 0;
}
sign =1;
int nctemp5627 = (f < 0.0);
if(nctemp5627)
{
float nctemp5634= -f;
f =nctemp5634;
int nctemp5638= -sign;
sign =nctemp5638;
}
nexp =0;
float nctemp5653 = f / 10.0;
float nctemp5655 = nctemp5653 + 1.1920928955078125e-07;
int nctemp5643 = (nctemp5655 >= 1.0);
if(nctemp5643)
{
float nctemp5667 = f / 10.0;
float nctemp5669 = nctemp5667 + 1.1920928955078125e-07;
int nctemp5657 = (nctemp5669 >= 1.0);
int nctemp5671=nctemp5657;
while(nctemp5671)
{{
float nctemp5680 = f / 10.0;
f =nctemp5680;
int nctemp5689 = nexp + 1;
nexp =nctemp5689;
}
float nctemp5700 = f / 10.0;
float nctemp5702 = nctemp5700 + 1.1920928955078125e-07;
int nctemp5690 = (nctemp5702 >= 1.0);
nctemp5671=nctemp5690;}}
else{
float nctemp5711 = f + 1.1920928955078125e-07;
int nctemp5704 = (nctemp5711 < 1.0);
if(nctemp5704)
{
float nctemp5720 = f + 1.1920928955078125e-07;
int nctemp5713 = (nctemp5720 < 1.0);
int nctemp5722=nctemp5713;
while(nctemp5722)
{{
float nctemp5731 = f * 10.0;
f =nctemp5731;
int nctemp5740 = nexp - 1;
nexp =nctemp5740;
}
float nctemp5748 = f + 1.1920928955078125e-07;
int nctemp5741 = (nctemp5748 < 1.0);
nctemp5722=nctemp5741;}}
}
i =0;
loop =1;
int nctemp5759=loop;
while(nctemp5759)
{{
int nctemp5771=(int)(f);
float nctemp5768=(float)(nctemp5771);
float nctemp5774 = f - nctemp5768;
r =nctemp5774;
int nctemp5775 = (r < 1.1920928955078125e-07);
if(nctemp5775)
{
loop =0;
}
else{
float nctemp5791 = f * 10.0;
f =nctemp5791;
}
int nctemp5800 = i + 1;
i =nctemp5800;
int nctemp5801 = (i >= 10);
if(nctemp5801)
{
loop =0;
}
}
nctemp5759=loop;}return i;
}
int LibeGetfexp (float f)
{
int nexp;
int nctemp5811 = (f ==0.0);
if(nctemp5811)
{
return 0;
}
nexp =0;
int nctemp5820 = (f < 0.0);
if(nctemp5820)
{
float nctemp5827= -f;
f =nctemp5827;
}
float nctemp5838 = f / 10.0;
float nctemp5840 = nctemp5838 + 1.1920928955078125e-07;
int nctemp5828 = (nctemp5840 >= 1.0);
if(nctemp5828)
{
float nctemp5852 = f / 10.0;
float nctemp5854 = nctemp5852 + 1.1920928955078125e-07;
int nctemp5842 = (nctemp5854 >= 1.0);
int nctemp5856=nctemp5842;
while(nctemp5856)
{{
float nctemp5865 = f / 10.0;
f =nctemp5865;
int nctemp5874 = nexp + 1;
nexp =nctemp5874;
}
float nctemp5885 = f / 10.0;
float nctemp5887 = nctemp5885 + 1.1920928955078125e-07;
int nctemp5875 = (nctemp5887 >= 1.0);
nctemp5856=nctemp5875;}}
else{
float nctemp5896 = f + 1.1920928955078125e-07;
int nctemp5889 = (nctemp5896 < 1.0);
if(nctemp5889)
{
float nctemp5905 = f + 1.1920928955078125e-07;
int nctemp5898 = (nctemp5905 < 1.0);
int nctemp5907=nctemp5898;
while(nctemp5907)
{{
float nctemp5916 = f * 10.0;
f =nctemp5916;
int nctemp5925 = nexp - 1;
nexp =nctemp5925;
}
float nctemp5933 = f + 1.1920928955078125e-07;
int nctemp5926 = (nctemp5933 < 1.0);
nctemp5907=nctemp5926;}}
}
return nexp;
}
float LibeClock ()
{
float nctemp5937=RunClock();
return nctemp5937;
}
int NBLOCKS;
int NTHREADS;
int LibeSetnb (int nb)
{
NBLOCKS =nb;
return 1;
}
int LibeSetnt (int nt)
{
NTHREADS =nt;
return 1;
}
int LibeGetnb ()
{
return NBLOCKS;
}
int LibeGetnt ()
{
return NTHREADS;
}
float LibeSincosmax;
float LibeSincoslim;
float LibeLnmax;
float LibeLnmin;
float LibeSincos (float x,float y,float sign);
float LibeAtan (float f);
int LibeMathinit ()
{
float nctemp5954= 1.0;
int nctemp5961 = 24 - 1;
int nctemp5956= nctemp5961;
float nctemp5962=LibeFscale2(nctemp5954,nctemp5956);
LibeSincosmax =nctemp5962;
float nctemp5971= LibeSincosmax;
float nctemp5973=LibeSqrt(nctemp5971);
float nctemp5974 = 3.1415926535897932384626433832795028841972 * nctemp5973;
LibeSincosmax =nctemp5974;
float nctemp5983= 1.0;
int nctemp5990 = 24 / 2;
int nctemp5985= nctemp5990;
float nctemp5991=LibeFscale2(nctemp5983,nctemp5985);
float nctemp5992 = 1.0 / nctemp5991;
LibeSincoslim =nctemp5992;
float nctemp5997= 3.4028234663852886e+38;
float nctemp5999=LibeLn(nctemp5997);
LibeLnmax =nctemp5999;
float nctemp6004= 1.1754943508222875e-38;
float nctemp6006=LibeLn(nctemp6004);
LibeLnmin =nctemp6006;
return 1;
}
float LibeSqrt (float x)
{
float f;
float yest;
float z;
int n;
int nctemp6008 = (x ==0.0);
if(nctemp6008)
{
return 0.0;
}
int nctemp6013 = (x < 0.0);
if(nctemp6013)
{
LibeErrno =(-101);
struct nctempchar1 *nctemp6026;
static struct nctempchar1 nctemp6027 = {{ 25}, (char*)"Sqrt input argument < 0 \0"};
nctemp6026=&nctemp6027;
LibeErrstr=nctemp6026;
return 0.0;
}
float nctemp6033= x;
float nctemp6035=LibeGetfman2(nctemp6033);
f =nctemp6035;
float nctemp6040= x;
int nctemp6042=LibeGetfexp2(nctemp6040);
n =nctemp6042;
float nctemp6055 = 0.59016 * f;
float nctemp6056 = 0.41731 + nctemp6055;
yest =nctemp6056;
float nctemp6069 = f / yest;
float nctemp6070 = yest + nctemp6069;
z =nctemp6070;
float nctemp6082 = 0.25 * z;
float nctemp6088 = f / z;
float nctemp6089 = nctemp6082 + nctemp6088;
yest =nctemp6089;
int nctemp6093= n;
int nctemp6095= 2;
int nctemp6097=LibeMod(nctemp6093,nctemp6095);
int nctemp6090 = (nctemp6097 !=0);
if(nctemp6090)
{
float nctemp6107 = yest * 0.70710678118654752440;
yest =nctemp6107;
int nctemp6116 = n + 1;
n =nctemp6116;
}
float nctemp6118= yest;
int nctemp6125 = n / 2;
int nctemp6120= nctemp6125;
float nctemp6126=LibeFscale2(nctemp6118,nctemp6120);
return nctemp6126;
}
float LibeLn (float x)
{
float f;
int n;
float z;
float zn;
float zd;
float w;
float r;
float xn;
int nctemp6127 = (x <= 0.0);
if(nctemp6127)
{
LibeErrno =(-101);
struct nctempchar1 *nctemp6140;
static struct nctempchar1 nctemp6141 = {{ 23}, (char*)"Ln input argument < 0 \0"};
nctemp6140=&nctemp6141;
LibeErrstr=nctemp6140;
return 3.4028234663852886e+38;
}
float nctemp6147= x;
float nctemp6149=LibeGetfman2(nctemp6147);
f =nctemp6149;
float nctemp6154= x;
int nctemp6156=LibeGetfexp2(nctemp6154);
n =nctemp6156;
int nctemp6157 = (f > 0.70710678118654752440);
if(nctemp6157)
{
float nctemp6172 = f - 0.5;
float nctemp6174 = nctemp6172 - 0.5;
zn =nctemp6174;
float nctemp6186 = f * 0.5;
float nctemp6188 = nctemp6186 + 0.5;
zd =nctemp6188;
}
else{
float nctemp6197 = f - 0.5;
zn =nctemp6197;
float nctemp6209 = zn * 0.5;
float nctemp6211 = nctemp6209 + 0.5;
zd =nctemp6211;
int nctemp6220 = n - 1;
n =nctemp6220;
}
float nctemp6229 = zn / zd;
z =nctemp6229;
float nctemp6238 = z * z;
w =nctemp6238;
float nctemp6258 = w * (-0.5527074855E+0);
float nctemp6264 = w + (-0.6632718214E+1);
float nctemp6265 = nctemp6258 / nctemp6264;
float nctemp6266 = z * nctemp6265;
float nctemp6267 = z + nctemp6266;
r =nctemp6267;
float nctemp6272=(float)(n);
xn =nctemp6272;
float nctemp6285 = xn * (-2.121944400546905827679E-4);
float nctemp6287 = nctemp6285 + r;
float nctemp6293 = xn * 0.69335938;
float nctemp6294 = nctemp6287 + nctemp6293;
return nctemp6294;
}
float LibeExp (float x)
{
int n;
float g;
float z;
float p;
float q;
float xn;
float P0;
float P1;
float Q1;
float rval;
P0 =0.24999999950E+0;
P1 =0.41602886268E-2;
Q1 =0.49987178778E-1;
int nctemp6307 = (x >= LibeLnmax);
if(nctemp6307)
{
LibeErrno =(-102);
struct nctempchar1 *nctemp6320;
static struct nctempchar1 nctemp6321 = {{ 25}, (char*)"Overflow in exp function\0"};
nctemp6320=&nctemp6321;
LibeErrstr=nctemp6320;
return 3.4028234663852886e+38;
}
int nctemp6323 = (x < LibeLnmin);
if(nctemp6323)
{
LibeErrno =(-102);
struct nctempchar1 *nctemp6336;
static struct nctempchar1 nctemp6337 = {{ 26}, (char*)"Underflow in exp function\0"};
nctemp6336=&nctemp6337;
LibeErrstr=nctemp6336;
return 0.0;
}
float nctemp6349 = x * 1.4426950408889634073;
int nctemp6343=(int)(nctemp6349);
n =nctemp6343;
float nctemp6354=(float)(n);
xn =nctemp6354;
float nctemp6369 = xn * 0.693147180559945309417232;
float nctemp6370 = x - nctemp6369;
g =nctemp6370;
float nctemp6379 = g * g;
z =nctemp6379;
float nctemp6394 = P1 * z;
float nctemp6396 = nctemp6394 + P0;
float nctemp6398 = nctemp6396 * g;
p =nctemp6398;
float nctemp6410 = Q1 * z;
float nctemp6412 = nctemp6410 + 0.5;
q =nctemp6412;
float nctemp6429 = q - p;
float nctemp6430 = p / nctemp6429;
float nctemp6431 = 0.5 + nctemp6430;
rval =nctemp6431;
float nctemp6433= rval;
int nctemp6440 = n + 1;
int nctemp6435= nctemp6440;
float nctemp6441=LibeFscale2(nctemp6433,nctemp6435);
return nctemp6441;
}
float LibeSincos (float x,float y,float sign)
{
int n;
float xn;
float f;
float g;
float R1;
float R2;
float R3;
float R4;
float nctemp6445= -0.1666665668E+0;
R1 =nctemp6445;
R2 =0.8333025139E-2;
float nctemp6453= -0.1980741872E-3;
R3 =nctemp6453;
R4 =0.2601903036E-5;
int nctemp6458 = (y > LibeSincosmax);
if(nctemp6458)
{
LibeErrno =(-102);
struct nctempchar1 *nctemp6471;
static struct nctempchar1 nctemp6472 = {{ 37}, (char*)"Loss of accuracy in sin/cos function\0"};
nctemp6471=&nctemp6472;
LibeErrstr=nctemp6471;
return 0.0;
}
float nctemp6487 = y * 0.31830988618379067154;
float nctemp6489 = nctemp6487 + 0.5;
int nctemp6478=(int)(nctemp6489);
n =nctemp6478;
float nctemp6494=(float)(n);
xn =nctemp6494;
int nctemp6500= n;
int nctemp6502= 2;
int nctemp6504=LibeMod(nctemp6500,nctemp6502);
int nctemp6497 = (nctemp6504 !=0);
if(nctemp6497)
{
float nctemp6509= -sign;
sign =nctemp6509;
}
float nctemp6514= x;
float nctemp6516=LibeFabs(nctemp6514);
x =nctemp6516;
int nctemp6517 = (x !=y);
if(nctemp6517)
{
float nctemp6529 = xn - 0.5;
xn =nctemp6529;
}
float nctemp6537= x;
float nctemp6539=LibeFabs(nctemp6537);
float nctemp6545 = xn * 3.1415926535897932384626433832795028841972;
float nctemp6546 = nctemp6539 - nctemp6545;
f =nctemp6546;
float nctemp6550= f;
float nctemp6552=LibeFabs(nctemp6550);
int nctemp6547 = (nctemp6552 < LibeSincoslim);
if(nctemp6547)
{
float nctemp6558 = sign * f;
return nctemp6558;
}
float nctemp6567 = f * f;
g =nctemp6567;
float nctemp6594 = R4 * g;
float nctemp6596 = nctemp6594 + R3;
float nctemp6598 = nctemp6596 * g;
float nctemp6600 = nctemp6598 + R2;
float nctemp6602 = nctemp6600 * g;
float nctemp6604 = nctemp6602 + R1;
float nctemp6606 = nctemp6604 * g;
g =nctemp6606;
float nctemp6619 = f * g;
float nctemp6620 = f + nctemp6619;
g =nctemp6620;
float nctemp6625 = sign * g;
return nctemp6625;
}
float LibeSin (float x)
{
int nctemp6626 = (x < 0.0);
if(nctemp6626)
{
float nctemp6631= x;
float nctemp6634= -x;
float nctemp6633= nctemp6634;
float nctemp6636= -1.0;
float nctemp6635= nctemp6636;
float nctemp6637=LibeSincos(nctemp6631,nctemp6633,nctemp6635);
return nctemp6637;
}
else{
float nctemp6639= x;
float nctemp6641= x;
float nctemp6643= 1.0;
float nctemp6645=LibeSincos(nctemp6639,nctemp6641,nctemp6643);
return nctemp6645;
}
}
float LibeCos (float x)
{
float nctemp6647= x;
float nctemp6653= x;
float nctemp6655=LibeFabs(nctemp6653);
float nctemp6657 = nctemp6655 + 1.57079632679489661923132;
float nctemp6649= nctemp6657;
float nctemp6658= 1.0;
float nctemp6660=LibeSincos(nctemp6647,nctemp6649,nctemp6658);
return nctemp6660;
}
float LibeTan (float x)
{
float P1;
float Q1;
float Q2;
int n;
float y;
float xn;
float f;
float xnum;
float xden;
float g;
float nctemp6664= -0.958017723E-1;
P1 =nctemp6664;
float nctemp6668= -0.429135777E+0;
Q1 =nctemp6668;
Q2 =0.971685835E-2;
float nctemp6677= x;
float nctemp6679=LibeFabs(nctemp6677);
y =nctemp6679;
int nctemp6680 = (y > LibeSincosmax);
if(nctemp6680)
{
LibeErrno =(-102);
struct nctempchar1 *nctemp6693;
static struct nctempchar1 nctemp6694 = {{ 33}, (char*)"Loss of accuracy in tan function\0"};
nctemp6693=&nctemp6694;
LibeErrstr=nctemp6693;
return 0.0;
}
float nctemp6706 = x * 0.63661977236758134308;
int nctemp6700=(int)(nctemp6706);
n =nctemp6700;
float nctemp6711=(float)(n);
xn =nctemp6711;
float nctemp6726 = xn * 1.57079632679489661923132;
float nctemp6727 = x - nctemp6726;
f =nctemp6727;
float nctemp6731= f;
float nctemp6733=LibeFabs(nctemp6731);
int nctemp6728 = (nctemp6733 < LibeSincoslim);
if(nctemp6728)
{
xnum =f;
xden =1.0;
}
else{
float nctemp6751 = f * f;
g =nctemp6751;
float nctemp6766 = P1 * g;
float nctemp6768 = nctemp6766 * f;
float nctemp6770 = nctemp6768 + f;
xnum =nctemp6770;
float nctemp6791 = Q2 * g;
float nctemp6793 = nctemp6791 + Q1;
float nctemp6795 = nctemp6793 * g;
float nctemp6797 = nctemp6795 + 0.5;
float nctemp6799 = nctemp6797 + 0.5;
xden =nctemp6799;
}
int nctemp6803= n;
int nctemp6805= 2;
int nctemp6807=LibeMod(nctemp6803,nctemp6805);
int nctemp6800 = (nctemp6807 !=0);
if(nctemp6800)
{
float nctemp6812= -xnum;
float nctemp6813 = xden / nctemp6812;
return nctemp6813;
}
else{
float nctemp6818 = xnum / xden;
return nctemp6818;
}
}
float LibeArcsin (float x)
{
float P1;
float P2;
float Q0;
float Q1;
float y;
float g;
float r;
float res;
int i;
P1 =0.933935835E+0;
float nctemp6826= -0.504400557E+0;
P2 =nctemp6826;
Q0 =0.560363004E+1;
float nctemp6834= -0.554846723E+1;
Q1 =nctemp6834;
float nctemp6839= x;
float nctemp6841=LibeFabs(nctemp6839);
y =nctemp6841;
int nctemp6842 = (y > 0.5);
if(nctemp6842)
{
i =1;
int nctemp6850 = (y > 1.0);
if(nctemp6850)
{
LibeErrno =(-101);
struct nctempchar1 *nctemp6863;
static struct nctempchar1 nctemp6864 = {{ 41}, (char*)"Absolute value of argument of arcsin > 1\0"};
nctemp6863=&nctemp6864;
LibeErrstr=nctemp6863;
return 3.4028234663852886e+38;
}
float nctemp6877 = 1.0 - y;
float nctemp6879 = nctemp6877 * 0.5;
g =nctemp6879;
float nctemp6884= g;
float nctemp6886=LibeSqrt(nctemp6884);
r =nctemp6886;
float nctemp6890= -r;
r =nctemp6890;
float nctemp6899 = r + r;
y =nctemp6899;
float nctemp6917 = P2 * g;
float nctemp6919 = nctemp6917 + P1;
float nctemp6921 = nctemp6919 * g;
float nctemp6933 = g + Q1;
float nctemp6935 = nctemp6933 * g;
float nctemp6937 = nctemp6935 + Q0;
float nctemp6938 = nctemp6921 / nctemp6937;
r =nctemp6938;
float nctemp6951 = y * r;
float nctemp6952 = y + nctemp6951;
res =nctemp6952;
}
else{
i =0;
int nctemp6957 = (y < LibeSincoslim);
if(nctemp6957)
{
res =y;
}
else{
float nctemp6973 = y * y;
g =nctemp6973;
float nctemp6991 = P2 * g;
float nctemp6993 = nctemp6991 + P1;
float nctemp6995 = nctemp6993 * g;
float nctemp7007 = g + Q1;
float nctemp7009 = nctemp7007 * g;
float nctemp7011 = nctemp7009 + Q0;
float nctemp7012 = nctemp6995 / nctemp7011;
g =nctemp7012;
float nctemp7025 = y * g;
float nctemp7026 = y + nctemp7025;
res =nctemp7026;
}
}
int nctemp7027 = (i ==1);
if(nctemp7027)
{
float nctemp7043 = 0.78539816339744830962 + res;
float nctemp7044 = 0.78539816339744830962 + nctemp7043;
res =nctemp7044;
}
int nctemp7045 = (x < 0.0);
if(nctemp7045)
{
float nctemp7052= -res;
res =nctemp7052;
}
return res;
}
float LibeArccos (float x)
{
float P1;
float P2;
float Q0;
float Q1;
float y;
float g;
float r;
float res;
int i;
P1 =0.933935835E+0;
float nctemp7061= -0.504400557E+0;
P2 =nctemp7061;
Q0 =0.560363004E+1;
float nctemp7069= -0.554846723E+1;
Q1 =nctemp7069;
float nctemp7074= x;
float nctemp7076=LibeFabs(nctemp7074);
y =nctemp7076;
int nctemp7077 = (y > 0.5);
if(nctemp7077)
{
i =0;
int nctemp7085 = (y > 1.0);
if(nctemp7085)
{
LibeErrno =(-101);
struct nctempchar1 *nctemp7098;
static struct nctempchar1 nctemp7099 = {{ 50}, (char*)"Absolute value of argument of arccos out of range\0"};
nctemp7098=&nctemp7099;
LibeErrstr=nctemp7098;
return 3.4028234663852886e+38;
}
float nctemp7112 = 1.0 - y;
float nctemp7114 = nctemp7112 * 0.5;
g =nctemp7114;
float nctemp7119= g;
float nctemp7121=LibeSqrt(nctemp7119);
r =nctemp7121;
float nctemp7125= -r;
r =nctemp7125;
float nctemp7134 = r + r;
y =nctemp7134;
float nctemp7152 = P2 * g;
float nctemp7154 = nctemp7152 + P1;
float nctemp7156 = nctemp7154 * g;
float nctemp7168 = g + Q1;
float nctemp7170 = nctemp7168 * g;
float nctemp7172 = nctemp7170 + Q0;
float nctemp7173 = nctemp7156 / nctemp7172;
r =nctemp7173;
float nctemp7186 = y * r;
float nctemp7187 = y + nctemp7186;
res =nctemp7187;
}
else{
i =1;
int nctemp7192 = (y < LibeSincoslim);
if(nctemp7192)
{
res =y;
}
else{
float nctemp7208 = y * y;
g =nctemp7208;
float nctemp7226 = P2 * g;
float nctemp7228 = nctemp7226 + P1;
float nctemp7230 = nctemp7228 * g;
float nctemp7242 = g + Q1;
float nctemp7244 = nctemp7242 * g;
float nctemp7246 = nctemp7244 + Q0;
float nctemp7247 = nctemp7230 / nctemp7246;
g =nctemp7247;
float nctemp7260 = y * g;
float nctemp7261 = y + nctemp7260;
res =nctemp7261;
}
}
int nctemp7262 = (x < 0.0);
if(nctemp7262)
{
int nctemp7266 = (i ==0);
if(nctemp7266)
{
float nctemp7282 = 1.57079632679489661923132 + res;
float nctemp7283 = 1.57079632679489661923132 + nctemp7282;
res =nctemp7283;
}
else{
float nctemp7296 = 0.78539816339744830962 + res;
float nctemp7297 = 0.78539816339744830962 + nctemp7296;
res =nctemp7297;
}
}
else{
int nctemp7298 = (i ==1);
if(nctemp7298)
{
float nctemp7314 = 0.78539816339744830962 - res;
float nctemp7315 = 0.78539816339744830962 + nctemp7314;
res =nctemp7315;
}
else{
float nctemp7319= -res;
res =nctemp7319;
}
}
return res;
}
float LibeAtan (float f)
{
float rt32;
float rt3;
float a;
float P0;
float P1;
float Q0;
int n;
float res;
float g;
rt32 =0.26794919243112270647;
rt3 =1.73205080756887729353;
float nctemp7337 = rt3 - 1.0;
a =nctemp7337;
float nctemp7341= -0.4708325141E+0;
P0 =nctemp7341;
float nctemp7345= -0.5090958253E-1;
P1 =nctemp7345;
Q0 =0.1412500740E+1;
int nctemp7350 = (f > 1.0);
if(nctemp7350)
{
float nctemp7362 = 1.0 / f;
f =nctemp7362;
n =2;
}
else{
n =0;
}
int nctemp7371 = (f > rt32);
if(nctemp7371)
{
float nctemp7395 = a * f;
float nctemp7397 = nctemp7395 - 0.5;
float nctemp7399 = nctemp7397 - 0.5;
float nctemp7401 = nctemp7399 + f;
float nctemp7407 = rt3 + f;
float nctemp7408 = nctemp7401 / nctemp7407;
f =nctemp7408;
int nctemp7417 = n + 1;
n =nctemp7417;
}
float nctemp7421= f;
float nctemp7423=LibeFabs(nctemp7421);
int nctemp7418 = (nctemp7423 < LibeSincoslim);
if(nctemp7418)
{
res =f;
}
else{
float nctemp7437 = f * f;
g =nctemp7437;
float nctemp7455 = P1 * g;
float nctemp7457 = nctemp7455 + P0;
float nctemp7459 = nctemp7457 * g;
float nctemp7465 = g + Q0;
float nctemp7466 = nctemp7459 / nctemp7465;
res =nctemp7466;
float nctemp7479 = f * res;
float nctemp7480 = f + nctemp7479;
res =nctemp7480;
}
int nctemp7481 = (n > 1);
if(nctemp7481)
{
float nctemp7488= -res;
res =nctemp7488;
}
int nctemp7489 = (n ==1);
if(nctemp7489)
{
float nctemp7501 = res + 0.52359877559829887308;
res =nctemp7501;
}
else{
int nctemp7502 = (n ==2);
if(nctemp7502)
{
float nctemp7514 = res + 1.57079632679489661923132;
res =nctemp7514;
}
else{
int nctemp7515 = (n ==3);
if(nctemp7515)
{
float nctemp7527 = res + 1.04719755119659774615;
res =nctemp7527;
}
}
}
return res;
}
float LibeArctan (float x)
{
float rval;
int nctemp7529 = (x < 0.0);
if(nctemp7529)
{
float nctemp7538= -x;
float nctemp7537= nctemp7538;
float nctemp7539=LibeAtan(nctemp7537);
rval =nctemp7539;
float nctemp7543= -rval;
rval =nctemp7543;
}
else{
float nctemp7548= x;
float nctemp7550=LibeAtan(nctemp7548);
rval =nctemp7550;
}
return rval;
}
float LibePow (float base,float exponent)
{
float nctemp7558= base;
float nctemp7560=LibeLn(nctemp7558);
float nctemp7561 = exponent * nctemp7560;
float nctemp7553= nctemp7561;
float nctemp7562=LibeExp(nctemp7553);
return nctemp7562;
}
int LibeMod (int n,int r)
{
int nctemp7563 = (r ==0);
if(nctemp7563)
{
return n;
}
int nctemp7579 = n / r;
int nctemp7581 = nctemp7579 * r;
int nctemp7582 = n - nctemp7581;
return nctemp7582;
}
int LibeSystem (nctempchar1 *cmd)
{
int rval;
nctempchar1* nctemp7587= cmd;
int nctemp7590=RunSystem(nctemp7587);
rval =nctemp7590;
return rval;
}
}
