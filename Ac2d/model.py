from ctypes import *
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
    pyac2d.ModelNew.restype=c_void_p
    #Get the velocity model
    fin = ba.bin(par.fvp)
    data=fin.read((par.ny,par.nx))
    #Convert 2d numpy float array to eps
    vp=pyeps.Store2df(pyac2d,data);

    #Get the density model
    fin = ba.bin(par.frho)
    data=fin.read((par.ny,par.nx))
    #Convert 2d numpy float array to eps
    rho=pyeps.Store2df(pyac2d,data);

    #Get the Q model
    fin = ba.bin(par.fq)
    data=fin.read((par.ny,par.nx))
    #Convert 2d numpy float array to eps
    q=pyeps.Store2df(pyac2d,data);

    #Create a new model
    # Set argument types
    pyac2d.ModelNew.argtypes=  [c_void_p,c_void_p,c_void_p,c_float,c_float,
                                c_float,c_int,c_int]
    self.model=pyac2d.ModelNew (vp,rho,q,c_float(par.dx),c_float(par.dt),
                                c_float(par.w0),c_int(par.nb),c_int(par.rheol))
