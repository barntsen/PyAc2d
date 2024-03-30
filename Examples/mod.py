import numpy as np
#------------------------------
# Modeling of OBS survey
#------------------------------
pi      = 3.14159
nx      = 1201      #No of grdipoints in x-direction
ny      = 251       #No of gridpoints in y-direction
dx      = 100.0     #Grid interval
dt      = 0.001;    #Time sampling interval
nt      = 20001     #No of time steps
t0      = 0.3       #Pulse delay
f0      = 20.0      #Dominant frequency 
w0      = 2.0*pi*f0 #Dominant angular frequency
resamp  = 1         #Resampling factor (relative to no of timesteps ) for data
sresamp = 50        #Resampling factor for snapshots
nb      = 35        #No of PML boundary points
l       = 8         #Length of differentiator
fvp     = "vp.bin"  # Vp file name
frho    = "rho.bin" # Rho file name
fq      = "q.bin"   # Q file name
fsrc    = "src.bin" # Wavelet file name
fsnp    = "snp.bin" # Snapshot file name
press   = "p.bin"   # Output data file
#Q-models
MAXWELL = 1
SLS     = 2
rheol   = SLS       #Use standard linear solid
#Source position
sx       = np.zeros(1) #Source x-coord
sy       = np.zeros(1) #Depth coord
sx[0]    = 40
sy[0]    = 35
#Receiver positions
nr = 1201
rx=np.zeros((nr))       #Receiver x-coord
ry=np.zeros((nr))       #Receiver depth
for i in range(0,nr):
  rx[i] = i
  ry[i] = 45
