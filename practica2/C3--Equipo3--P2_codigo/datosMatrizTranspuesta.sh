#!/bin/bash
# Funcionamiento:nombre inicio fin


echo "ALGORITMO: $1"
for (( i=$2; i<=$3; i+=1 )); do
	echo "[$1] Progreso: [ $i / $3 ]"
	Codigo/$1 $(( 2**$i)) >> Datos/$1.dat	
done

