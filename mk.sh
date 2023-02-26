#!/bin/sh

# Script for compiling the ac2d library and creating pyhon bindings

#Compile library
cd Ac2d
./mk.sh
cd ..

#Create Python c-bindings
cd Python-cpu
./mk.sh
cd ..

#Create Python cuda-bindings
cd Python-cuda
./mk.sh
cd ..

#Create Python omp-bindings
cd Python-omp
./mk.sh
cd ..
