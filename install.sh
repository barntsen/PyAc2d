#!/bin/sh

# Install is a shell script for installing python code, shell scripts 
# and libraries.
# The Bin directory is target for all runable scripts/code.

cp Ac2d/ac2dmod.py  Bin/ac2dmod 
chmod +x               Bin/ac2dmod
cp Scripts/babin.py    Bin 

cp Python-cpu/_pyac2dcpu.so  Bin
cp Python-cpu/pyac2dcpu.py   Bin
cp Python-cpu/pyepscpu.py    Bin

cp Python-cuda/_pyac2dcu.so  Bin
cp Python-cuda/pyac2dcu.py   Bin
cp Python-cuda/pyepscu.py    Bin

cp Python-omp/_pyac2domp.so  Bin
cp Python-omp/pyac2domp.py   Bin
cp Python-omp/pyepsomp.py    Bin
