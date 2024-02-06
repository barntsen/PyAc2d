#!/bin/sh
n1=1201
n2=251
n3=400

movie                  \
      -cmin -0.5e-07  \
      -cmax 0.5e-07   \
       -cbmin 1500.0   \
       -cbmax 8500.0   \
       -n1 $n1         \
       -n2 $n2         \
       -n3 $n3         \
       -o1 0.0         \
       -d1 0.1       \
       -d2 0.1       \
       -ar 2.0        \
       -fbg vp.bin     \
       -bgcolormap crust \
       -trans 0.65      \
        snp.bin

