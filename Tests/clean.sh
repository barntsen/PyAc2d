#!/bin/sh

# Script for cleaning tests

cd Cpu
./clean.sh
cd ..

cd Cuda
./clean.sh
cd ..

cd Omp
./clean.sh
cd ..
