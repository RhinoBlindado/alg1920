/*ES:   Asignatura: Algoritmica
        Trabajo: Practica 3 - Greedy
        Descripcion: TSP con método de Cercanía */ 

// LIBRERIAS
//      Entrada/Salida
#include <iostream>
//      Vectores
#include <vector>
//      Abrir archivos
#include <fstream>
//      Procesado de Cadenas
#include <string>
#include <sstream>
//      Hacer operaciones matematicas
#include <cmath>
//      Obtener el MAX_INT
#include <climits>

using namespace std;

//  CONTENEDOR
struct nodo
{
    int indice;
    double x;
    double y;
};

//  FUNCIONES
//      Funcion auxiliar para calcular distancia euclidea entre dos puntos.
int calcularDistancia(double x2, double x1, double y2, double y1)
{
    return  (int)round( ( sqrt( pow(x2 - x1, 2) + pow(y2 - y1, 2) ) ) ) ;
}

//  Funcion TSP Greedy por Cercanía
/*  Entrada: Vector de ciudades de entrada, de salida, ciudad inicial, camino.

    Funcionamiento: Dada la lista de ciudades, se toma una para que sea la inicial; esta se borra de la lista 
    y se añade a la solución como el inicio del camino. Al iniciar el bucle, se calcula que ciudad de las que 
    están en la lista de ciudades queda más cerca; al obtenerse se almacena en la solución, se suma la distancia y 
    se elimina de los candidatos. Esto se realiza hasta que no queden más ciudades candidatas.
    Luego, se conecta la última ciudad con la primera de todas para cerrar el camino y se suma la distancia correspondiente.
*/
void tspCercania(vector<nodo> ciudades, vector<nodo> &tour, int inicio, int &camino)
{
//  Declaración de variables auxiliares para Greedy.
    int dim = ciudades.size(),
        distanciaMin,
        distanciaAct,
        indiceCiudad;

//  Declaración de los nodos (ciudades) auxiliares para Greedy
    nodo nodoIni = ciudades[inicio],
         nodoVec, 
         nodoFin = nodoIni;

//  Inicializar la lista de soluciones Tour con la ciudad inicial.
    tour.push_back(ciudades[inicio]);

//  El vector Ciudades es la lista de Candidatos, se elimina el vector de inicio.
    ciudades.erase(ciudades.begin() + inicio);

//  Mientras queden Candidatos
    while (!ciudades.empty())
    {
//      Tomando la ciudad actualmente elegida, se itera en el vector de Candidatos buscando otra ciudad que tiene la distancia más corta hacia ella.
//      Si existen dos o más con la misma distancia, se toma la primera.
        distanciaMin = INT_MAX;
        for (int i = 0; i < (int)ciudades.size(); i++)
        {
            distanciaAct = calcularDistancia(ciudades[i].x, nodoIni.x, ciudades[i].y, nodoIni.y);   
            if(distanciaMin > distanciaAct)
            {
//              Se actualiza la distancia minima hasta obtener la mas pequeña de todas y también el nodo asociado a ella.
                distanciaMin = distanciaAct;
                nodoVec = ciudades[i];
                indiceCiudad = i;
            }
        }
//      Se suma la distancia mínima en al camino
        camino += distanciaMin;

//      Se añade la ciudad más cercana a la solución y ahora se busca otra ciudad cercana a esta última.
        tour.push_back(nodoVec);
        nodoIni = nodoVec;

//      Se elimina la ciudad más cercana de los candidatos, para evitar pasar por el mismo sitio dos veces.
        ciudades.erase(ciudades.begin() + indiceCiudad);
    }

//  Calcular el camino de la ultima ciudad elegida y el comienzo, lo que finaliza el recorrido y se almacena también en la solución.
    camino += calcularDistancia(tour[dim-1].x, nodoFin.x, tour[dim-1].y, nodoFin.y);
    tour.push_back(nodoFin);
}

//      Funcion Main
int main(int argc, char * argv[])
{
    // Verificacion de que está el archivo de entrada
    if (argc != 2)
    {
      cerr << "Formato: ./" << argv[0] << " <rutaArchivo.tsp>" << endl;
      return -1;
    }

    //      Lectura de archivo:
    // Cantidad de nodos.
    int dim;
    // Estructura para contener las ciudades de entrada y el resultado.
    vector<nodo> ciudades, tour;
    // Cadenas para procesar entrada.
    string linea = "";
    istringstream aux2;
    // Abrir el archivo.
    ifstream archivo (argv[1]);
    if (archivo.is_open())
    {
        int aux;
        while (linea.compare("NODE_COORD_SECTION") != 0)
        {
            getline(archivo,linea);
            aux = linea.find("DIMENSION");
            if(aux != -1)
            {
                aux = linea.find(":");
                aux2.str(linea.substr(aux+1,-1));
                aux2 >> dim;
            }
        }

        ciudades.resize(dim);
        int a;
        double b,c;
        for(int i=0; i<dim; i++)
        {
            archivo >> a >> b >> c;
            ciudades[i].indice = a;
            ciudades[i].x = b;
            ciudades[i].y = c;
        }
        archivo.close();
    }
    else cout << "No se puede abrir el archivo."; 

    //  Inicializar el camino.
    int camino = 0;
    //  Llamar a la función.
    tspCercania(ciudades,tour, 0, camino);

    //  Imprimir resultado del Greedy
    cout <<"CAMINO: "<< camino << endl
            <<"INICIO_CAMINO_CERCANIA"<< endl;

    for (int i = 0; i < (int)tour.size(); i++)
    {
        cout <<tour[i].indice<<"\t" <<tour[i].x<<"\t"<<tour[i].y<<endl;
    }

  return 0;
}
