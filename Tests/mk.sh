#!/bin/sh

# Script for running all tests

cd Py-Cuda
./mk.sh
cd ..

cd Py-Omp
./mk.sh
cd ..

cd Py-Cpu
./mk.sh
cd ..

cd Hip 
./mk.sh
cd ..
