#!/bin/sh

EXE=\#\!/usr/bin/python3
echo $EXE > xaa.txt
inst=../Bin

cat xaa.txt ricker.py > $inst/ricker
chmod +x $inst/ricker
cat xaa.txt spike.py  > $inst/spike
chmod +x $inst/spike
cat xaa.txt image.py > $inst/image
chmod +x $inst/image
cat xaa.txt movie.py > $inst/movie
chmod +x $inst/movie

cp parula.py $inst
cp pltcom.py $inst
cp babin.py $inst 
cp bacolmaps.py $inst
cp rss.py   $inst
cp segy.py  $inst
cp cpt.py   $inst
