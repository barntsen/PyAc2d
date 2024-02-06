import pyeps
import babin as ba
import pyeps


class model :
  ''' model creates a model suitable for the pyac2d library 
      solver.

     Parameters: 
       pyac2d  : Reference to the pyac2d wave propagation
                 library.

     Returns   : model object.       

  '''

  def __init__(self,pyac2d,par):
    #Get the velocity model
    fin = ba.bin(par.fvp)
    data=fin.read((par.ny,par.nx))
    #Convert 2d numpy float array to eps
    vp=pyeps.PyepsStore2df(pyac2d,data);

    #Get the density model
    fin = ba.bin(par.frho)
    data=fin.read((par.ny,par.nx))
    #Convert 2d numpy float array to eps
    rho=pyeps.PyepsStore2df(pyac2d,data);

    #Get the Q model
    fin = ba.bin(par.fq)
    data=fin.read((par.ny,par.nx))
    #Convert 2d numpy float array to eps
    q=pyeps.PyepsStore2df(pyac2d,data);

    #Create a new model
    self.model=pyac2d.ModelNew (vp,rho,q,par.dx,par.dt,par.w0,par.nb,par.rheol)
