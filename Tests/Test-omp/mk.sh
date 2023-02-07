#!/bin/sh

./clean.sh

#Copy in python module c shared lib
cp ../../Src/Python-omp/_fd2d.so .

#Create wavelet
./wavelet.sh

n1=201
n2=201
#Create vp
spike -n1 $n1 -n2 $n2 -val 2500.0 vp.bin

#Create rho 
spike -n1 $n1 -n2 $n2 -val 1000.0 rho.bin

#Create Q 
spike -n1 $n1 -n2 $n2 -val 100000.0 q.bin

#Run modelling
export OMP_NUM_THREADS=4
time python3 ac2dmod.py



