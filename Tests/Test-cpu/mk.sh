#!/bin/sh

./clean.sh

#Copy in python module c shared lib
cp ../../Src/Python-cpu/_fd2d.so .

#Create wavelet
nt=1501 #No of samples
ricker -nt $nt -f0 25.0 -t0 0.100 -dt 0.0005 src.bin 

n1=501
n2=501
#Create vp
spike -n1 $n1 -n2 $n2 -val 2500.0 vp.bin

#Create rho 
spike -n1 $n1 -n2 $n2 -val 1000.0 rho.bin

#Create Q 
spike -n1 $n1 -n2 $n2 -val 100000.0 q.bin

#Run modelling
python3 ac2dmod.py



