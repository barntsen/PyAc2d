#!/bin/sh

# Script for cleaning tests

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
