#!/usr/bin/python3
''' ac2dmod is a script for 2D acoustic modeling

  Arguments:
    fname : Input configuration file

'''

import time
from datetime import datetime
import importlib
import numpy as np
import babin as ba
import time
import argparse
import sys

#Get configuration file name
parser = argparse.ArgumentParser(description='ac2dmod - 2D acoustic modeling')
parser.add_argument('fname',help='Configuartion file name')
parser.add_argument("-m",dest="m",default='gpu', help="either of cpu,gpu or omp ")
args = parser.parse_args()

print("** ac2dmod ", args.m, "version **",flush=True)

#Get pyeps library
if args.m == 'cpu' :
  module1 = 'pyac2dcpu'
  module2 = 'pyepscpu'
elif args.m == 'gpu':
  module1 = 'pyac2dcu'
  module2 = 'pyepscu'
elif args.m == 'omp':
  module1 = 'pyac2domp'
  module2 = 'pyepsomp'
elif args.m == 'hip':
  module1 = 'pyac2dhip'
  module2 = 'pyepship'
  
pyac2d=importlib.import_module(module1, package=None)
pyeps=importlib.import_module(module2, package=None)

#Get configuration file 
if args.fname is not None :
  tmp=args.fname
  module = tmp.split('.')[0]
  par=importlib.import_module(module, package=None)
else :
  sys.exit("No cfg file name")
  

#Initialize I/O
pyac2d.LibeInit()

t0=time.perf_counter()   #Start measure wall clock time
#----------------------------------------------
#Create source 
#----------------------------------------------
#Get the wavelet
fin = ba.bin(par.fsrc)
data=fin.read((par.nt))
sxx = pyeps.PyepsStore1di(par.sx)       #Convert numpy integer array to c-type
syy = pyeps.PyepsStore1di(par.sy)       #Convert numpy integer array to c-type
wavelet = pyeps.PyepsStore1df(data) #Convert numpy float array to c-type   
#Create source object
src=pyac2d.SrcNew(wavelet,sxx,syy)
#----------------------------------------------
#Create receivers 
#----------------------------------------------
rxx = pyeps.PyepsStore1di(par.rx)  #Convert numpy integer array to c-type
ryy = pyeps.PyepsStore1di(par.ry)  #Convert numpy integer array to c-type
snp = pyeps.PyepsStore1ds(par.fsnp) #Convert python string to c-type
#Create receiver object
rec= pyac2d.RecNew(rxx,ryy,par.nt,par.resamp,par.sresamp,snp);
#----------------------------------------
# Create model
#----------------------------------------
#Get the velocity model
fin = ba.bin(par.fvp)
data=fin.read((par.ny,par.nx))
#Convert 2d numpy float array to c-type
vp=pyeps.PyepsStore2df(data);

#Get the density model
fin = ba.bin(par.frho)
data=fin.read((par.ny,par.nx))
#Convert 2d numpy float array to c-type
rho=pyeps.PyepsStore2df(data);

#Get the Q model
fin = ba.bin(par.fq)
data=fin.read((par.ny,par.nx))
#Convert 2d numpy float array to c-type
q=pyeps.PyepsStore2df(data);

#Create a new model
t1=time.perf_counter()
model=pyac2d.ModelNew (vp,rho,q,par.dx,par.dt,par.w0,par.nb,par.rheol)
print("model time  (secs):", time.perf_counter()-t1, flush=True)
#--------------------------------------
#Create fd solver
#--------------------------------------
#Create solver object
ac2d = pyac2d.Ac2dNew(model)

#--------------------------------------
#Run solver
#--------------------------------------
t1=time.perf_counter()
pyac2d.Ac2dSolve(ac2d,model,src,rec,par.nt,par.l)

#--------------------------------
# Log wall clock time and date
#-------------------------------
now = datetime.now()
dtstring = now.strftime("%b-%d-%Y %H:%M:%S")
print("date              :",dtstring)
print("grid size      nx :", par.nx)  
print("grid size      ny :", par.ny)  
print("timesteps    nt   :", par.nt)  
print("solver time (secs):", time.perf_counter()-t1)
print("wall time (secs)  :", time.perf_counter()-t0)
#--------------------------------------
#Save Recording
#--------------------------------------
fp  = par.press   # Output file name for pressure recording
p=pyeps.PyepsStore1ds(fp)
pyac2d.RecSave(rec,p)
