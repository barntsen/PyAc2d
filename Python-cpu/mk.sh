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

ec -c  pyeps.e
ec -c  model.e
ec -c  src.e
ec -c  rec.e
ec -c  ac2d.e
ec -c  diff.e

cp $EPS/Src/libe.e .
cp $EPS/Src/libe.i .
cp $EPS/Src/m.i .
cp $EPS/Src/run.i .
cp $EPS/Src/runcpu.e .

ec -c libe.e
cp runcpu.e runcpu.c

#
#-- Create the python interface for the pyac2dcpu
#
swig -python pyac2dcpu.i

gcc -O2 -fPIC -c pyac2dcpu_wrap.c  libe.c runcpu.c \
     pyeps.c model.c src.c rec.c diff.c ac2d.c  -I/usr/include/python3.8	

gcc -O2 -shared -o _pyac2dcpu.so -L/usr/local/cuda-10.1/lib64/ runcpu.o libe.o \
                ac2d.o model.o pyeps.o src.o rec.o diff.o pyac2dcpu_wrap.o


#The _fd2dcpu.so shared library contains the c-to-python bindings.
