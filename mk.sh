#!/bin/sh
# mk is a script for compiling and installing all runable codes
# and scripts.

cc=$1

if test -z $cc ; then 
  echo " usage: mk.sh arg "
  echo "        arg is one of gcc, nvcc, hip or omp"
  exit
fi

if test $cc != gcc && test $cc != nvcc  && test $cc != hip && test $cc != omp ; then
  echo " usage: mk.sh arg "
  echo "        arg is one of gcc, nvcc, hip or omp"
  exit
fi

echo "** Compiling and installing binaries"

if test $cc = gcc ;  then
  cd Ac2d       #Compile ac2d library for cpu
  ./mk.sh $cc   
  cd ..

  cd Python-cpu #Compile Python bindings for cpu
  ./mk.sh
  cd ..
fi

if test $cc = omp ;  then
  cd Ac2d       #Compile ac2d library with gcc and omp
  ./mk.sh $cc   
  cd ..

  cd Python-omp #Compile Python bindings for gcc and omp
  ./mk.sh
  cd ..
fi

if test $cc = nvcc ; then  
  cd Ac2d        #Compile ac2d library for nvidia gpu
  ./mk.sh $cc    
  cd ..

  cd Python-cuda #Compile Python bindings for nvidia gpu
  ./mk.sh
  cd ..
fi

if test $cc = hip ; then
  cd Ac2d       #Compile ac2d library for nvidia gpu
  ./mk.sh $cc  
  cd ..

  cd Python-hip #Compile Python bindings for nvidia gpu
  ./mk.sh
  cd ..
fi

# Install python scripts and modules in the Bin folder
./install.sh $cc
