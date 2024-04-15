''' Differentiator class 

    Methods:
      Dxminus : Backward staggered differentiation in the x-direction
      Dyminus : Backward staggered differentiation in the y-direction
      Dxplus  : Forward  staggered differentiation in the x-direction
      Dyplus  : Forward  staggered differentiation in the y-direction
      
'''     


class diff :

  __init__(l) :

  ''' Constructor for the Diff class  

      Parameters:
        l : Differentiator length

  ''' 

  self.lmax = 8;

  if l < 1:
    l=1;
  if l > self.lmax :
    l=self.lmax;

  self.l = l;
  self.coeffs = np.zeros([lmax,lmax]);
  self.w      = np.zeros(l)

  *Load coefficients
  for i in range(0,self.lmax) :
# for (i=0; i<Diff.lmax; i=i+1)
    for j in range(0,self.lmax) :
#   for (j=0; j<Diff.lmax; j=j+1)
      self.coeffs[i,j] = 0.0;
  # l=1
  self.coeffs[0,0] = 1.0021;

  # l=2
  self.coeffs[1,0] = 1.1452;
  self.coeffs[1,1] = -0.0492;
  
  # l=3
  self.coeffs[2,0] = 1.2036;
  self.coeffs[2,1] = -0.0833;
  self.coeffs[2,2] = 0.0097;

  # l=4
  self.coeffs[3,0] = 1.2316;
  self.coeffs[3,1] = -0.1041;
  self.coeffs[3,2] = 0.0206;
  self.coeffs[3,3] = -0.0035;

  # l=5
  self.coeffs[4,0] = 1.2463;
  self.coeffs[4,1] = -0.1163;
  self.coeffs[4,2] = 0.0290;
  self.coeffs[4,3] = -0.0080;
  self.coeffs[4,4] = 0.0018;

  # l=6
  self.coeffs[5,0] = 1.2542;
  self.coeffs[5,1] = -0.1213;
  self.coeffs[5,2] = 0.0344;
  self.coeffs[5,3] = -0.017;
  self.coeffs[5,4] = 0.0038;
  self.coeffs[5,5] = -0.0011;

  # l=7
  self.coeffs[6,0] = 1.2593;
  self.coeffs[6,1] = -0.1280;
  self.coeffs[6,2] = 0.0384;
  self.coeffs[6,3] = -0.0147;
  self.coeffs[6,4] = 0.0059;
  self.coeffs[6,5] = -0.0022;
  self.coeffs[6,6] = 0.0007;

  # l=8
  self.coeffs[7,0] = 1.2626;
  self.coeffs[7,1] = -0.1312;
  self.coeffs[7,2] = 0.0412;
  self.coeffs[7,3] = -0.0170;
  self.coeffs[7,4] = 0.0076;
  self.coeffs[7,5] = -0.0034;
  self.coeffs[7,6] = 0.0014;
  self.coeffs[7,7] = -0.0005;


  for k in range(0,l) :
# for(k=0;k<l;k=k+1)
    self.w[k] = self.coeffs[l-1,k];

  ''' Dxminus computes the backward derivative in the x-direction.
  
      Parameters:
               A  :  Input 2D array
               dx :  Sampling interval
               dA :  Output array                

      The output array, dA, contains the derivative for each point computed
      as:
      dA[i,j] = (1/dx) sum_{k=1}^l w[k](A[i+(k-1)dx,j]-A[(i-kdx,j]

      w[k] are weights and l is the length of the differentiator.
      (see constructor for the definitions of these)
  '''

  def Dxminus(self, A, dA, dx) :
    nx = A.shape[0];
    ny = A.shape[1];

    # 
    # Left border 
    # 

    l = self.l;
    w = self.w;

    # parallel(i=0:l,j=0:ny)
    for i in range(0,l) :
      for j in range(0,ny) :
        sum=0.0;
      #for(k=1; k<i+1; k=k+1){
      for k in range (1,i+1) :
        sum = -w[k-1]*A[i-k,j] + sum; 
      #for(k=1; k<l+1; k=k+1){
       for k in range(0,l+1) :
         sum = w[k-1]*A[i+(k-1),j] +sum; 
      dA[i,j] = sum/dx;

  # Outside border area 
    
  #parallel(i=l:nx-l,j=0:ny)
  for i in range(l,nx-l) :
    for j in range(0,ny) :
   
      sum=0.0;
     #for(k=1; k<l+1; k=k+1){
      for j in range(1,l+1) :
        sum = w[k-1]*(-A[i-k,j]+A[i+(k-1),j]) +sum; 
      dA[i,j] = sum/dx;
    
  # Right border 

  #parallel(i=nx-l:nx,j=0:ny)
  for i in range(nx-l,nx) :
    for j in range(0,ny) :
      sum = 0.0;
      #for(k=1; k<l+1; k=k+1){
      for(k in range(1,l+1):
        sum = -w[k-1]*A[i-k,j] + sum;

      #for(k=1; k<(nx-i+1); k=k+1){
      for(k in range(1,nx-i+1):
        sum = w[k-1]*A[i+(k-1),j] + sum;

    dA[i,j] = sum/dx;

// Dxplus computes the forward derivative in the x-direction.
//
// Arguments:
//  Diff: Diff object 
//  float  A       : Input 2D array
//  float dx       : Sampling interval
//  float dA       : Output array 
//
//  The output array, dA, contains the derivative for each point computed
//  as:
//  dA[i,j] = (1/dx) sum_{k=1}^l w[k](A[i+kdx,j]-A[(i-(k-1)dx,j]
//
//  w[k] are weights and l is the length of the differentiator.
//  (see DiffNew for the definitions of these)
//------------------------------------------------------------------------------
int DiffDxplus(struct diff Diff, float [*,*] A, float [*,*] dA, float dx){
  int nx, ny;
  int i,j,k;
  float sum;
  int l;
  float [*] w;

  nx = len(A,0);
  ny = len(A,1);

  //
  // Left border (1 <i < l+1)
  //

  l= Diff.l;
  w = Diff.w;

  // Left border

  parallel(i=0:l,j=0:ny)
  {
    sum=0.0;
    for(k=1; k<i+2; k=k+1){
      sum = -w[k-1]*A[i-(k-1),j] + sum; 
    }
    for(k=1; k<l+1; k=k+1){
      sum = w[k-1]*A[i+k,j] +sum; 
    }
    dA[i,j] = sum/dx;
  } 
  //
  // Between left and right border
  //
  parallel(i=l:nx-l,j=0:ny)
  {
    sum=0.0;
    for(k=1; k<l+1; k=k+1){
      sum = w[k-1]*(-A[i-(k-1),j]+A[i+k,j]) +sum; 
    }
    dA[i,j] = sum/dx;
  } 

  //
  // Right border 
  //
  parallel(i=nx-l:nx,j=0:ny)
  {
    sum = 0.0;
    for(k=1; k<l+1; k=k+1){
      sum = -w[k-1]*A[i-(k-1),j] + sum;
    }

    for(k=1; k<nx-i; k=k+1){
      sum = w[k-1]*A[i+k,j] + sum;
    }
    dA[i,j] = sum/dx;
  }
}
//------------------------------------------------------------------------------
// Dyminus computes the backward derivative in the y-direction
//
// Arguments:
//  Diff: Diff object 
//  float  A       : Input 2D array
//  float dx       : Sampling interval
//  float dA       : Output array 
//
//  The output array, dA, contains the derivative for each point computed
//  as:
//  dA[i,j] = (1/dx) sum_{k=1}^l w[k](A[i,j+(k-1)dx]-A[i,j-kdx,j]
//
//  w[k] are weights and l is the length of the differentiator.
//  (see DiffNew for the definitions of these)
//------------------------------------------------------------------------------
int DiffDyminus(struct diff Diff, float [*,*] A, float [*,*] dA, float dx){
  int nx, ny;
  int i,j,k;
  float sum;
  int l;
  float [*] w;

  nx = len(A,0);
  ny = len(A,1);

  //
  // Top border (1 <i < l+1)
  //

  l= Diff.l;
  w = Diff.w;

  // Left border 

  parallel(i=0:nx,j=0:l)
  {
    sum=0.0;
    for(k=1; k<j+1; k=k+1){
      sum = -w[k-1]*A[i,j-k] + sum; 
    }
    for(k=1; k<l+1; k=k+1){
      sum = w[k-1]*A[i,j+(k-1)] +sum; 
    }
    dA[i,j] = sum/dx;
  } 

  //
  // Outside border area 
  //
  parallel(i=0:nx,j=l:ny-l)
  {
    sum=0.0;
    for(k=1; k<l+1; k=k+1){
      sum = w[k-1]*(-A[i,j-k]+A[i,j+(k-1)]) +sum; 
    }
    dA[i,j] = sum/dx;
  } 

  //
  // Right border 
  //
  parallel(i=0:nx,j=ny-l:ny)
  {
    sum = 0.0;
    for(k=1; k<l+1; k=k+1){
      sum = -w[k-1]*A[i,j-k] + sum;
   }

    for(k=1; k<(ny-j+1); k=k+1){
      sum = w[k-1]*A[i,j+(k-1)] + sum;
    }
    dA[i,j] = sum/dx;
  }
}
// Dyplus computes the forward derivative in the x-direction
//
// Arguments:
//  Diff: Diff object 
//  float  A       : Input 2D array
//  float dx       : Sampling interval
//  float dA       : Output array 
//
//  The output array, dA, contains the derivative for each point computed
//  as:
//  dA[i,j] = (1/dx) sum_{k=1}^l w[k](A[i+kdx,j]-A[(i-(k-1)dx,j]
//
//  w[k] are weights and l is the length of the differentiator.
//  (see DiffNew for the definitions of these)
//------------------------------------------------------------------------------
int DiffDyplus(struct diff Diff, float [*,*] A, float [*,*] dA, float dx){
  int nx, ny;
  int i,j,k;
  float sum;
  int l;
  float [*] w;

  nx = len(A,0);
  ny = len(A,1);

  //
  // Left border (1 <i < l+1)
  //

  l= Diff.l;
  w = Diff.w;

  // Left border
  parallel(i=0:nx,j=0:l)
  {
    sum=0.0;
    for(k=1; k<j+2; k=k+1){
      sum = -w[k-1]*A[i,j-(k-1)] + sum; 
    }
    for(k=1; k<l+1; k=k+1){
      sum = w[k-1]*A[i,j+k] +sum; 
    }
    dA[i,j] = sum/dx;
  } 

  //
  // Between left and right border
  //
  parallel(i=0:nx,j=l:ny-l)
  {
    sum=0.0;
    for(k=1; k<l+1; k=k+1){
      sum = w[k-1]*(-A[i,j-(k-1)]+A[i,j+k]) +sum; 
    }
    dA[i,j] = sum/dx;
  } 

  //
  // Right border 
  //
  parallel(i=0:nx,j=ny-l:ny)
  {
    sum = 0.0;
    for(k=1; k<l+1; k=k+1){
      sum = -w[k-1]*A[i,j-(k-1)] + sum;
    }

    for(k=1; k<ny-j; k=k+1){
      sum = w[k-1]*A[i,j+k] + sum;
    }
    dA[i,j] = sum/dx;
  }
}
