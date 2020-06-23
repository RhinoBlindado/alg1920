#--MAKEFILE--
# Autor: Valentino Lugli

# COMPILADOR
CC = g++


all: burbuja_exe quicksort_exe hanoi_exe floyd_exe
all_O1:
	$(CC) -O1 -o burbuja_O1_exe burbuja.cpp
	$(CC) -O1 -o quicksort_O1_exe quicksort.cpp
	$(CC) -O1 -o hanoi_O1_exe hanoi.cpp
	$(CC) -O1 -o floyd_O1_exe floyd.cpp
all_O2:
	$(CC) -O2 -o burbuja_O2_exe burbuja.cpp
	$(CC) -O2 -o quicksort_O2_exe quicksort.cpp
	$(CC) -O2 -o hanoi_O2_exe hanoi.cpp
	$(CC) -O2 -o floyd_O2_exe floyd.cpp

all_O3:
	$(CC) -O3 -o burbuja_O3_exe burbuja.cpp
	$(CC) -O3 -o quicksort_O3_exe quicksort.cpp
	$(CC) -O3 -o hanoi_O3_exe hanoi.cpp
	$(CC) -O3 -o floyd_O3_exe floyd.cpp

burbuja_exe: burbuja.cpp
	$(CC) -o $@ $<
quicksort_exe: quicksort.cpp
	$(CC) -o $@ $<
hanoi_exe: hanoi.cpp
	$(CC) -o $@ $<
floyd_exe: floyd.cpp
	$(CC) -o $@ $<

clean:
	$(RM) *_exe
