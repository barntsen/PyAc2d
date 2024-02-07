#!/bin/sh
# mk.sh is a test script for PyAc2d. 

#./clean.sh

window -n1 5401 -n2 251 -f1 0 -l1 1201 vp-orig.bin vp.bin
window -n1 5401 -n2 251 -f1 0 -l1 1201 rho-orig.bin rho.bin

#Create wavelet
nt=20001 #No of samples
ricker -nt $nt -f0 2.0 -t0 0.700 -dt 0.001 src.bin 
graph -noshow -o src.pdf -n1 1001 src.bin

n1=1201
n2=251
#Create Q 
spike -n1 $n1 -n2 $n2 -val 100000.0 q.bin

#Run modelling
BIN=../Bin
$BIN/ac2dmod -m cpu mod.py > log.txt 

