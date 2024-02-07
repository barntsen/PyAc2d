#!/bin/sh

# Install is a shell script for installing python code, shell scripts 
# and libraries.
# The Bin directory is target for all runable scripts/code.

cp Ac2d/ac2dmod.py     Bin/ac2dmod 
chmod +x               Bin/ac2dmod
cp ac2dmod/babin.py    Bin 
cp Ac2d/src.py              Bin
cp Ac2d/rec.py              Bin
cp Ac2d/model.py            Bin
cp Ac2d/ac2d.py             Bin
cp Ac2d/pyeps.py            Bin

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
