import numpy as np
from pyac2domp import *

def PyepsStore2df(arr):
  nx = arr.shape[0]
  ny = arr.shape[1]
  out = PyepsCre2df(nx,ny) 

  for i in range(0,ny):
    for j in range(0,nx):
      PyepsSet2df(out,j,i,float(arr[i,j]))

  return(out)

def PyepsStore1df(arr):
  nx = arr.shape[0]
  out = PyepsCre1df(nx) 
  for i in range(0,nx):
    PyepsSet1df(out,i,float(arr[i]))

  return(out)

def PyepsStore1di(arr):
  nx = arr.shape[0]
  out = PyepsCre1di(nx) 
  for i in range(0,nx):
    PyepsSet1di(out,i,int(arr[i]))

  return(out)

def PyepsStore1ds(arr):
  nx = len(arr)
  out = PyepsCre1ds(nx) 

  for i in range(0,nx):
    PyepsSet1ds(out,i,arr[i])
  
  return(out)
