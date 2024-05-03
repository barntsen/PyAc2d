
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


//Empty main program (Necessary for linking)
int Main(struct MainArg [*] MainArgs)
{
  return(1);
}

// PepsCre1ds creates a string buffer
//
// Parameter:
//  Nx      : No of characters in buffer
//
// Returns:
//  str     : String buffer
char [*] PyepsCre1ds(int Nx){
  char [*] str;
  str = new(char [Nx+1]);
  str[Nx] = cast(char,0);
  return(str);
}

// PepsDel1ds deletes string buffer
//
// Parameter:
//  arr      : String buffer
//
// Returns: integer equal to 1
//  
int PyepsDel1ds(char [*] arr){
   delete(arr);
   return(1);
}

// PepsSet1ds copies string into buffer
//
// Parameter:
//  char [*] arr : String buffer
//  int i        : Index of string character
//  char val     : String character
//
// Returns: integer equal to 1
//  
int PyepsSet1ds(char [*] arr, int i, char val){
  arr[i] = val;
  return(1);
}

// PepsCre1di creates integer 1D array
//
// Parameter:
//  int Nx      : No of integers in array
//
// Returns:
//  int [*] arr     : Integer array
//
int [*] PyepsCre1di(int Nx){
  int [*] tmp;
  tmp = new(int [Nx]);
  return(tmp);
}

// PepsDel1di deletes 1D integer array
//
// Parameter:
//  int [*] arr      : Integer array
//
// Returns: integer equal to 1
//  
int PyepsDel1di(int [*] arr){
   delete(arr);
   return(1);
}

// PepsSet1di copies integer into array
//
// Parameter:
//  int [*] arr  : Integer array
//  int i        : Index of integer in arr
//  val val      : Integer value 
//
// Returns: integer equal to 1
//  
int PyepsSet1di(int [*] arr, int i, int val){
  arr[i] = val;
  return(1);
}

// PepsCre1di creates float 1D array
//
// Parameter:
//  int Nx      : No of floats in array
//
// Returns:
//  float [*] arr     : Float array
//
float [*] PyepsCre1df(int Nx){
  float [*] tmp;
  tmp=new(float [Nx]);
  return(tmp);
}

// PepsDel1df deletes 1D float array
//
// Parameter:
//  float [*] arr      : Float array
//
// Returns: integer equal to 1
//  
int PyepsDel1df(float [*] arr){
   delete(arr);
   return(1);
}

// PepsSet1df copies float into array
//
// Parameter:
//  float [*] arr: Float array
//  int i        : Index of integer in arr
//  val val      : Integer value 
//
// Returns: integer equal to 1
//  
int PyepsSet1df(float [*] arr, int i, float val){
  arr[i] = val;
  return(1);
}

// PepsCre1di creates float 2D array
//
// Parameter:
//  int Nx      : No of floats in array 1st dim
//  int Ny      : No of floats in array 2nd dim
//
// Returns:
//  float [*,*] arr     : Float array
//
float [*,*] PyepsCre2df(int Nx, int Ny){
  return(new(float [Nx,Ny]));
}

// PepsDel2df deletes 2D float array
//
// Parameter:
//  float [*,*] arr      : Float array
//
// Returns: integer equal to 1
//  
int PyepsDel2df(float [*,*] arr){
   delete(arr);
   return(1);
}

// PepsSet2df copies float into array
//
// Parameter:
//  float [*,*] arr: Float array
//  int i        : Index of integer in arr 1st dim
//  int j        : Index of integer in arr 2nd dim
//  val val      : Integer value 
//
// Returns: integer equal to 1
//  
int PyepsSet2df(float [*,*] arr, int i, int j, float val){
  arr[i,j] = val;
  return(1);
}
