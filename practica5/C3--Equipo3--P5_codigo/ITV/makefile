
EXE = generador itv
DAT = 2l.dat 3l.dat
GRAF = graf2l.png graf3l.png grafall.png

rutaESC = ./Escenarios
rutaDAT = ./Datos
rutaGRAF = ./Graficas

ini = 2
fin2=30
fin = 22
paso = 2


all : $(EXE) $(DAT) esc $(GRAF)

exe : $(EXE)

dat : $(DAT)

graf : $(GRAF)

generador : generador.cpp
	g++ -Wall -std=c++17 -o $@ $<

itv : itv.cpp
	g++ -Wall -std=c++17 -o $@ $<

esc : generar_escenarios.sh generador
	bash generar_escenarios.sh $(ini) $(fin2) $(paso)

2l.dat : esc itv
	bash generar_datos.sh $(ini) $(fin2) $(paso) 2

3l.dat : esc itv
	bash generar_datos.sh $(ini) $(fin) $(paso) 3

graf2l.png : 2l.dat
	gnuplot ./grafica2l.gpi

graf3l.png : 3l.dat
	gnuplot ./grafica3l.gpi

grafall.png : 2l.dat 3l.dat
	gnuplot ./graficaAll.gpi

clean:
	rm $(EXE)
	rm $(rutaESC)/*

cleanexe:
	rm $(EXE)

cleanesc:
	rm $(rutaESC)/*

cleandat:
	rm $(rutaDAT)/*

cleangraf:
	rm $(rutaGRAF)/*
