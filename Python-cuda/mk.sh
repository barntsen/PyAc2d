#!/bin/sh
# mk.sh is a script for building the python-cuda interface

if ! type swig   ; then
  cp pyac2dcu_wrap.e pyac2dcu_wrap.cxx
else
  swig -c++ -python pyac2dcu.i
fi

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
ecc -c -O pyeps.e
ecc -c -O model.e
ecc -c -O src.e
ecc -c -O rec.e
ecc -c -O ac2d.e
ecc -c -O diff.e

cp $EPS/Src/libe.e .
cp $EPS/Src/libe.i .
cp $EPS/Src/m.i .
cp $EPS/Src/run.i .
cp $EPS/Src/runcuda.e .

ecc -c libe.e
cp runcuda.e runcuda.cpp

export PYTHONINC=/usr/include/python3.8

nvcc  --x cu --compiler-options "-fPIC" -c pyac2dcu_wrap.cu  \
       libe.cpp runcuda.cpp                                  \
       pyeps.cpp model.cpp src.cpp rec.cpp diff.cpp ac2d.cpp \
       -I$PYTHONINC
#g++  -shared -o _pyac2dcu.so -L/usr/local/cuda-11.8/lib64/      \
nvcc  -shared -o _pyac2dcu.so -L/usr/local/cuda-11.8/lib64/      \
      runcuda.o libe.o                                          \
      ac2d.o model.o pyeps.o src.o rec.o diff.o pyac2dcu_wrap.o \
      -lcuda -lcudart


