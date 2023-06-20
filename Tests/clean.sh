#!/bin/sh
# clean is a script for cleaning all test directories

cd Cuda
./clean.sh
cd ..

cd Cpu
./clean.sh
cd ..

cd Hip
./clean.sh
cd ..

cd Python-cpu
./clean.sh
cd ..

cd Python-cuda
./clean.sh
cd ..

cd Hip
./clean.sh
cd ..

cd Python-omp
./clean.sh
cd ..
