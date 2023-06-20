#!/bin/sh
# mk is a script for compiling the py2acd ac2d code

if test -z $1 ; then 
  echo " usage: mk.sh arg "
  echo "        arg is one of gcc, nvcc, hip or omp"
  exit
fi

#Set compiler

echo "** Compiling all code with " $1

if  test $1 = gcc ; then
  cc=ec
  nt=0
  nb=0
elif  test $1 = omp ; then
  cc=ec
  nt=0
  nb=0
  f=-f
elif test $1 = nvcc ; then 
  cc=ecc 
  nt=1024
  nb=1024
elif test $1 = hip ; then 
  cc=ech
  cc=ecc 
  nt=1024
  nb=1024
else
    echo "argument is one of gcc, nvcc, hip or omp"
    exit
fi

echo "Compiling with" $cc

# Compile eps code
$cc  -O -n $nt -m $nb $f ac2d.e
$cc  -O -n $nt -m $nb $f diff.e
$cc  -O -n $nt -m $nb $f model.e
$cc  -O -n $nt -m $nb $f src.e
$cc  -O -n $nt -m $nb $f rec.e

if  test $1 = gcc ; then
  lib=libac2dcpu
elif  test $1 = omp ; then
  lib=libac2dcpu
elif test $1 = nvcc ; then 
  lib=libac2dcu
elif test $1 = hip ; then 
  lib=libac2dhip
else
  echo "unsupported compiler"
  exit
fi
    ar rcs $lib.o ac2d.o diff.o model.o src.o rec.o
