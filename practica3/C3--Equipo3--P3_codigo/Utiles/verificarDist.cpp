/*ES:   Asignatura: Algoritmica
        Trabajo: Practica 3 - Greedy
        Descripción: Verificar distancias
		*/ 



//  LIBRERIAS
//      Entrada/Salida
#include <iostream>
//      Abrir archivos
#include <fstream>
//      Procesado de Cadenas
#include <string>
#include <sstream>
//      Hacer operaciones matematicas
#include <cmath>
//      Obtener el MAX_FLT
#include <cfloat>

using namespace std;

int calcularDistancia(float x2, float x1, float y2, float y1)
{
    return (int)(round ( sqrt( pow(x2 - x1, 2) + pow(y2 - y1, 2) ) ) );
}

int main(int argc, char * argv[])
{
    float **matrizNXY;
	int dim;
    cin >> dim;

    matrizNXY = new float*[dim];
    float a,b,c;
    for(int i=0; i<dim; i++)
    {
        cin >> a >> b >> c;

        matrizNXY[i] = new float[3];
        matrizNXY[i][0] =a;
        matrizNXY[i][1] =b;
        matrizNXY[i][2] =c;
    }
    
    int camino = 0;

    for (int i = 0; i < dim-1; i++)
    {
        camino += calcularDistancia(matrizNXY[i+1][1], matrizNXY[i][1], matrizNXY[i+1][2], matrizNXY[i][2]);
    }
    camino += calcularDistancia(matrizNXY[0][1], matrizNXY[dim-1][1], matrizNXY[0][2], matrizNXY[dim-1][2]);

    cout <<"CAMINO OPTIMO: "<<camino<<endl
         <<"INICIO_CAMINO_OPTIMO"<<endl;

    for (int i = 0; i < dim; i++)
    {
        cout << matrizNXY[i][0] << "\t" << matrizNXY[i][1] << "\t" << matrizNXY[i][2] << endl;
    }
    
// Eliminar la matriz.
 for (int i = 0; i < dim; i++)
 {
    delete [] matrizNXY[i];
 }

  delete [] matrizNXY;
}