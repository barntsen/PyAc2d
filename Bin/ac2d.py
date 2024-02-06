import pyeps
import babin as ba
import pyeps


class ac2d :

  def __init__(self,pyac2d,model):

    #Create fd solver
    m = model.model
    self.ac2d = pyac2d.Ac2dNew(m)
  
  def solve(self, pyac2d,model,src,rec,par) :

    m=model.model
    pyac2d.Ac2dSolve(self.ac2d,m,src.src,rec.rec,par.nt,par.l)

