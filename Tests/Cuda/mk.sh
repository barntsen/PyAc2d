#!/bin/sh

cp ../../Ac2d/libac2dcuda.o .
cp ../../Ac2d/*.i .
#cp ../../Ac2d/ac2dmod.e .

ecc ac2dmod.e
elc -o ac2dmod ac2dmod.o libac2dcuda.o 

#Create wavelet
nt=1001 #No of samples
ricker -nt $nt -f0 30.0 -t0 0.100 -dt 0.0005 src.bin 

n1=1001
n2=1001
#Create vp
spike -n1 $n1 -n2 $n2 -val 2500.0 vp.bin

#Create rho 
spike -n1 $n1 -n2 $n2 -val 1000.0 rho.bin

#Create Q 
spike -n1 $n1 -n2 $n2 -val 100000.0 q.bin

#Run modelling
#./ac2dmod 

#../../Scripts/snp.sh




