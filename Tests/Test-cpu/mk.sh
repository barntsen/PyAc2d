#!/bin/sh

./clean.sh

#Copy in python module c shared lib
cp ../../Src/Python-cpu/_fd2d.so .

#Create wavelet
nt=1501 #No of samples
ricker -nt $nt -f0 25.0 -t0 0.100 -dt 0.0005 src.bin 

#-----------------------------------------
# Model no 1
#-----------------------------------------
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
python3 ac2dmod-250.py  >> log.txt

#-----------------------------------------
# Model no 2
#-----------------------------------------
n1=501
n2=501
#Create vp
spike -n1 $n1 -n2 $n2 -val 2500.0 vp.bin

#Create rho 
spike -n1 $n1 -n2 $n2 -val 1000.0 rho.bin

#Create Q 
spike -n1 $n1 -n2 $n2 -val 100000.0 q.bin

#Run modelling
echo "** Model size 501x501 Timesteps 1501" >> log.txt
python3 ac2dmod-500.py  >> log.txt

#-----------------------------------------
# Model no 3
#-----------------------------------------
n1=1001
n2=1001
#Create vp
spike -n1 $n1 -n2 $n2 -val 2500.0 vp.bin

#Create rho 
spike -n1 $n1 -n2 $n2 -val 1000.0 rho.bin

#Create Q 
spike -n1 $n1 -n2 $n2 -val 100000.0 q.bin

#Run modelling
echo "** Model size 1001x1001 Timesteps 1501" >> log.txt
python3 ac2dmod-1000.py  >> log.txt

#-----------------------------------------
# Model no 4
#-----------------------------------------
n1=2001
n2=2001
#Create vp
spike -n1 $n1 -n2 $n2 -val 2500.0 vp.bin

#Create rho 
spike -n1 $n1 -n2 $n2 -val 1000.0 rho.bin

#Create Q 
spike -n1 $n1 -n2 $n2 -val 100000.0 q.bin

#Run modelling
echo "** Model size 2001x2001 Timesteps 1501" >> log.txt
python3 ac2dmod-2000.py  >> log.txt

#-----------------------------------------
# Model no 5
#-----------------------------------------
n1=4001
n2=4001
#Create vp
spike -n1 $n1 -n2 $n2 -val 2500.0 vp.bin

#Create rho 
spike -n1 $n1 -n2 $n2 -val 1000.0 rho.bin

#Create Q 
spike -n1 $n1 -n2 $n2 -val 100000.0 q.bin

#Run modelling
echo "** Model size 4001x4001 Timesteps 1501" >> log.txt
python3 ac2dmod-4000.py  >> log.txt
