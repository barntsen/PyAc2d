import pyeps       # Python interface for functions 
                   # contained in pyeps.e
import babin as ba # File manipulation


class src :
   ''' src is a class for reading a source wavelet 
       and creating the source geometry 

       Parameters:
         pyac2d : Pointer to the pyac2d module 
         par    : Object containing modelling parameters
                  set in the configuration (mod.py) file.

       Returns  : Source object
  
       The pyac2d module is implemented in eps
       and contains all essential wave propagation methods.
   '''

  def __init__(self,pyac2d,par):
    # Read the source time function
    fin = ba.bin(par.fsrc)  
    data=fin.read((par.nt))
    
    # Convert python variables to eps variables
    sxx = pyeps.PyepsStore1di(pyac2d,par.sx)
    syy = pyeps.PyepsStore1di(pyac2d,par.sy)
    wavelet = pyeps.PyepsStore1df(pyac2d,data)

    #Create source eps object
    self.src=pyac2d.SrcNew(wavelet,sxx,syy) 
