/* smodel.i */
 %module fd2d
 %{
 /* Put header files here or function declarations like below */

  typedef struct nctempchar1 { int d[1]; char *a;} nctempchar1;
  typedef struct nctempint1 { int d[1]; int *a;} nctempint1;
  typedef struct nctempfloat1 { int d[1]; float *a;} nctempfloat1;
  typedef struct nctempfloat2 { int d[2]; float *a;} nctempfloat2;

  struct model {
    int Nx,Ny;
    int Nb;
    float W0;
    nctempfloat2 *Kappa;
    nctempfloat2 *Dkappa;
    nctempfloat2 *Dkappay;
    nctempfloat2 *Dsx;
    nctempfloat2 *Dsy;
    nctempfloat2 *Rho;
    nctempfloat2 *Q;
    nctempfloat2 *Tauex;
    nctempfloat2 *Tausx;
    nctempfloat2 *Tauey;
    nctempfloat2 *Tausy;
    nctempfloat2 *Alpha1x;
    nctempfloat2 *Alpha1y;
    nctempfloat2 *Alpha2x;
    nctempfloat2 *Alpha2y;
    float Dx;
    float Dt;
  };

  struct src
  {
    nctempfloat1 *Src;
    nctempint1   *Sx;
    nctempint1    *Sy;
    int Ns;
  };

  struct rec
  {
    int nr;
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

  struct ac2d 
{
  nctempfloat2 *p0;
  nctempfloat2 *p1;
  nctempfloat2 *p2;
  nctempfloat2 *ax;
  nctempfloat2 *ay;
  nctempfloat2 *ex;
  nctempfloat2 *ey;
  nctempfloat2 *gammasx;
  nctempfloat2 *gammasy;
  nctempfloat2 *gammax;
  nctempfloat2 *gammay;
};

  int LibeInit();

  void *GpuNew(int n);
  void *GpuDelete(void *f);
  void *GpuError();

  nctempchar1* PyepsCre1ds (int Nx);
  int PyepsDel1ds (nctempchar1 *arr);
  nctempchar1* PyepsSet1ds (nctempchar1 *arr,int i, char val);

  nctempint1* PyepsCre1di (int Nx);
  int PyepsDel1di (nctempint1 *arr);
  nctempint1* PyepsSet1di (nctempint1 *arr,int i,int val);

  nctempfloat1* PyepsCre1df (int Nx);
  int PyepsDel1df (nctempfloat1 *arr);
  nctempfloat1* PyepsSet1df (nctempfloat1 *arr,int i,float val);

  nctempfloat2* PyepsCre2df (int Nx,int Ny);
  int PyepsDel2df (nctempfloat2 *arr);
  nctempfloat2* PyepsSet2df (nctempfloat2 *arr,int i,int j,float val);

  struct model* ModelNew (nctempfloat2 *kappa,nctempfloat2 *rho,
                          nctempfloat2 *Q,float Dx,float Dt,float W0,int Nb);
  
  struct src *SrcNew(nctempfloat1 *source, nctempint1 *sx, nctempint1 *sy);

  struct rec *RecNew(nctempint1 *rx, nctempint1 *ry, int nt, int resamp, 
                    int sresamp, nctempchar1 *file);
  int RecSave(struct rec *Rec, nctempchar1 *file);

 struct ac2d * Ac2dNew(struct model * Model); 
 int Ac2dSolve(struct ac2d* Ac2d, struct model* Model, struct src* Src, 
                struct rec* Rec, int nt, int l);

 %}
  
  int LibeInit();

  void *GpuNew(int n);
  void *GpuDelete(void *f);
  void *GpuError();

  nctempchar1* PyepsCre1ds (int Nx);
  int PyepsDel1ds (nctempchar1 *arr);
  nctempchar1* PyepsSet1ds (nctempchar1 *arr,int i, char val);

  nctempint1* PyepsCre1di (int Nx);
  int PyepsDel1di (nctempint1 *arr);
  nctempint1* PyepsSet1di (nctempint1 *arr,int i,int val);

  nctempfloat1* PyepsCre1df (int Nx);
  int PyepsDel1df (nctempfloat1 *arr);
  nctempfloat1* PyepsSet1df (nctempfloat1 *arr,int i,float val);

  nctempfloat2* PyepsCre2df (int Nx,int Ny);
  int PyepsDel2df (nctempfloat2 *arr);
  nctempfloat2* PyepsSet2df (nctempfloat2 *arr,int i,int j,float val);

  struct model* ModelNew (nctempfloat2 *kappa,nctempfloat2 *rho,
                          nctempfloat2 *Q,float Dx,float Dt,float W0,int Nb);

  struct src * SrcNew(nctempfloat1 *source, nctempint1 *sx, nctempint1 *sy);

  struct rec * RecNew(nctempint1 *rx, nctempint1 *ry, int nt, int resamp, 
                    int sresamp, nctempchar1 *file);
  int RecSave(struct rec *Rec, nctempchar1 *file);

  struct ac2d * Ac2dNew(struct model * Model); 
  int Ac2dSolve(struct ac2d* Ac2d, struct model* Model, struct src* Src, 
                struct rec* Rec, int nt, int l);
