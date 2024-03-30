#!/bin/sh
# mk.sh is a test script for PyAc2d. 

#./clean.sh

window -n1 5401 -n2 251 -f1 0 -l1 1201 vp-orig.bin vp.bin
window -n1 5401 -n2 251 -f1 0 -l1 1201 rho-orig.bin rho.bin

#Create wavelet
nt=20001 #No of samples
ricker -nt $nt -f0 2.0 -t0 0.700 -dt 0.001 src.bin 
graph -noshow -ar 2.5 -o src.pdf -n1 2001 -d1 0.001 src.bin \
      -xlabel "Time (sec)" \
      -ylabel "Amplitude"

n1=1201
n2=251
#Create Q 
spike -n1 $n1 -n2 $n2 -val 100000.0 q.bin

#Run modelling
BIN=../Bin
export NTHREADS=1024
export NBLOCKS=1024
#$BIN/ac2dmod -m gpu mod.py > log.txt 

