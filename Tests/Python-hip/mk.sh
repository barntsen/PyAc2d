#!/bin/sh

# Test script for PyAc2d. 

./clean.sh

#Create wavelet
nt=1501 #No of samples
ricker -nt $nt -f0 25.0 -t0 0.150 -dt 0.0005 src.bin 

n1=251
n2=251
#Create vp
spike -n1 $n1 -n2 $n2 -val 2500.0 vp.bin

#Create rho 
spike -n1 $n1 -n2 $n2 -val 1000.0 rho.bin

#Create Q 
spike -n1 $n1 -n2 $n2 -val 100000.0 q.bin

#Run modelling
BIN=../../Bin
export PYTHONPATH=$PYTHONPATH:/users/boarntse/Src/PyAc2d/Tests/Python-hip
$BIN/ac2dmod -m hip mod.py

#Display snapshots
#../../Scripts/snp.sh
