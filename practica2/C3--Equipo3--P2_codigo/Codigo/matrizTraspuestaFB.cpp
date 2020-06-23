//Programa que prueba la funcionalidad de la funcion trasponer(implementada abajo)
//Este programa se ha compilado con la orden g++ -o matrizTraspuestaFB matrizTraspuestaFB.cpp 


#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


/*
Funcion que devuelve la traspuesta de una matriz dinamica dada
Esta función realiza la trasposición simplemente colocando el elemento de la posición i,j 
de la matriz original en la j,i de la matriz a devolver

*/
void trasponer(int **&m, int dim){
    //Reserva de espacio para la matriz traspuesta
    int **mt = new int*[dim];
    for(int i=0; i<dim; i++ ){
        mt[i] = new int [dim];
    }
    //Bucles que trasponen la matriz dada realizando el cambio de posiciones anteriormente citado
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            mt[i][j]=m[j][i];
        }
    }
    m = mt;
}

int main(int argc, char ** argv){

    
    
    //Comprobación de argumentos, ya que este programa solo admite un argumento, que será la dimensión de la matriz de entrada
    if(argc != 2){
        cout << "El programa solo recibe un parametro\n";
        return 1;
    }
    int util = atoi(argv[1]);

    clock_t tantes, tdespues;
    //Reserva de espacio para la matriz dinamica
    int **matriz = new  int*[util];
    for(int i=0; i<util; i++ ){
        matriz[i] = new int [util];
    }
    srand(time(NULL));
    //Rellenamos la matriz con numeros aleatorios
    for(int i=0; i<util; i++){
        for(int j=0; j<util; j++){
            matriz[i][j]=random() % 10;
        }
    }


/*  for (int i = 0; i < util; i++)
  {
    for (int j = 0; j < util; j++)
    {
      cout << matriz[i][j] << " ";
      if (j == util-1)
        cout << endl;
    }
  }
  cout << endl << endl;
*/

    //Medir el tiempo quee tarda en ejecutarse el método 
    tantes=clock();
    trasponer(matriz, util);
    tdespues=clock();
    
    //Mostrar el resultado, con la dimensión 
    cout << util << "\t" << (double)(tdespues-tantes) / CLOCKS_PER_SEC << endl;

    /*
    for (int i = 0; i < util; i++)
    {
        for (int j = 0; j < util; j++)
        {
          cout << traspuesta[i][j] << " ";
          if (j == util-1)
            cout << endl;
         }
    }
    cout << endl << endl;
    */

    //Liberar memoria de las matrices

    for (int i = 0; i < util; i++)
        delete [] matriz[i];

    delete [] matriz;
    
    
}
