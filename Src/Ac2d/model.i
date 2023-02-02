// Model is the model object.
struct model {
int Nx,Ny;
int Nb;
float W0;
float [*,*] Kappa;
float [*,*] Dkappax;
float [*,*] Dkappay;
float [*,*] Dsx;
float [*,*] Dsy;
float [*,*] Rho;
float [*,*] Q;
float [*,*] Tauex;
float [*,*] Tausx;
float [*,*] Tauey;
float [*,*] Tausy;
float [*,*] Alpha1x;
float [*,*] Alpha1y;
float [*,*] Alpha2x;
float [*,*] Alpha2y;
float Dx;
float Dt;

}
// Methods for the model object

// ModelNew creates a new Model obejct
struct model ModelNew(float [*,*] kappa, float [*,*] rho, float [*,*] Q,
                      float Dx, float Dt, float W0, int Nb){}

// ModelStability computes stability index
float ModelStability(struct model Model){}

