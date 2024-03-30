#!/bin/sh

image -d1 0.1         \
      -d2 0.1         \
      -ar 2.5         \
      -n1 1201        \
      -n2 251         \
      -colormap crust \
      -xlabel "Distance (km)" \
      -ylabel "Depth (km)"    \
      -o model.pdf            \
      -noshow                 \
      vp.bin 
