#!/bin/sh

# Script for cleaning up

#
rm -rf Bin/*

#Clean Documentation
cd Doc
./clean.sh
cd ..

#Clean library
cd Ac2d
./clean.sh
cd ..

#Clean Python-cpu bindings
cd Python-c
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

#Clean Python-hip bindings
cd Python-hip
./clean.sh
cd ..

cd Tests
./clean.sh
cd ..

cd Scripts
./clean.sh
cd ..

rm -rf Bin/*
