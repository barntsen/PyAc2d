#!/bin/sh
#./clean.sh


#Uncomment on idun and lumi cluster
cp pyac2dhip_wrap.e pyac2dhip_wrap.cxx

#Comment the two lines below on idun and lumi cluster
#swig -c++ -python pyac2dhip.i
#cp pyac2dhip_wrap.cxx pyac2dhip_wrap.e


mv pyac2dhip_wrap.cxx pyac2dhip_wrap.cu
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
ech -c pyeps.e
ech -c model.e
ech -c src.e
ech -c rec.e
ech -c ac2d.e
ech -c diff.e

cp $EPS/Src/libe.e .
cp $EPS/Src/libe.i .
cp $EPS/Src/m.i .
cp $EPS/Src/run.i .
cp $EPS/Src/runhip.e .

ech -c libe.e
cp runhip.e runhip.cpp

hipcc -fPIC -c pyac2dhip_wrap.cu                              \
       libe.cpp runhip.cpp                                   \
       pyeps.cpp model.cpp src.cpp rec.cpp diff.cpp ac2d.cpp \
       -I/opt/cray/pe/python/3.9.13.1/include/python3.9/

#Uncomment for Ubuntu
#g++  -shared -o _pyac2dcu.so -L/usr/local/cuda-11.8/lib64/      \
#      runcuda.o libe.o                                          \
#      ac2d.o model.o pyeps.o src.o rec.o diff.o pyac2dcu_wrap.o \
#      -lcuda -lcudart

#Uncomment for idun cluster
# gcc -O2 -fPIC -c pyac2dcpu_wrap.c  libe.c runcpu.c \
#    pyeps.c model.c src.c rec.c diff.c ac2d.c      \
#    -I/cluster/apps/eb/software/Python/3.8.2-GCCcore-9.3.0/include/python3.8

#Uncomment for lumi cluster
hipcc -shared -o _pyac2dhip.so                                  \
      runhip.o libe.o                                           \
      ac2d.o model.o pyeps.o src.o rec.o diff.o pyac2dhip_wrap.o \
      -L/opt/cray/pe/python/3.9.13.1/lib -lpython3.9


