#!/bin/sh


# Test script for pyac2domp 

./clean.sh

#Create wavelet
nt=1501 #No of samples
ricker -nt $nt -f0 25.0 -t0 0.100 -dt 0.0005 src.bin 

n1=256
n2=256
#Create vp
spike -n1 $n1 -n2 $n2 -val 2500.0 vp.bin

#Create rho 
spike -n1 $n1 -n2 $n2 -val 1000.0 rho.bin

#Create Qp 
spike -n1 $n1 -n2 $n2 -val 100000.0 qp.bin

#Create Qr 
spike -n1 $n1 -n2 $n2 -val 100000.0 qr.bin

#Run modelling
BIN=../../Bin
export OMP_NUM_THREADS=6
$BIN/ac2dmod -m omp mod.py


#Show snapshots
#../../Scripts/snp.sh
