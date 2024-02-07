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
cp Scripts/ac2dmod.py  Bin/ac2dmod 
chmod +x               Bin/ac2dmod
cp ac2dmod/babin.py    Bin 
cp Ac2d/src.py              Bin
cp Ac2d/rec.py              Bin
cp Ac2d/model.py            Bin
cp Ac2d/ac2d.py             Bin
cp Ac2d/pyeps.py            Bin

if  test $cc = gcc ; then 
  cp Python-cpu/_pyac2dcpu.so  Bin
  cp Python-cpu/pyac2dcpu.py   Bin
  cp Python-cpu/pyepscpu.py    Bin
fi

if  test $cc = omp ; then 
  cp Python-omp/_pyac2domp.so  Bin
  cp Python-omp/pyac2domp.py   Bin
  cp Python-omp/pyepsomp.py    Bin
fi

if test $cc = nvcc ; then 
  cp Python-cuda/_pyac2dcu.so  Bin
  cp Python-cuda/pyac2dcu.py   Bin
  cp Python-cuda/pyepscu.py    Bin
fi

if test $cc = hip ; then 
  cp Python-hip/_pyac2dhip.so  Bin
  cp Python-hip/pyac2dhip.py   Bin
  cp Python-hip/pyepship.py    Bin
fi
cp Python-cpu/_pyac2dcpu.so  Bin
cp Python-cuda/_pyac2dcu.so  Bin
cp Python-omp/_pyac2domp.so  Bin

cp Scripts/spike             Bin
cp Scripts/ricker            Bin
cp Scripts/movie             Bin
cp Scripts/parula.py         Bin
cp Scripts/babin.py          Bin
cp Scripts/bacolmap.py       Bin
cp Scripts/pltcom.py         Bin
