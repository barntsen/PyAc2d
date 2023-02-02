#!/bin/sh
#./clean.sh

swig -c++ -python fd2d.i
mv fd2d_wrap.cxx fd2d_wrap.cu

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
ecc -c pyeps.e
ecc -c model.e
ecc -c src.e
ecc -c rec.e
ecc -c ac2d.e
ecc -c diff.e

cp $EPS/Src/libe.e .
cp $EPS/Src/libe.i .
cp $EPS/Src/m.i .
cp $EPS/Src/run.i .
cp $EPS/Src/runcuda.e .

ecc -c libe.e
cp runcuda.e runcuda.cpp

nvcc --x cu --compiler-options "-fPIC" -c fd2d_wrap.cu  libe.cpp runcuda.cpp \
       pyeps.cpp model.cpp src.cpp rec.cpp diff.cpp ac2d.cpp  -I/usr/include/python3.8	

g++ -shared -o _fd2d.so -L/usr/local/cuda-11.8/lib64/ runcuda.o libe.o \
                ac2d.o model.o pyeps.o src.o rec.o diff.o fd2d_wrap.o -lcuda -lcudart


