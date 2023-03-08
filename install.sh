#!/bin/sh

cp Tests/Scripts/ac2dmodcpu  Bin 
chmod +x                     Bin/ac2dmodcpu
cp Tests/Scripts/babin.py    Bin 
cp Python-cpu/_pyac2dcpu.so  Bin
cp Python-cpu/pyac2dcpu.py   Bin
cp Python-cpu/pyepscpu.py    Bin

cp Tests/Scripts/ac2dmodcu   Bin 
chmod +x                     Bin/ac2dmodcu
cp Python-cuda/_pyac2dcu.so  Bin
cp Python-cuda/pyac2dcu.py   Bin
cp Python-cuda/pyepscu.py    Bin

cp Tests/Scripts/ac2dmodomp   Bin 
chmod +x                     Bin/ac2dmodcu
cp Python-omp/_pyac2domp.so  Bin
cp Python-omp/pyac2domp.py   Bin
cp Python-omp/pyepsomp.py    Bin
