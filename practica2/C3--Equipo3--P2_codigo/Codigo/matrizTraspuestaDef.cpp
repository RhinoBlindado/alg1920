
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>



// Umbral determinado haciendo uso del método teórico y el método experimental.
 static int UMBRAL = 1024;

//  VERSION FB
//  Funcion que traspone una matriz dinamica dada
//  Esta función realiza la trasposición simplemente colocando el elemento de la posición i,j 
//  de la matriz original en la j,i de la matriz auxiliar, que finalmente igualaremos a la originar para modificarla.
void trasponer(int ** &m, int ci, int cf, int fi, int ff){
      int d = cf - ci + 1;
    //Reserva de espacio para las matrices auxiliares
    int **mt = new int*[d];
    int **m2 = new int*[d];
    for(int i=0; i<d; i++ ){
        mt[i] = new int [d];
        m2[i] = new int [d];
    }
      // Se copia la submatriz a la matriz auxiliar 1
     for(int i=0; i<d; i++){
        for(int j=0; j<d; j++){
            mt[i][j] = m[ci+i][fi+j];
        }
       }

    //Bucles que trasponen la matriz dada realizando el cambio de posiciones anteriormente citado
    for(int i=0; i<d; i++)
    {
      for(int j=0; j<d; j++)
      {
          m2[i][j]=mt[j][i];
      }
    }
    // De la matriz auxiliar 2 se reemplazan valores en la submatriz original.
    for(int i=0; i<d; i++)
    {
      for(int j=0; j<d; j++)
        {
          m[ci+i][fi+j]=m2[i][j];
        }
    }
    // Se liberan de memoria las submatrices.
  for (int i = 0; i < d; i++)
  {
    delete [] mt[i];
    delete [] m2[i];
  }
  delete [] mt;
  delete [] m2;
}

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
int mtdyv (int **&m, int ci, int cf, int fi, int ff) {

  int aux, d;

  // Cálculo de la dimensión de la matriz
  d = cf - ci + 1;
  //cout <<"dim="<<d<<endl;
  // Caso base al alcanzar umbral.
  if (d <= UMBRAL ) {
    // Se utiliza la versión Fuerza Bruta

    trasponer(m, ci, cf, fi, ff);
  }
  else {

    // Divido la matriz en en cuatro submatrices
    // m1 m2
    // m3 m4
    // m1
    mtdyv(m, ci, ci+d/2-1, fi, fi+d/2-1);
    mtdyv(m, ci+d/2, cf, fi, fi+d/2-1);
    mtdyv(m, ci, ci+d/2-1, fi+d/2, ff);
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


  } 
  //else

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
      matriz[i][j] = rand()%10;
    }
  }

  for (int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
    {
      cout << matriz[i][j] << " ";
      if (j == dim-1)
        cout << endl;
    }
  }
  cout << endl << endl;


  tantes = clock();

  // Llamada a la función para trasponer la matriz de Divide y Vencerás
  err = mtdyv(matriz, 0, dim-1, 0, dim-1);

  tdespues = clock();

  // Calcular tiempo transcurrido
  tiempo_transcurrido = (double)(tdespues-tantes) / CLOCKS_PER_SEC;

  cout << dim << "\t" << tiempo_transcurrido << endl;

  for (int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
    {
      cout << matriz[i][j] << " ";
      if (j == dim-1)
        cout << endl;
    }
  }
  cout << endl << endl;





  //Liberar memoria de la matriz
  for (int i = 0; i < dim; i++)
    delete [] matriz[i];

  delete [] matriz;
}
