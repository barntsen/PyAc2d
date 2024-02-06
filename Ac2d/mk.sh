#!/bin/sh

# Compile cpu version
ec  -O ac2d.e
ec  -O diff.e
ec  -O model.e
ec  -O src.e
ec  -O rec.e
ar rcs libac2dcpu.o ac2d.o diff.o model.o src.o rec.o

# Compile omp version
#ec  -f -O ac2d.e
#ec  -f -O diff.e
#ec  -f -O model.e
#ec  -f -O src.e
#ec  -f -O rec.e
#ar rcs libac2domp.o ac2d.o diff.o model.o src.o rec.o

# Compile nividia cuda version
ecc      -O ac2d.e
ecc      -O diff.e
ecc      -O model.e
ecc      -O src.e
ecc      -O rec.e
ar rcs libac2dcuda.o ac2d.o diff.o model.o src.o rec.o

# Compile amd hip version
#ech  -n $nt -m $nb ac2d.e
#ech  -n $nt -m $nb diff.e
#ech  -n $nt -m $nb  model.e
#ech  -n $nt -m $nb  src.e
#ech  -n $nt -m $nb  rec.e
#ar rcs libac2dhip.o ac2d.o diff.o model.o src.o rec.o

