// Ac2D is the acoustic modeling object
//=====================================

struct ac2d {
  float [*,*] p0;
  float [*,*] p1;
  float [*,*] p2;
  float [*,*] ax;
  float [*,*] ay;
  float [*,*] ex;
  float [*,*] ey;
  float [*,*] gammasx;
  float [*,*] gammasy;
  float [*,*] gammax;
  float [*,*] gammay;
  int ts;             // Timestep no
}

// Ac2dNew creates a new Ac2d object
//
  struct ac2d Ac2dNew(struct model Model){}

// Ac2dSolve computes the pressure at the next timestep
//
   int Ac2dSolve(struct ac2d Ac2d, struct model Model,struct src Src, 
                 struct rec Rec,int nt, int l){}
