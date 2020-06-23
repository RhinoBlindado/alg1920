#!/bin/bash
DATA=$1
let INI=$2
let FIN=$3
let i=$INI
echo "" > "Datos/$DATA.dat"
while [ $i -le $FIN ];do
  echo $i
  ./$DATA  $i >> "Datos/$DATA.dat"
  let i=$i+$INI
done
