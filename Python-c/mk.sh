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

gcc -O2 -fPIC -c libe.c runcpu.c \
     pyeps.c model.c src.c rec.c diff.c ac2d.c  

gcc -shared -o pyac2dcpu.so pyeps.o libe.o runcpu.o src.o rec.o model.o \
               ac2d.o diff.o

