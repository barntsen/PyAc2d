import numpy as np
#from pyac2dcpu import *

def PyepsStore2df(pyac2d,arr):
  nx = arr.shape[0]
  ny = arr.shape[1]
  out = pyac2d.PyepsCre2df(ny,nx) 

  for i in range(0,nx):
    for j in range(0,ny):
      pyac2d.PyepsSet2df(out,j,i,float(arr[i,j]))

  return(out)

def PyepsStore1df(pyac2d,arr):
  nx = arr.shape[0]
  out = pyac2d.PyepsCre1df(nx) 
  for i in range(0,nx):
    pyac2d.PyepsSet1df(out,i,float(arr[i]))

  return(out)

def PyepsStore1di(pyac2d,arr):
  nx = arr.shape[0]
  out = pyac2d.PyepsCre1di(nx) 
  for i in range(0,nx):
    pyac2d.PyepsSet1di(out,i,int(arr[i]))

  return(out)

def PyepsStore1ds(pyac2d,arr):
  nx = len(arr)
  out = pyac2d.PyepsCre1ds(nx) 

  for i in range(0,nx):
    pyac2d.PyepsSet1ds(out,i,arr[i])
  
  return(out)
