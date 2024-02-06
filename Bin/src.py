import pyeps
import babin as ba
import pyeps


class src :

  def __init__(self,pyac2d,par):
    fin = ba.bin(par.fsrc)
    data=fin.read((par.nt))
    sxx = pyeps.PyepsStore1di(pyac2d,par.sx)       #Convert numpy integer array to c-type
    syy = pyeps.PyepsStore1di(pyac2d,par.sy)       #Convert numpy integer array to c-type
    wavelet = pyeps.PyepsStore1df(pyac2d,data)     #Convert numpy float array to c-type
    #Create source object
    self.src=pyac2d.SrcNew(wavelet,sxx,syy) 
