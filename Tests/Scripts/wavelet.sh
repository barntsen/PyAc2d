#!/bin/sh
#----------------------
# Generate source pulse
# and make plot
#----------------------

nt=10001 #No of samples
lw=1001  #Window for plotting

ricker -nt $nt -f0 30.0 -t0 0.100 -dt 0.0005 src.bin 
window -n1 $nt -l1 $lw src.bin xaa.bin
graph -noshow  -title "Wavelet" -o wavelet.pdf -d1 0.0005 -n1 $lw xaa.bin

spec -n1 $lw xaa.bin spectrum.bin
window -n1 $lw -l1 50 spectrum.bin xab.bin
graph -noshow -o spectrum.pdf -d1 2.0 -n1 50 xab.bin


