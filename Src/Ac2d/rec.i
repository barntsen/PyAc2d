//-----------------------------------------------------------------
// rec is the receiver object
//-----------------------------------------------------------------

struct rec 
{
    int nr; // No of receivers
    int [*] rx;    // Receiver x-postions
    int [*] ry;    // Receiver y-postions 
    int fd;        // Snapshot output file descriptor
    int nt;        // No of time samples
    float [*,*] p; // Pressure p[i,j] time sample no j at
                   // position no i 
    float [*,*] wrk; // Work array
    int   resamp;  // Resample factor for receivers
    int   sresamp; // Resample factor for snapshots
    int pit;       // Next time sample to be recorded
}

//
// RecNew is the constructor for receivers.
// The return value is a Rec object
//
struct rec RecNew(int [*] rx, int [*] ry, int nt, int resamp, int sresamp,
                  char[*] file){}
//
// RecReciver records data at the receivers
//
int RecReceiver(struct rec Rec,int it, float [*,*] p){}
//
// Recsave stores receiver recording on file
//
int RecSave(struct rec Rec, char [*] file){}
//
// RecSnap records snapshots
//
int RecSnap(struct rec Rec,int it, float [*,*] snp){}

