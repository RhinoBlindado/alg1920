#!/bin/bash

MIN=1
MAX=20

for (( i=$1; i<=$2; i+=$3 )); do
  echo $i
  ./generador $i $MIN $MAX > ./Escenarios/esc$i.txt
done
