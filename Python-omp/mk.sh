#!/bin/sh

# Translate from eps (.e) to c
cp ../Ac2d/model.i .
cp ../Ac2d/model.e .
cp ../Ac2d/src.i .
cp ../Ac2d/src.e .
cp ../Ac2d/rec.i .
cp ../Ac2d/rec.e .
cp ../Ac2d/ac2d.i .
cp ../Ac2d/ac2d.e .
cp ../Ac2d/diff.e .
cp ../Ac2d/diff.i .
cp ../Python-cpu/pyeps.e .

ec -c  -f -O pyeps.e
ec -c  -f -O model.e
ec -c  -f -O src.e
ec -c  -f -O rec.e
ec -c  -f -O ac2d.e
ec -c  -f -O diff.e

cp $EPS/Src/libe.e .
cp $EPS/Src/libe.i .
cp $EPS/Src/m.i .
cp $EPS/Src/run.i .
cp $EPS/Src/runcpu.e .

ec -c libe.e
cp runcpu.e runcpu.c

#
#-- Create the python interface for the pyac2domp
#

#Uncomment on idun cluster
#cp pyac2domp_wrap.e pyac2domp_wrap.c

#Comment the two lines below on idun cluster
swig -python pyac2domp.i
#Backup the swig wrapper file 
cp pyac2domp_wrap.c pyac2domp_wrap.e


#--- Uncomment lines below for Ubuntu
gcc -fopenmp -ffast-math -O3 -fPIC -c pyac2domp_wrap.c  libe.c runcpu.c  \
     pyeps.c model.c src.c rec.c diff.c ac2d.c  -I/usr/include/python3.8	

#--- Uncomment lines below for Idun ntnu cluster
# gcc -fopnemp -O3 -fPIC -c pyac2domp_wrap.c  libe.c runcpu.c \
#    pyeps.c model.c src.c rec.c diff.c ac2d.c      \
#    -I/cluster/apps/eb/software/Python/3.8.2-GCCcore-9.3.0/include/python3.8

gcc -fopenmp -ffast-math -O3 -shared -o _pyac2domp.so runcpu.o libe.o    \
     ac2d.o model.o pyeps.o src.o rec.o diff.o pyac2domp_wrap.o


#The _pyac2domp.so shared library contains the c-to-python bindings.
