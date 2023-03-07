#!/bin/sh

# Test script for PyAc2d. To run all tests,
# remove the exit command after model 1.

./clean.sh

#Copy in python module c shared lib
cp ../../Python-omp/_fd2d.so .
#Copy in python module 
cp ../../Python-cpu/fd2d.py .
cp ../../Python-cpu/pyeps.py .

#Create wavelet
nt=1501 #No of samples
ricker -nt $nt -f0 25.0 -t0 0.100 -dt 0.0005 src.bin 

n1=251
n2=251
#Create vp
spike -n1 $n1 -n2 $n2 -val 2500.0 vp.bin

#Create rho 
spike -n1 $n1 -n2 $n2 -val 1000.0 rho.bin

#Create Q 
spike -n1 $n1 -n2 $n2 -val 100000.0 q.bin

#Run modelling
echo "** Model size 251x251 Timesteps 1501" > log.txt
python3 ../Scripts/ac2dmod.py  > log.txt

#Show snapshots
../Scripts/snp.sh
