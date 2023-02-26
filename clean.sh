#!/bin/sh

# Script for cleaning up

#Clean Documentation
cd Doc
./clean.sh
cd ..


#Clean library
cd Ac2d
./clean.sh
cd ..

#Clean Python-cpu bindings
cd Python-cpu
./clean.sh
cd ..

#Clean Python-cuda bindings
cd Python-cuda
./clean.sh
cd ..

#Clean Python-omp bindings
cd Python-omp
./clean.sh
cd ..
