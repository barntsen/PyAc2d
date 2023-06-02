#!/bin/sh

cp ../../Ac2d/libac2dcuda.o .
cp ../../Ac2d/*.i .


ecc ac2dmod.e
elc -o ac2dmod ac2dmod.o libac2dcuda.o 

./run.sh


