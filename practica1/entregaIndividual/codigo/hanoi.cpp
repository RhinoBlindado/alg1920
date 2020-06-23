/**
   @file Resoluci�n del problema de las Torres de Hanoi
*/

/*  ALGORITMICA - Practica 1
  Autor: Valentino Glauco Lugli, Grupo C3

  Descripcion: Medir el tiempo que toma en realizarse el algoritmo de Burbuja para diferentes tamaño de entrada, para ello se
han realizado modificaciones puntuales al codigo para que este se acople mejor al guion de Bash para automatizar el proceso.

  - Añadido los argumentos a la funcion main() para recibir parametros desde la consola.
  - Cambiar de tipo la variable recibida del main a tipo entero.
  - Declarado variables tantes y tdespues tipo 'clock_t' para medir el tiempo que toma en ejecutarse la implementacion del algoritmo
  - Imprimir el numero de elementos y el tiempo que tomo el programa en ejecutarse.
*/
   
#include <iostream>
using namespace std;
#include <ctime>


/**
   @brief Resuelve el problema de las Torres de Hanoi
   @param M: n�mero de discos. M > 1.
   @param i: n�mero de columna en que est�n los discos.
             i es un valor de {1, 2, 3}. i != j.
   @param j: n�mero de columna a que se llevan los discos.
             j es un valor de {1, 2, 3}. j != i.

   Esta funci�n imprime en la salida est�ndar la secuencia de 
   movimientos necesarios para desplazar los M discos de la
   columna i a la j, observando la restricci�n de que ning�n
   disco se puede situar sobre otro de tama�o menor. Utiliza
   una �nica columna auxiliar.
*/
void hanoi (int M, int i, int j);




void hanoi (int M, int i, int j)
{
  if (M > 0)
    {
      hanoi(M-1, i, 6-i-j);
      //cout << i << " -> " << j << endl;
      hanoi (M-1, 6-i-j, j);
  }
}

int main(int argc, char * argv[])
{
  //Variables para medir el tiempo antes y despu�s de la ejecuci�n del procedimiento que nos interesa.
  clock_t tantes;
  clock_t tdespues;

  //Convertir a entero la variable tipo car�cter del tama�o del vector.

  int M=(atoi(argv[1]));
  do
    {
    //  cout << "N�mero de discos: ";
    //  cin >> M;
    } while (M <= 0);

  tantes = clock();
  hanoi(M, 1, 2);
  tdespues = clock();

  //cout << M <<"\t"<< acumulador/totalEjec << endl;
  cout << M <<"\t"<< (double)(tdespues-tantes) / CLOCKS_PER_SEC << endl;  

  return 0;
}
