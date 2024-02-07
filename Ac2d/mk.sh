#!/bin/sh
# mk is a script for compiling the py2acd ac2d code

# Compile nividia cuda version
ecc      -O ac2d.e
ecc      -O diff.e
ecc      -O model.e
ecc      -O src.e
ecc      -O rec.e
ar rcs libac2dcuda.o ac2d.o diff.o model.o src.o rec.o

# Compile amd hip version
#ech  -O ac2d.e
#ech  -O diff.e
#ech  -O model.e
#ech  -O src.e
#ech  -O  rec.e
#ar rcs libac2dhip.o ac2d.o diff.o model.o src.o rec.o

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
