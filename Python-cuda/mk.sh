#!/bin/sh
# mk.sh is a script for building the python-cuda interface

# To regenerate the cuda-code from
# eps source uncomment below.
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
#cp ../Ac2d/pyeps.e .
#cp $EPS/Src/libe.e .
#cp $EPS/Src/libe.i .
#cp $EPS/Src/m-cuda.i m.i
#cp $EPS/Src/run.i .
#cp $EPS/Src/runcuda.e .
#ecc -c pyeps.e
#ecc -c model.e
#ecc -c src.e
#ecc -c rec.e
#ecc -c ac2d.e
#ecc -c diff.e
#ecc -c libe.e
#cp runcuda.e runcuda.cpp

nvcc  --x cu --compiler-options "-fPIC" -c                      \
       libe.cpp runcuda.cpp pyeps.cpp model.cpp src.cpp rec.cpp \
       diff.cpp ac2d.cpp  

g++  -shared -o pyac2dcuda.so -L/usr/local/cuda-11.8/lib64/ runcuda.o libe.o \
                ac2d.o model.o pyeps.o src.o rec.o diff.o \
                -lcuda -lcudart
