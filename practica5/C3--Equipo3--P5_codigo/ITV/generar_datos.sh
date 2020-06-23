#!/bin/bash

MIN=1
MAX=20

rm ./Datos/$4l.dat

for (( i=$1; i<=$2; i+=$3 )); do
  echo $i
  ./itv ./Escenarios/esc$i.txt $4 >> ./Datos/$4l.dat
done
