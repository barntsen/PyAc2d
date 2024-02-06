import pyeps
import babin as ba
import pyeps


class ac2d :
  ''' ac2d is a  class for solving the acoustic 
      wave equation.  
     
     Parameters: 
       pyac2d  : Reference to the pyac2d wave propagation
                 library.

     Returns   : ac2d object.

  '''


  def __init__(self,pyac2d,model):

    #Create fd solver
    m = model.model
    self.ac2d = pyac2d.Ac2dNew(m)
  
  def solve(self, pyac2d,model,src,rec,par) :
    ''' solve computes the solution for the acoustic 
        wave equation.

        Parameters : 
          pyac2d   : Reference to the pyac2d eps library.
          model    : model object.
          src      : src object.
          rec      : rec object.
          par      : parameter object set by the configuartion file.

    '''
    # Run the pyac2d solver.
    m=model.model
    pyac2d.Ac2dSolve(self.ac2d,m,src.src,rec.rec,par.nt,par.l)

