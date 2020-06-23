/**
   @file Ordenaci�n por burbuja
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
#include <cstdlib>
#include <climits>
#include <cassert>






/* ************************************************************ */ 
/*  M�todo de ordenaci�n por burbuja  */

/**
   @brief Ordena un vector por el m�todo de la burbuja.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: n�mero de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo de la burbuja.
*/
inline static 
void burbuja(int T[], int num_elem);



/**
   @brief Ordena parte de un vector por el m�todo de la burbuja.

   @param T: vector de elementos. Tiene un n�mero de elementos 
                   mayor o igual a final.Es MODIFICADO.

   @param inicial: Posici�n que marca el incio de la parte del
                   vector a ordenar.
   @param final: Posici�n detr�s de la �ltima de la parte del
                   vector a ordenar. 
		   inicial < final.

   Cambia el orden de los elementos de T entre las posiciones
   inicial y final - 1de forma que los dispone en sentido creciente
   de menor a mayor.
   Aplica el algoritmo de la burbuja.
*/
static void burbuja_lims(int T[], int inicial, int final);



/**
   Implementaci�n de las funciones
**/

inline void burbuja(int T[], int num_elem)
{
  burbuja_lims(T, 0, num_elem);
};


static void burbuja_lims(int T[], int inicial, int final)
{
  int i, j;
  int aux;
  for (i = inicial; i < final - 1; i++)
    for (j = final - 1; j > i; j--)
      if (T[j] < T[j-1])
	{
	  aux = T[j];
	  T[j] = T[j-1];
	  T[j-1] = aux;
	}
}


int main(int argc, char * argv[])
{

  //Variables para medir el tiempo antes y despu�s de la ejecuci�n del procedimiento que nos interesa.
  clock_t tantes;
  clock_t tdespues;

  //Convertir a entero la variable tipo car�cter del tama�o del vector.
  int n=(atoi(argv[1]));

  //cout << "Introduce n�mero de elementos del vector: ";
  //cin >> n;

  int * T = new int[n];
  assert(T);

  double acumulador = 0, totalEjec = 10;
  for (int j = 0; j < (int)totalEjec; j++)
  {    
    srandom(time(0));
    for (int i = 0; i < n; i++)
      {
        T[i] = random();
      };

    //Medir el tiempo antes y despu�s de la ejecuci�n del algoritmo.
    tantes = clock();
    burbuja(T, n);
    tdespues = clock();

    acumulador = acumulador + ((double)(tdespues-tantes) / CLOCKS_PER_SEC);
   // cout << "acumulador: " << acumulador <<" tiempo it actual: "<< ((double)(tdespues-tantes) / CLOCKS_PER_SEC)<<endl;
  }
  //Imprimir a pantalla el n�mero de elementos y el tiempo en segundos.
  cout << n <<"\t"<< acumulador/totalEjec << endl;

  delete [] T;

  return 0;
};
