#!/bin/sh

# mk is a script for compiling and installing all runable codes
# and scripts.

#Compile library
cd Ac2d
./mk.sh
cd ..

#Create Python c-bindings
cd Python-c
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

./install.sh
