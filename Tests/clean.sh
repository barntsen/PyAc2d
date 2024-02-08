#!/bin/sh
# clean is a script for cleaning all test directories


cd Python-c
./clean.sh
cd ..

cd Python-cuda
./clean.sh
cd ..

cd Python-omp
./clean.sh
cd ..

cd Python-hip
./clean.sh
cd ..
