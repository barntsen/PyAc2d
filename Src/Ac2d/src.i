// Src is the source object
struct src 
{ 
  float [*] Src;
  int [*] Sx;
  int [*] Sy;
  int Ns;
}
// SrcNew creates a new source object
struct src SrcNew(float [*] source, int [*] sx, int [*] sy){}

// SrcDel deletes a source object
int SrcDel(struct src Src){}
