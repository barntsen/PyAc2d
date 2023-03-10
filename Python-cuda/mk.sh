#!/bin/sh
#./clean.sh

swig -c++ -python pyac2dcu.i
mv pyac2dcu_wrap.cxx pyac2dcu_wrap.cu

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
ecc -c -g pyeps.e
ecc -c -g model.e
ecc -c -g src.e
ecc -c -g rec.e
ecc -c -g ac2d.e
ecc -c -g diff.e

cp $EPS/Src/libe.e .
cp $EPS/Src/libe.i .
cp $EPS/Src/m.i .
cp $EPS/Src/run.i .
cp $EPS/Src/runcuda.e .

ecc -c libe.e
cp runcuda.e runcuda.cpp

nvcc -g --x cu --compiler-options "-fPIC" -c pyac2dcu_wrap.cu  libe.cpp runcuda.cpp \
       pyeps.cpp model.cpp src.cpp rec.cpp diff.cpp ac2d.cpp  -I/usr/include/python3.8	

g++ -g -shared -o _pyac2dcu.so -L/usr/local/cuda-11.8/lib64/ runcuda.o libe.o \
                ac2d.o model.o pyeps.o src.o rec.o diff.o pyac2dcu_wrap.o -lcuda -lcudart


