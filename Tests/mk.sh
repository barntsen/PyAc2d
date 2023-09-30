#!/bin/sh
# mk.sh is a script for running tests

cc=$1

if  test $cc = gcc ; then 
  cd Python-cpu
  ./mk.sh
cd ..
fi

if  test $cc = nvcc ; then 
  cd Python-cuda
  ./mk.sh
cd ..
fi

if  test $cc = hip ; then 
  cd Python-hip
  ./mk.sh
cd ..
fi

if  test $cc = omp ; then 
  cd Python-omp
  ./mk.sh
cd ..
fi

