#!/bin/sh
# install is a script for installing all runable codes
# and scripts.

cc=$1

if test -z $cc ; then 
  echo " usage: install.sh arg "
  echo "        arg is one of cpu, cuda, hip or omp"
  exit
fi

if test $cc != cpu  && test $cc != cuda  && test $cc != hip && test $cc != omp ; then 
  echo " usage: mk.sh arg "
  echo "        arg is one of cpu, cuda, hip or omp"
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

if  test $cc = cpu ; then 
  cp Python-c/pyac2dcpu.so  Bin
fi

if  test $cc = omp ; then 
  cp Python-omp/pyac2domp.so  Bin
fi

if test $cc = cuda ; then 
  cp Python-cuda/pyac2dcuda.so  Bin
fi

if test $cc = hip ; then 
  cp Python-hip/pyac2dhip.so  Bin
fi

