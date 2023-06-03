#!/bin/sh

cp ../../Ac2d/libac2dcuda.o .
cp ../../Ac2d/*.i .
cp ../../Ac2d/ac2dmod.e .

ecc ac2dmod.e
elc -o ac2dmod ac2dmod.o libac2dcuda.o 



