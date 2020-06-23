/**
   @file Resoluci�n del problema de las Torres de Hanoi
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
      hanoi (M-1, 6-i-j, j);
  }
}

int main(int argc, char ** argv)
{
  int M;
  int dim;
  clock_t tantes, tdespues;
  long double tiempo_transcurrido;

  tiempo_transcurrido = 0.0;

  //Lectura de los parametros de entrada
  if (argc != 2)
    {
      cout << "Parametros de entrada: " << endl
	   << "1.- Numero de discos" << endl << endl;
      return 1;
    }


  dim = atoi(argv[1]);
  M = dim;

  tantes = clock();

  hanoi(M, 1, 2);

  tdespues = clock();

  tiempo_transcurrido = (double)(tdespues-tantes) / CLOCKS_PER_SEC;

  cout << dim << "\t" << tiempo_transcurrido << endl;

  return 0;
}
