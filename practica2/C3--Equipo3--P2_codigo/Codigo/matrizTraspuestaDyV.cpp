
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

// VERSION DYV
// Función que cobierte una matriz en su traspuesta siguiendo el método
// de Divide y Vencerás dividiendo la matriz en cuatro submatrices de la misma
// dimensión y cada una de estas realiza una llamada a esta función, se dividen
// en cuatro submatrices nuevamente hasta llegar al caso base de ser una matriz
// 2x2. Una vez que conseguido esto se reordenan las submatrices necesarias para
// así llegar a la matriz traspuesta de la matriz inicial.
// m : puntero a la matriz a trasponer que al final de la ejecución será la matriz traspuesta
// ci : índice de la columna inicial de la matriz a trasponer (en el caso inicial normalmente será 0)
// cf : índice de la columna final de la matriz  a trasponer (en el caso inicial normalmente será la dimensión de la matriz menos uno)
// fi : índice de la fila inicial de la matriz a trasponer (en el caso inicial normalmente será 0)
// ff : índice de la fila final de la matriz a trasponer (en el caso inicial normalmente será la dimensión de la matriz menos uno)
int mtdyv (int **m, int ci, int cf, int fi, int ff) {

  int aux, d;

  // Cálculo de la dimensión de la matriz
  d = cf - ci + 1;

  // Caso base matriz 2x2
  if (d == 2) {

    // Realizamos el intercambio en el caso de la matriz base:
    // a b
    // c d
    // Cambiamos 'c' por 'b':
    // a c
    // b d
    aux = m[cf][fi];
    m[cf][fi] = m[ci][ff];
    m[ci][ff] = aux;
  }
  else {

    // Divido la matriz en en cuatro submatrices
    // m1 m2
    // m3 m4
    // m1
    mtdyv(m, ci, ci+d/2-1, fi, fi+d/2-1);
    // m2
    mtdyv(m, ci+d/2, cf, fi, fi+d/2-1);
    // m3
    mtdyv(m, ci, ci+d/2-1, fi+d/2, ff);
    // m4
    mtdyv(m, ci+d/2, cf, fi+d/2, ff);

    // Inetrcambio posiciones
    // m1 m3
    // m2 m4
    for (int i = 0; i < d/2; i++) {
      for (int j = 0; j < d/2; j++) {
        aux = m[ci+d/2+i][fi+j];
        m[ci+d/2+i][fi+j] = m[ci+i][fi+d/2+j];
        m[ci+i][fi+d/2+j] = aux;
      }
    }
  } //else

  return 0;
}

int main(int argc, char **argv) {

  int dim, err;
  int **matriz;
  clock_t tantes, tdespues;
  long double tiempo_transcurrido;

  err = 0;

  // Lectura de los parametros de entrada
  if (argc != 2)
  {
    cout << "Parametros de entrada: " << endl
    << "1.- Dimension de la matriz" << endl << endl;
    return 1;
  }

  srand(time(0));

  // Creación de la matriz
  dim = atoi(argv[1]);
  matriz = new int*[dim];
  assert(matriz);
  for (int i = 0; i < dim; i++)
  {
    matriz[i] = new int[dim];
    assert(matriz[i]);
  }

  // Rellenar matriz de elementos aleatorios
  for (int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
    {
      matriz[i][j] = rand() % 10;
    }
  }

  tantes = clock();

  // Llamada a la función para trasponer la matriz de Divide y Vencerás
  err = mtdyv(matriz, 0, dim-1, 0, dim-1);

  tdespues = clock();

  // Calcular tiempo transcurrido
  tiempo_transcurrido = (double)(tdespues-tantes) / CLOCKS_PER_SEC;

  cout << dim << "\t" << tiempo_transcurrido << endl;

  //Liberar memoria de la matriz
  for (int i = 0; i < dim; i++)
    delete [] matriz[i];

  delete [] matriz;
}
