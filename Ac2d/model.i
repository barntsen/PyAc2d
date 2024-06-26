// Model is the model object.
struct model {
int Nx,Ny;
int Nb;
float W0;
float [*,*] Qp;
float [*,*] Qr;
float [*,*] Kappa;
float [*,*] Dkappax;
float [*,*] Dkappay;
float [*,*] Drhox;
float [*,*] Drhoy;
float [*,*] Rho;
float [*,*] Alpha1x;
float [*,*] Alpha1y;
float [*,*] Alpha2x;
float [*,*] Alpha2y;
float [*,*] Eta1x;
float [*,*] Eta1y;
float [*,*] Eta2x;
float [*,*] Eta2y;
float [*] dx;
float [*] dy;
float Dx;
float Dt;

}
// Methods for the model object

// ModelNew creates a new Model obejct
struct model ModelNew(float [*,*] kappa, float [*,*] rho, float [*,*] Qp, float [*,*] Qr,
                      float Dx, float Dt, float W0, int Nb, int Rheol){}

// ModelStability computes stability index
float ModelStability(struct model Model){}

// Constants
const MAXWELL = 1;
const SLS     = 2;
const MAXWELLR = 3;
