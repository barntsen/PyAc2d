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

import src
import rec
import model
import ac2d
import pyeps

#Get configuration file name
parser = argparse.ArgumentParser(description='ac2dmod - 2D acoustic modeling')
parser.add_argument('fname',help='Configuartion file name')
parser.add_argument("-m",dest="m",default='gpu', 
                    help="either of cpu,gpu or omp ")
args = parser.parse_args()

print("** ac2dmod ", args.m, "version **",flush=True)

#Get pyeps library
if args.m == 'cpu' :
  module1 = 'pyac2dcpu'
elif args.m == 'gpu':
  module1 = 'pyac2dcu'
elif args.m == 'omp':
  module1 = 'pyac2domp'
  
pyac2d=importlib.import_module(module1, package=None)

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

# Create source 
src=src.src(pyac2d,par)

# Create receivers 
rec=rec.rec(pyac2d,par)

# Create model
model = model.model(pyac2d,par)
print("model time  (secs):", time.perf_counter()-t1, flush=True)

# Create fd solver
ac2d = ac2d.ac2d(pyac2d,model)

# Run solver
t1=time.perf_counter()
ac2d.solve(pyac2d,model,src,rec,par)

# Log wall clock time and date
now = datetime.now()
dtstring = now.strftime("%b-%d-%Y %H:%M:%S")
print("date              :",dtstring)
print("grid size      nx :", par.nx)  
print("grid size      ny :", par.ny)  
print("timesteps    nt   :", par.nt)  
print("solver time (secs):", time.perf_counter()-t1)
print("wall time (secs)  :", time.perf_counter()-t0)

# Save data
rec.save(pyac2d,par)
