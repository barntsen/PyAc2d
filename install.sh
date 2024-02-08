#!/bin/sh
# install is a script for installing all runable codes
# and scripts.

cc=$1

if test -z $cc ; then 
  echo " usage: install.sh arg "
  echo "        arg is one of gcc, nvcc, hip or omp"
  exit
fi

if test $cc != gcc  && test $cc != nvcc  && test $cc != hip && test $cc != omp ; then 
  echo " usage: mk.sh arg "
  echo "        arg is one of gcc, nvcc, hip or omp"
fi

echo "** Installing binaries to the Bin folder"

#Install all python scripts
cp Ac2d/ac2dmod.py  Bin/ac2dmod 
chmod +x               Bin/ac2dmod
cp Ac2d/src.py              Bin
cp Ac2d/rec.py              Bin
cp Ac2d/model.py            Bin
cp Ac2d/ac2d.py             Bin
cp Ac2d/pyeps.py            Bin
cp Scripts/spike             Bin
cp Scripts/ricker            Bin
cp Scripts/movie             Bin
cp Scripts/parula.py         Bin
cp Ac2d/babin.py             Bin
cp Scripts/bacolmaps.py      Bin
cp Scripts/pltcom.py         Bin

# Install shared libs (python callable)

if  test $cc = gcc ; then 
  cp Python-c/_pyac2dcpu.so  Bin
  cp Python-c/pyac2dcpu.py   Bin
fi

if  test $cc = omp ; then 
  cp Python-omp/_pyac2domp.so  Bin
  cp Python-omp/pyac2domp.py   Bin
fi

if test $cc = nvcc ; then 
  cp Python-cuda/_pyac2dcu.so  Bin
  cp Python-cuda/pyac2dcu.py   Bin
fi

if test $cc = hip ; then 
  cp Python-hip/_pyac2dhip.so  Bin
  cp Python-hip/pyac2dhip.py   Bin
fi

