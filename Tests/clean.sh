#!/bin/sh

# Script for cleaning tests
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
