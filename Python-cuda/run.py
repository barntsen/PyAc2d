
import numpy as np
from fd2d import *
from pyeps import *
import babin as ba


#Initialize I/O
LibeInit()
pi=3.14159   #Pi

#------------------------------
#Set all modeling parameters
#------------------------------
nx      = 201       #No of grdipoints in x-direction
ny      = 201       #No of gridpoints in y-direction
dx      = 5.0       #Grid interval
dt      = 0.0005;   #Time sampling interval
nt      = 801       #No of time steps
t0      = 0.1       #Pulse delay
f0      = 20.0      #Dominant frequency 
w0      = 2.0*pi*f0 #Dominant angular frequency
resamp  = 1         #Resampling factor (relative to no of timesteps ) for data
sresamp = 10        #Resampling factor for snapshots
nb      = 35        #No of PML boundary points
l       = 4         #Length of differentiator
fvp     = "vp.bin"  # Vp file name
frho    = "rho.bin" # Rho file name
fq      = "q.bin"   # Q file name
fsrc    = "src.bin" # Wavelet file name
fsnp    = "snp.bin" # Snapshot file name
fp      = "p.bin"   # Output file name for pressure recording
MAXWELL = 1         # Maxwell Q-model
SLS     = 2         # Standard Linear Solid Q-model
#----------------------------------------------
#Create source positions and source wavelet
#----------------------------------------------
#Get the wavelet
fin = ba.bin(fsrc)
data=fin.read((nt))
x=np.zeros(1)
y=np.zeros(1)
x[0]=nx/2
y[0]=ny/2
sx = PyepsStore1di(x) #Convert numpy integer array to c-type
sy = PyepsStore1di(y) #Convert numpy integer array to c-type
wavelet = PyepsStore1df(data) #Convert numpy float array to c-type

#Create source object
src=SrcNew(wavelet,sx,sy)
#----------------------------------------------
#Create receiver positions
#----------------------------------------------
nr = 201  
x=np.zeros((nr))
y=np.zeros((nr))
for i in range(0,nr):
  x[i] = i
  y[i] = 10

rx = PyepsStore1di(x)    #Convert numpy integer array to c-type
ry = PyepsStore1di(y)    #Convert numpy integer array to c-type
snp= PyepsStore1ds(fsnp) #Convert python string to c-type

#Create receiver object
rec= RecNew(rx,ry,nr,resamp,sresamp,snp);

#----------------------------------------
# Create model
#----------------------------------------
#Get the velocity model
fin = ba.bin(fvp)
data=fin.read((ny,nx))
#Convert 2d numpy float array to c-type
vp=PyepsStore2df(data);

#Get the density model
fin = ba.bin(frho)
data=fin.read((ny,nx))
#Convert 2d numpy float array to c-type
rho=PyepsStore2df(data);

#Get the Q model
fin = ba.bin("q.bin")
data=fin.read((ny,nx))
#Convert 2d numpy float array to c-type
q=PyepsStore2df(data);

#Create a new model
rheol=MAXWELL
model=ModelNew (vp,rho,q,dx,dt,w0,nb,rheol)
      
#--------------------------------------
#Create fd solver
#--------------------------------------
#Create solver object
ac2d = Ac2dNew(model)

#--------------------------------------
#Run solver
#--------------------------------------
Ac2dSolve(ac2d,model,src,rec,nt,l)

#--------------------------------------
#Save Recording
#--------------------------------------
p=PyepsStore1ds(fp)
RecSave(rec,p)
