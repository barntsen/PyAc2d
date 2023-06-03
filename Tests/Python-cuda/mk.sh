#!/bin/sh

# Test script for PyAc2d. 

./clean.sh

#Create wavelet
nt=1501 #No of samples
ricker -nt $nt -f0 30.0 -t0 0.100 -dt 0.0005 src.bin 

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
$BIN/ac2dmod -m gpu mod.py 

../../Scripts/snp.sh

