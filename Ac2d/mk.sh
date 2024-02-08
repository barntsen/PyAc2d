#!/bin/sh
# mk is a script for compiling the py2acd ac2d code
cc=$1

# Compile nividia cuda version
if  test $cc = cuda ; then
  ecc      -O ac2d.e
  ecc      -O diff.e
  ecc      -O model.e
  ecc      -O src.e
  ecc      -O rec.e
ar rcs libac2dcuda.o ac2d.o diff.o model.o src.o rec.o
fi

# Compile amd hip version
if  test $cc = hip ; then
  ech  -O ac2d.e
  ech  -O diff.e
  ech  -O model.e
  ech  -O src.e
  ech  -O  rec.e
  ar rcs libac2dhip.o ac2d.o diff.o model.o src.o rec.o
fi

# Compile eps code
if  test $cc = gcc ; then
  ec  -O $f ac2d.e
  ec  -O $f diff.e
  ec  -O $f model.e
  ec  -O $f src.e
  ec  -O $f rec.e
  ar rcs libac2dcpu.o ac2d.o diff.o model.o src.o rec.o
fi

