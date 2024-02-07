import pyeps
import babin as ba
import pyeps


class rec :

  def __init__(self,pyac2d,par):
    rxx = pyeps.PyepsStore1di(pyac2d,par.rx)  
    ryy = pyeps.PyepsStore1di(pyac2d,par.ry)  
    snp = pyeps.PyepsStore1ds(pyac2d,par.fsnp) 
    #Create receiver object
    self.rec= pyac2d.RecNew(rxx,ryy,par.nt,par.resamp,par.sresamp,snp);

  def save(self,pyac2d,par):
    fname  = par.press   # Output file name for pressure recording
    fp=pyeps.PyepsStore1ds(pyac2d,fname)
    pyac2d.RecSave(self.rec,fp)
