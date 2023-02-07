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

ec -c pyeps.e
ec -c -f model.e
ec -c -f src.e
ec -c -f rec.e
ec -c -f ac2d.e
ec -c -f diff.e

cp $EPS/Src/libe.e .
cp $EPS/Src/libe.i .
cp $EPS/Src/m.i .
cp $EPS/Src/run.i .
cp $EPS/Src/runcpu.e .

ec -c libe.e
cp runcpu.e runcpu.c

#
#-- Create the python interface for the fd2d module
#
swig -python fd2d.i

gcc -fopenmp -fPIC -c fd2d_wrap.c  libe.c runcpu.c \
     pyeps.c model.c src.c rec.c diff.c ac2d.c  -I/usr/include/python3.8	

gcc -fopenmp -shared -o _fd2d.so -L/usr/local/cuda-10.1/lib64/ runcpu.o libe.o \
                ac2d.o model.o pyeps.o src.o rec.o diff.o fd2d_wrap.o 

#The _fd2d.so shared library contains the c-to-python bindings.
