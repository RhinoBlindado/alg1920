#!/bin/bash
# Funcionamiento:nombre inicio fin intervalo


echo "ALGORITMO: $1"

for (( i=10; i<=2000; i+=50 )); do
	echo "[$1] Progreso: [ $i / $3 ]"
	Codigo/$1 $i >> Datos/$1.dat	
done

for (( i=$2; i<=$3; i+=$4 )); do
	echo "[$1] Progreso: [ $i / $3 ]"
	Codigo/$1 $i >> Datos/$1.dat	
done

