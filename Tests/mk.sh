#!/bin/sh

# Script for running all tests

cd Cuda
./mk.sh
cd ..

cd Omp
./mk.sh
cd ..

cd Cpu
./mk.sh
cd ..
