#!/bin/sh

image -n1 1201       \
      -n2 20001      \
      -d1 0.10      \
      -d2 0.001      \
      -cmin -0.1e-07 \
      -cmax 0.1e-07  \
      -o data.pdf    \
      -noshow        \
      -xlabel "Distance (km)" \
      -ylabel "Time (sec)"   \
       p.bin
