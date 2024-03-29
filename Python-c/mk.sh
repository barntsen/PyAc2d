#!/bin/sh

# To regenerate c-code frome the eps source
# uncomment the lines below.
#cp ../Ac2d/pyeps.e .
#cp ../Ac2d/model.i .
#cp ../Ac2d/model.e .
#cp ../Ac2d/src.i .
#cp ../Ac2d/src.e .
#cp ../Ac2d/rec.i .
#cp ../Ac2d/rec.e .
#cp ../Ac2d/ac2d.i .
#cp ../Ac2d/ac2d.e .
#cp ../Ac2d/diff.e .
#cp ../Ac2d/diff.i .
#cp $EPS/Src/libe.e .
#cp $EPS/Src/libe.i .
#cp $EPS/Src/m-cpu.i m.i
#cp $EPS/Src/run.i .
#cp $EPS/Src/runcpu.e .
#ec -c  pyeps.e
#ec -c  model.e
#ec -c  src.e
#ec -c  rec.e
#ec -c  ac2d.e
#ec -c  diff.e
#ec -c libe.e
#cp runcpu.e runcpu.c
#swig -python pyac2dcpu.i

#--- Uncomment lines below for Ubuntu
gcc -O2 -fPIC -c pyac2dcpu_wrap.c  libe.c runcpu.c \
     pyeps.c model.c src.c rec.c diff.c ac2d.c  -I/usr/include/python3.8	

#--- Uncomment lines below for Idun ntnu cluster
#gcc -O2 -fPIC -c pyac2dcpu_wrap.c  libe.c runcpu.c \
#    pyeps.c model.c src.c rec.c diff.c ac2d.c  -I/cluster/apps/eb/software/Python/3.8.2-GCCcore-9.3.0/include/python3.8

gcc -O2 -shared -o _pyac2dcpu.so runcpu.o libe.o \
     ac2d.o model.o pyeps.o src.o rec.o diff.o pyac2dcpu_wrap.o

