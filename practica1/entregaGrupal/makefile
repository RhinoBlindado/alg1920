EXE=burbuja floyd hanoi heapsort insercion mergesort quicksort seleccion
O1=burbujaO1 floydO1 hanoiO1 heapsortO1 insercionO1 mergesortO1 quicksortO1 seleccionO1
O2=burbujaO2 floydO2 hanoiO2 heapsortO2 insercionO2 mergesortO2 quicksortO2 seleccionO2
O3=burbujaO3 floydO3 hanoiO3 heapsortO3 insercionO3 mergesortO3 quicksortO3 seleccionO3
DAT=Datos/burbuja.dat Datos/floyd.dat Datos/hanoi.dat Datos/heapsort.dat Datos/insercion.dat Datos/mergesort.dat Datos/quicksort.dat Datos/seleccion.dat
DATO1=Datos/burbujaO1.dat Datos/floydO1.dat Datos/hanoiO1.dat Datos/heapsortO1.dat Datos/insercionO1.dat Datos/mergesortO1.dat Datos/quicksortO1.dat Datos/seleccionO1.dat
DATO2=Datos/burbujaO2.dat Datos/floydO2.dat Datos/hanoiO2.dat Datos/heapsortO2.dat Datos/insercionO2.dat Datos/mergesortO2.dat Datos/quicksortO2.dat Datos/seleccionO2.dat
DATO3=Datos/burbujaO3.dat Datos/floydO3.dat Datos/hanoiO3.dat Datos/heapsortO3.dat Datos/insercionO3.dat Datos/mergesortO3.dat Datos/quicksortO3.dat Datos/seleccionO3.dat
GRAF=../Graficas/burbuja.png ../Graficas/floyd.png ../Graficas/hanoi.png ../Graficas/heapsort.png ../Graficas/insercion.png ../Graficas/mergesort.png ../Graficas/quicksort.png ../Graficas/seleccion.png ../Graficas/n2.png ../Graficas/nlogn.png
GRAFAO=../Graficas/burbujaAO.png ../Graficas/floydAO.png ../Graficas/hanoiAO.png  ../Graficas/heapsortAO.png ../Graficas/insercionAO.png ../Graficas/mergesortAO.png ../Graficas/quicksortAO.png ../Graficas/seleccionAO.png
GRAFAJ=../Graficas/burbujaAjuste.png ../Graficas/floydAjuste.png ../Graficas/hanoiAjuste.png  ../Graficas/heapsortAjuste.png ../Graficas/insercionAjuste.png ../Graficas/mergesortAjuste.png ../Graficas/quicksortAjuste.png ../Graficas/seleccionAjuste.png
n2_ini=4000
n2_fin=100000
nlogn_ini=2000000
nlogn_fin=50000000
n3_ini=100
n3_fin=2500
2n_ini=1
2n_fin=30

all : $(DAT) $(DATO1) $(DATO2) $(DATO3) $(GRAF) $(GRAFAO) $(GRAFAJ)

burbuja : burbuja.cpp
	g++ burbuja.cpp -o burbuja

floyd : floyd.cpp
	g++ floyd.cpp -o floyd

hanoi : hanoi.cpp
	g++ hanoi.cpp -o hanoi

heapsort : heapsort.cpp
	g++ heapsort.cpp -o heapsort

insercion : insercion.cpp
	g++ insercion.cpp -o insercion

mergesort : mergesort.cpp
	g++ mergesort.cpp -o mergesort

quicksort : quicksort.cpp
	g++ quicksort.cpp -o quicksort

seleccion : seleccion.cpp
	g++ seleccion.cpp -o seleccion

# Compilacion -O1

burbujaO1 : burbuja.cpp
	g++ -O1 burbuja.cpp -o burbujaO1

floydO1 : floyd.cpp
	g++ -O1 floyd.cpp -o floydO1

hanoiO1 : hanoi.cpp
	g++ -O1 hanoi.cpp -o hanoiO1

heapsortO1 : heapsort.cpp
	g++ -O1 heapsort.cpp -o heapsortO1

insercionO1 : insercion.cpp
	g++ -O1 insercion.cpp -o insercionO1

mergesortO1 : mergesort.cpp
	g++ -O1 mergesort.cpp -o mergesortO1

quicksortO1 : quicksort.cpp
	g++ -O1 quicksort.cpp -o quicksortO1

seleccionO1 : seleccion.cpp
	g++ -O1 seleccion.cpp -o seleccionO1

# Compilacion -O2

burbujaO2 : burbuja.cpp
	g++ -O2 burbuja.cpp -o burbujaO2

floydO2 : floyd.cpp
	g++ -O2 floyd.cpp -o floydO2

hanoiO2 : hanoi.cpp
	g++ -O2 hanoi.cpp -o hanoiO2

heapsortO2 : heapsort.cpp
	g++ -O2 heapsort.cpp -o heapsortO2

insercionO2 : insercion.cpp
	g++ -O2 insercion.cpp -o insercionO2

mergesortO2 : mergesort.cpp
	g++ -O2 mergesort.cpp -o mergesortO2

quicksortO2 : quicksort.cpp
	g++ -O2 quicksort.cpp -o quicksortO2

seleccionO2 : seleccion.cpp
	g++ -O2 seleccion.cpp -o seleccionO2

# Compilacion -O3

burbujaO3 : burbuja.cpp
	g++ -O3 burbuja.cpp -o burbujaO3

floydO3 : floyd.cpp
	g++ -O3 floyd.cpp -o floydO3

hanoiO3 : hanoi.cpp
	g++ -O3 hanoi.cpp -o hanoiO3

heapsortO3 : heapsort.cpp
	g++ -O3 heapsort.cpp -o heapsortO3

insercionO3 : insercion.cpp
	g++ -O3 insercion.cpp -o insercionO3

mergesortO3 : mergesort.cpp
	g++ -O3 mergesort.cpp -o mergesortO3

quicksortO3 : quicksort.cpp
	g++ -O3 quicksort.cpp -o quicksortO3

seleccionO3 : seleccion.cpp
	g++ -O3 seleccion.cpp -o seleccionO3

# Datos

Datos/burbuja.dat : burbuja
	sh script.sh burbuja $(n2_ini) $(n2_fin)

Datos/floyd.dat : floyd
	sh script.sh floyd $(n3_ini) $(n3_fin)

Datos/hanoi.dat : hanoi
	sh script.sh hanoi $(2n_ini) $(2n_fin)

Datos/heapsort.dat : heapsort
	sh script.sh heapsort $(nlogn_ini) $(nlogn_fin)

Datos/insercion.dat : insercion
	sh script.sh insercion $(n2_ini) $(n2_fin)

Datos/mergesort.dat : mergesort
	sh script.sh mergesort $(nlogn_ini) $(nlogn_fin)

Datos/quicksort.dat : quicksort
	sh script.sh quicksort $(nlogn_ini) $(nlogn_fin)

Datos/seleccion.dat : seleccion
	sh script.sh seleccion $(n2_ini) $(n2_fin)

# Datos -O1

Datos/burbujaO1.dat : burbujaO1
	sh script.sh burbujaO1 $(n2_ini) $(n2_fin)

Datos/floydO1.dat : floydO1
	sh script.sh floydO1 $(n3_ini) $(n3_fin)

Datos/hanoiO1.dat : hanoiO1
	sh script.sh hanoiO1 $(2n_ini) $(2n_fin)

Datos/heapsortO1.dat : heapsortO1
	sh script.sh heapsortO1 $(nlogn_ini) $(nlogn_fin)

Datos/insercionO1.dat : insercionO1
	sh script.sh insercionO1 $(n2_ini) $(n2_fin)

Datos/mergesortO1.dat : mergesortO1
	sh script.sh mergesortO1 $(nlogn_ini) $(nlogn_fin)

Datos/quicksortO1.dat : quicksortO1
	sh script.sh quicksortO1 $(nlogn_ini) $(nlogn_fin)

Datos/seleccionO1.dat : seleccionO1
	sh script.sh seleccionO1 $(n2_ini) $(n2_fin)

# Datos -O2

Datos/burbujaO2.dat : burbujaO2
	sh script.sh burbujaO2 $(n2_ini) $(n2_fin)

Datos/floydO2.dat : floydO2
	sh script.sh floydO2 $(n3_ini) $(n3_fin)

Datos/hanoiO2.dat : hanoiO2
	sh script.sh hanoiO2 $(2n_ini) $(2n_fin)

Datos/heapsortO2.dat : heapsortO2
	sh script.sh heapsortO2 $(nlogn_ini) $(nlogn_fin)

Datos/insercionO2.dat : insercionO2
	sh script.sh insercionO2 $(n2_ini) $(n2_fin)

Datos/mergesortO2.dat : mergesortO2
	sh script.sh mergesortO2 $(nlogn_ini) $(nlogn_fin)

Datos/quicksortO2.dat : quicksortO2
	sh script.sh quicksortO2 $(nlogn_ini) $(nlogn_fin)

Datos/seleccionO2.dat : seleccionO2
	sh script.sh seleccionO2 $(n2_ini) $(n2_fin)

# Datos -O3

Datos/burbujaO3.dat : burbujaO3
	sh script.sh burbujaO3 $(n2_ini) $(n2_fin)

Datos/floydO3.dat : floydO3
	sh script.sh floydO3 $(n3_ini) $(n3_fin)

Datos/hanoiO3.dat : hanoiO3
	sh script.sh hanoiO3 $(2n_ini) $(2n_fin)

Datos/heapsortO3.dat : heapsortO3
	sh script.sh heapsortO3 $(nlogn_ini) $(nlogn_fin)

Datos/insercionO3.dat : insercionO3
	sh script.sh insercionO3 $(n2_ini) $(n2_fin)

Datos/mergesortO3.dat : mergesortO3
	sh script.sh mergesortO3 $(nlogn_ini) $(nlogn_fin)

Datos/quicksortO3.dat : quicksortO3
	sh script.sh quicksortO3 $(nlogn_ini) $(nlogn_fin)

Datos/seleccionO3.dat : seleccionO3
	sh script.sh seleccionO3 $(n2_ini) $(n2_fin)

# Graficas

../Graficas/burbuja.png : Gnuplot/burbuja.gpi Datos/burbuja.dat
	gnuplot Gnuplot/burbuja.gpi

../Graficas/floyd.png : Gnuplot/floyd.gpi Datos/floyd.dat
	gnuplot Gnuplot/floyd.gpi

../Graficas/hanoi.png : Gnuplot/hanoi.gpi Datos/hanoi.dat
	gnuplot Gnuplot/hanoi.gpi

../Graficas/heapsort.png : Gnuplot/heapsort.gpi Datos/heapsort.dat
	gnuplot Gnuplot/heapsort.gpi

../Graficas/insercion.png : Gnuplot/insercion.gpi Datos/insercion.dat
	gnuplot Gnuplot/insercion.gpi

../Graficas/mergesort.png : Gnuplot/mergesort.gpi Datos/mergesort.dat
	gnuplot Gnuplot/mergesort.gpi

../Graficas/quicksort.png : Gnuplot/quicksort.gpi Datos/quicksort.dat
	gnuplot Gnuplot/quicksort.gpi

../Graficas/seleccion.png : Gnuplot/seleccion.gpi Datos/seleccion.dat
	gnuplot Gnuplot/seleccion.gpi

# Graficas AO

../Graficas/burbujaAO.png : Gnuplot/burbujaAO.gpi Datos/burbuja.dat Datos/burbujaO1.dat Datos/burbujaO2.dat Datos/burbujaO3.dat
	gnuplot Gnuplot/burbujaAO.gpi

../Graficas/floydAO.png : Gnuplot/floydAO.gpi Datos/floyd.dat Datos/floydO1.dat Datos/floydO2.dat Datos/floydO3.dat
	gnuplot Gnuplot/floydAO.gpi

../Graficas/hanoiAO.png : Gnuplot/hanoiAO.gpi Datos/hanoi.dat Datos/hanoiO1.dat Datos/hanoiO2.dat Datos/hanoiO3.dat
	gnuplot Gnuplot/hanoiAO.gpi

../Graficas/heapsortAO.png : Gnuplot/heapsortAO.gpi Datos/heapsort.dat Datos/heapsortO1.dat Datos/heapsortO2.dat Datos/heapsortO3.dat
	gnuplot Gnuplot/heapsortAO.gpi

../Graficas/insercionAO.png : Gnuplot/insercionAO.gpi Datos/insercion.dat Datos/insercionO1.dat Datos/insercionO2.dat Datos/insercionO3.dat
	gnuplot Gnuplot/insercionAO.gpi

../Graficas/mergesortAO.png : Gnuplot/mergesortAO.gpi Datos/mergesort.dat Datos/mergesortO1.dat Datos/mergesortO2.dat Datos/mergesortO3.dat
	gnuplot Gnuplot/mergesortAO.gpi

../Graficas/quicksortAO.png : Gnuplot/quicksortAO.gpi Datos/quicksort.dat Datos/quicksortO1.dat Datos/quicksortO2.dat Datos/quicksortO3.dat
	gnuplot Gnuplot/quicksortAO.gpi

../Graficas/seleccionAO.png : Gnuplot/seleccionAO.gpi Datos/seleccion.dat Datos/seleccionO1.dat Datos/seleccionO2.dat Datos/seleccionO3.dat
	gnuplot Gnuplot/seleccionAO.gpi

# Graficas Ajuste

../Graficas/burbujaAjuste.png : Gnuplot/burbujaAjuste.gpi Datos/burbuja.dat
	gnuplot Gnuplot/burbujaAjuste.gpi

../Graficas/floydAjuste.png : Gnuplot/floydAjuste.gpi Datos/floyd.dat
	gnuplot Gnuplot/floydAjuste.gpi

../Graficas/hanoiAjuste.png : Gnuplot/hanoiAjuste.gpi Datos/hanoi.dat
	gnuplot Gnuplot/hanoiAjuste.gpi

../Graficas/heapsortAjuste.png : Gnuplot/heapsortAjuste.gpi Datos/heapsort.dat
	gnuplot Gnuplot/heapsortAjuste.gpi

../Graficas/insercionAjuste.png : Gnuplot/insercionAjuste.gpi Datos/insercion.dat
	gnuplot Gnuplot/insercionAjuste.gpi

../Graficas/mergesortAjuste.png : Gnuplot/mergesortAjuste.gpi Datos/mergesort.dat
	gnuplot Gnuplot/mergesortAjuste.gpi

../Graficas/quicksortAjuste.png : Gnuplot/quicksortAjuste.gpi Datos/quicksort.dat
	gnuplot Gnuplot/quicksortAjuste.gpi

../Graficas/seleccionAjuste.png : Gnuplot/seleccionAjuste.gpi Datos/seleccion.dat
	gnuplot Gnuplot/seleccionAjuste.gpi

# Graficas tipo

../Graficas/n2.png : Gnuplot/n2.gpi Datos/burbuja.dat Datos/insercion.dat Datos/seleccion.dat
	gnuplot Gnuplot/n2.gpi

../Graficas/nlogn.png : Gnuplot/nlogn.gpi Datos/quicksort.dat Datos/mergesort.dat Datos/heapsort.dat
	gnuplot Gnuplot/nlogn.gpi

# Cleaners

cleanburbuja :
	rm burbuja burbujaO1 burbujaO2 burbujaO3 Datos/burbuja.dat Datos/burbujaO1.dat Datos/burbujaO2.dat Datos/burbujaO3.dat ../Graficas/burbuja.png ../Graficas/burbujaAO.png ../Graficas/burbujaAjuste.png

cleanfloyd :
	rm floyd floydO1 floydO2 floydO3 Datos/floyd.dat Datos/floydO1.dat Datos/floydO2.dat Datos/floydO3.dat ../Graficas/floyd.png ../Graficas/floydAO.png ../Graficas/floydAjuste.png

cleanhanoi :
	rm hanoi hanoiO1 hanoiO2 hanoiO3 Datos/hanoi.dat Datos/hanoiO1.dat Datos/hanoiO2.dat Datos/hanoiO3.dat ../Graficas/hanoi.png ../Graficas/hanoiAO.png ../Graficas/hanoiAjuste.png

cleanheapsort :
	rm heapsort heapsortO1 heapsortO2 heapsortO3 Datos/heapsort.dat Datos/heapsortO1.dat Datos/heapsortO2.dat Datos/heapsortO3.dat ../Graficas/heapsort.png ../Graficas/heapsortAO.png ../Graficas/heapsortAjuste.png

cleaninsercion :
	rm insercion insercionO1 insercionO2 insercionO3 Datos/insercion.dat Datos/insercionO1.dat Datos/insercionO2.dat Datos/insercionO3.dat ../Graficas/insercion.png ../Graficas/insercionAO.png ../Graficas/insercionAjuste.png

cleanmergesort :
	rm mergesort mergesortO1 mergesortO2 mergesortO3 Datos/mergesort.dat Datos/mergesortO1.dat Datos/mergesortO2.dat Datos/mergesortO3.dat ../Graficas/mergesort.png ../Graficas/mergesortAO.png ../Graficas/mergesortAjuste.png

cleanquicksort :
	rm quicksort quicksortO1 quicksortO2 quicksortO3 Datos/quicksort.dat Datos/quicksortO1.dat Datos/quicksortO2.dat Datos/quicksortO3.dat ../Graficas/quicksort.png ../Graficas/quicksortAO.png ../Graficas/quicksortAjuste.png

cleanseleccion :
	rm seleccion seleccionO1 seleccionO2 seleccionO3 Datos/seleccion.dat Datos/seleccionO1.dat Datos/seleccionO2.dat Datos/seleccionO3.dat ../Graficas/seleccion.png ../Graficas/seleccionAO.png ../Graficas/seleccionAjuste.png

clean :
	rm $(EXE) $(O1) $(O2) $(O3) $(DAT) $(DATO1) $(DATO2) $(DATO3) $(GRAF) $(GRAFAO) $(GRAFAJ) fit.log
