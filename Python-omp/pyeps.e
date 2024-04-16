
include <libe.i>                 // Library interface

// Create string array
char [*] PyepsCre1ds(int Nx){}

// Delete 1D string array
int PyepsDel1ds(char [*] arr){}

//Set 1D string array
int PyepsSet1ds(char [*] arr, int i, char val){}

// Create integer array
int [*] PyepsCre1di(int Nx){}

// Delete 1D integer array
int PyepsDel1di(int [*] arr){}

//Set 1D integer array
int PyepsSet1di(int [*] arr, int i, int val){}

// Create 1D float array
float [*] PyepsCre1df(int Nx){}

// Delete 1D float array
int PyepsDel1df(float [*] arr){}

//Set 1D float array
int PyepsSet1df(float [*] arr, int i, float val){}

// Create 2D float array
float [*,*] PyepsCre2df(int Nx, int Ny){}

// Delete 2D float array
int PyepsDel2df(float [*,*] arr){}

//Set 2D float array
int PyepsSet2df(float [*,*] arr, int i, int j, float val){}


//Empty main program
int Main(struct MainArg [*] MainArgs)
{
  return(1);
}

char [*] PyepsCre1ds(int Nx){
  char [*] str;
  str = new(char [Nx+1]);
  str[Nx] = cast(char,0);
  return(str);
}

int PyepsDel1ds(char [*] arr){
   delete(arr);
   return(1);
}

int PyepsSet1ds(char [*] arr, int i, char val){
  arr[i] = val;
  return(1);
}

int [*] PyepsCre1di(int Nx){
  int [*] tmp;
  tmp = new(int [Nx]);
  return(tmp);
}

int PyepsDel1di(int [*] arr){
   delete(arr);
   return(1);
}

int PyepsSet1di(int [*] arr, int i, int val){
  arr[i] = val;
  return(1);
}

float [*] PyepsCre1df(int Nx){
  float [*] tmp;
  tmp=new(float [Nx]);
  return(tmp);
}

int PyepsDel1df(float [*] arr){
   delete(arr);
   return(1);
}

int PyepsSet1df(float [*] arr, int i, float val){
  arr[i] = val;
  return(1);
}

float [*,*] PyepsCre2df(int Nx, int Ny){
  return(new(float [Nx,Ny]));
}

int PyepsDel2df(float [*,*] arr){
   delete(arr);
   return(1);
}

int PyepsSet2df(float [*,*] arr, int i, int j, float val){
  arr[i,j] = val;
  return(1);
}
