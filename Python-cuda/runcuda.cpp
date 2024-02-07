// run contains runtime functions for the ecc compiler

//Note that this file is a c++ file, but
//stored in a file with extension .e to prevent
//accidental removal
//The run time library is written in C++
//Most of the routines in the library
//are wrappers to unix system calls and the cuda api.

extern "C" {
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
}
//#include<cuda_runtime.h> 
#define OK   1
#define ERR  0
#define EOF (-1)


#define PERMS 0666
#define MAXRANK 1

typedef struct nctempchar1 { int d[MAXRANK]; char *a;} nctempchar1; 
struct MainArg {nctempchar1 *arg;};
struct nctempMainArg1 {int d[MAXRANK]; struct MainArg *a; };
int Main (struct nctempMainArg1 *MainArgs);

// main is the startup code always called by the eps Main function.
int main(int argc, char ** argv)
{
  struct nctempMainArg1 *cmlargs;
  int i;
  int rval;

  cmlargs = (struct nctempMainArg1*)malloc(sizeof(struct nctempMainArg1));
  cmlargs->a = (struct MainArg*) malloc(argc*sizeof(struct MainArg));
  cmlargs->d[0] = argc;
  for(i=0; i<argc; i=i+1){
    cmlargs->a[i].arg = (struct nctempchar1*)malloc(sizeof(struct nctempchar1));
    cmlargs->a[i].arg->a = argv[i]; 
    cmlargs->a[i].arg->d[0] = strlen(argv[i])+1;
  }
  rval = Main(cmlargs);
  if(rval == ERR) 
    rval = -1;
  else
    rval = 0;

  return(rval);
}
  
// GpuNew allocates memory on cpu host and gpu device
void * GpuNew(int n){
  void *f;
  cudaError_t cerr;
  cerr = cudaMallocManaged(&f, n);
  if(cerr != cudaSuccess){
    fprintf(stderr,"GpuNew:%s\n ", cudaGetErrorString(cerr)) ;
    exit(1);
  }
  return(f);
}

// GpuDelete deletes memory on cpu host and gpu device
void GpuDelete(void *f){
  cudaError_t cerr;

  cerr=cudaFree(f);
  if(cerr != cudaSuccess){
    fprintf(stderr,"GpuDelete:%s\n ", cudaGetErrorString(cerr)) ;
    exit(1);
  }
  cerr=cudaDeviceSynchronize();
  if(cerr != cudaSuccess){
    fprintf(stderr,"GpuDelete:%s\n ", cudaGetErrorString(cerr)) ;
    exit(1);
  }
}

// GpuError checks for error on gpu and perform sync
void GpuError(){
  cudaDeviceSynchronize();
  cudaError_t cerr;
  cerr = cudaGetLastError();
  if(cerr != cudaSuccess){
    fprintf(stderr,"%s\n",cudaGetErrorString(cerr));
    exit(1);
  }
}

// RunMalloc allocates memory
void * RunMalloc(int nb)
{
    return((void *)GpuNew(nb));
}

// Runfree delete memory
int RunFree(void* p)
{
    GpuDelete(p);
    return(OK);
}

// RunSync checks for errors and sync
int RunSync()
{
    GpuError();
    return(OK);
}

// RunClock measures time.
float RunClock()
{
  struct timespec tp;
  clock_gettime(CLOCK_MONOTONIC, &tp);
  return (float)((double)tp.tv_sec + (double)tp.tv_nsec*1.0e-9) ;
}

// RunCreate creates a file.
int RunCreate(nctempchar1* name)
{
  int rval;
  
  rval = creat(name->a, PERMS);
  if(rval == -1)
    return(ERR);
  else
    return(rval);
}

// RunOpen opens a file.
int RunOpen(nctempchar1 *name, nctempchar1 *mode)
{
  int rval;
  int flag;

  if(*(mode->a) == 'r')
    flag=O_RDONLY;
  else if(*(mode->a) == 'w')
    flag = O_WRONLY;
  else if(*(mode->a) == 'a')
    flag = O_RDWR | O_APPEND;
  else
    return(ERR);

  rval = open(name->a, flag);
  if(rval == -1)
    return(ERR);
  else
    return (rval);
}

// RunClose closes a file.
int RunClose(int fd)
{
  int rval;
  
  rval = close(fd);
  if(rval == -1)
    return(ERR);
  else
    return(OK);
}

// RunRead reads form a file.
// {\tt RunRead} reads in {\tt lbuff} characters into the
// {\tt buffer} array from a file with descriptor {\tt fd}.
// The return value is the number of characters actually read.
// If an error has occured {\tt ERR} will be returned.
// If the end of a file is reached, {\tt EOF} will
// be returned.
// The {\tt read} routine is a standard UNIX system call.
int RunRead(int fd, int lbuff, nctempchar1 *buffer)
{
  int rval;
  rval = (int)read(fd, (void *)buffer->a, (size_t)lbuff);
  if(rval == 0)
    rval=EOF;
  else if(rval == -1)
    rval = ERR;
  return(rval);
}

// RunWrite writes to a file.
//{\tt RunWrite} writes {\tt lbuff} from the {\tt buffer} array
//into a file with file descriptor {\tt fd}.
//{\tt bufferdesc} is an integer array containg the length
//of the {\tt buffer} array.
//The return value is the number of characters actually written.
//{\tt ERR} is returned whenever an error has occured.
//The {\tt write} routine is a standard UNIX system call.
int RunWrite(int fd, int lbuff, nctempchar1 *buffer)
{
  int rval;
  if(lbuff==0)return(0);
  rval = (int)write(fd, (void *)buffer->a, (size_t)lbuff);
  if(rval == -1)rval=ERR;
  return(rval);
}

// RunSeek sets the file pointer.
// {\tt RunSeek} sets the position of the file pointer to {\tt pos} 
// bytes relative to the beginning of the file if flag equals 0, or
// realtive to the current position if {\tt flag} equals 1 or relative 
// to the end of the file if {\tt flag} equals 2.
int RunSeek(int fd, int flag, int pos)
{
  int rval;
  int fflag;

  if(flag == 0)
    fflag=SEEK_SET;
  else if(flag == 1)
    fflag=SEEK_CUR;
  else if(flag == 2)
    fflag=SEEK_END;
  else
    return(-1);

  rval = (int)lseek(fd, (off_t) pos, fflag);
  if(rval == -1)return(-1);
  return(rval);
}

// RunGetenv gets reads an environment variable
nctempchar1 *RunGetenv(nctempchar1* str)
{
  nctempchar1* rval=(nctempchar1*)malloc(sizeof(nctempchar1));
  rval->a=getenv(str->a); 
  rval->d[0] = strlen(rval->a);
  return(rval);
}
// RunGetnt gets number of threads from
// the NTHREADS environment variable
int RunGetnt() 
{
 int nt;
 char * ntstring;

 char *s = (char *)malloc(sizeof(char)*(strlen("NTHREADS")+1));
 s[strlen("NTHREADS")] = '\0';
 strcpy(s,"NTHREADS");
 ntstring = getenv(s);
 if(ntstring == NULL){
   printf("RunGetnt: Environmental variable NTHREADS must be set to no. of threads\n");
   exit(-1);
 }
 nt = atoi(ntstring); 

 return(nt); 
}

// RunGetnb gets number of blocks from
// the NBLOCKS environment variable
int RunGetnb() 
{
 int nb;
 char * nbstring;

 char *s = (char *)malloc(sizeof(char)*(strlen("NBLOCKS")+1));
 s[strlen("NBLOCKS")] = '\0';
 strcpy(s,"NBLOCKS");
 nbstring = getenv(s);
 if(nbstring == NULL){
   printf("RunGetnb: Environmental variable NBLOCKS must be set to no. of blocks\n");
   exit(-1);
 }
 nb = atoi(nbstring); 

 return(nb); 
}

// RunExit cleans up and exits.
int RunExit()
{
  exit(-1);
  return(OK);
}

// RunSystem executes a shell command
int RunSystem (nctempchar1 *cmd)
{
  int rval;
  rval = system(cmd->a);
  return(rval);
}
