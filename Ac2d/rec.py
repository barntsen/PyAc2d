import pyeps
import babin as ba


class rec :
   ''' rec is a class for creating receiver geometry from
       the variables in the configuration (mod.py) file

       Parameters :
         pyac2d   : Reference to the pyac2d eps wave
                    propagation library.    

         par      : Object with parameters set in the
                    configuration (mod.py) file.
       
       Returns    : Receiver object.
   '''

  def __init__(self,pyac2d,par):
    #Convert from python variables to eps variables
    rxx = pyeps.PyepsStore1di(pyac2d,par.rx)  
    ryy = pyeps.PyepsStore1di(pyac2d,par.ry)  
    snp = pyeps.PyepsStore1ds(pyac2d,par.fsnp) 
    #Create receiver eps object.
    self.rec= pyac2d.RecNew(rxx,ryy,par.nt,par.resamp,par.sresamp,snp);

  def save(self,pyac2d,par):
    ''' save records data to file.

        Parameters: 
          pyac2da :  Pointer to the eps pyac2d library.
          par     :  object with parameters set in the
                     configuration (mod.py) file.
 
          Returns :  None
    '''

    fname  = par.press   # Output file name for pressure recording
    fp=pyeps.PyepsStore1ds(pyac2d,fname)
    pyac2d.RecSave(self.rec,fp)
