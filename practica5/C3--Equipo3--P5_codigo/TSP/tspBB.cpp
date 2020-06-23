#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <math.h>
#include <sstream>
#include <ctime>

using namespace std;

class TSP {

private:

  vector< vector<int> > distancias;
  int distancia_sol;
  vector<int> camino_sol;
  int nodos_expandidos;
  int n_podas;

  vector<int> ordenar_prioridad (int ciudad, vector<int> ciudades_sinvisitar) {

    int aux;

    for (int i = 0; i < (int) ciudades_sinvisitar.size() - 1; i++) {
      for (int j = i; j < (int) ciudades_sinvisitar.size() - 1; j++) {
        if (distancias[ciudades_sinvisitar[j]][ciudad] > distancias[ciudades_sinvisitar[j+1]][ciudad]) {
          aux = ciudades_sinvisitar[j];
          ciudades_sinvisitar[j] = ciudades_sinvisitar[j+1];
          ciudades_sinvisitar[j+1] = aux;
        }
      }
    }

    return ciudades_sinvisitar;
  }

public:

  int calcular_distancia(float x1, float x2, float y1, float y2) {
    return (int) round((sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))));
  }

  int menor_arista(int nodo) {
    int arista_menor;
    arista_menor = INT_MAX;
    for (int i = 0; i < (int) distancias[nodo].size(); i++) {
      if (arista_menor > distancias[nodo][i]) {
        arista_menor = distancias[nodo][i];
      }
    }
    return arista_menor;
  }

  int get_nodos_expandidos() {
    return nodos_expandidos;
  }

  int get_n_podas() {
    return n_podas;
  }

  int get_distancia_sol() {
    return distancia_sol;
  }

  vector<int> get_camino_sol() {
    return camino_sol;
  }

  TSP (vector<float> x, vector<float> y, vector<int> ciudades) {

    int dimension;

    camino_sol.clear();

    distancias.clear();

    dimension = (int) x.size();
    distancias.resize(dimension);

    for (int i = 0; i < dimension; i++) {
      for (int j = 0; j < dimension; j++) {
        distancias[i].push_back(calcular_distancia(x[i], x[j], y[i], y[j]));
      }
    }

    distancia_sol = greedy(ciudades);

    cout<<"Distancia Inicial:"<<distancia_sol<<endl;

    nodos_expandidos = 0;
    n_podas = 0;
  }

  // ciudades_visitadas: camino solucion
  // ciudades_sinvisitar: ciudades para anadir a la solucion
  // distancia_visitadas: distancia de camino solucion
  // distancia_estimada_opt: distancia estiamada optimista de las ciudades para anadir a la solucion
  // Estado inicial ejemplo con 5 nodos:
  // ciudades_visitadas: {5}
  // ciudades_sinvisitar: {1,2,3,4}
  // distancia_visitadas: 0
  // distancia_estimada_opt: opt(1) + opt(2) + opt(3) + opt(4)
  //                         opt(x): distancia desde x a y, siendo y la ciudad más cercana a x
  //                                 y pertenece al conjunto de todas las ciudades
  int resolver(vector<int> ciudades_visitadas, vector<int> ciudades_sinvisitar, int distancia_visitadas, int distancia_estimada_opt) {

    vector<int> aux_ciudades_visitadas, aux_ciudades_sinvisitar;
    int distancia_total, aux_distancia_estimada_opt;

    // Si todavía quedan ciudades por visitar
    if (!ciudades_sinvisitar.empty()) {

      // Ordenamos la cola segun prioridad
      ciudades_sinvisitar = ordenar_prioridad(ciudades_visitadas.back(), ciudades_sinvisitar);

      aux_ciudades_visitadas = ciudades_visitadas;

      // Para cada ciudad que quede por visitar
      for (int i = 0; i < (int) ciudades_sinvisitar.size(); i++) {

        distancia_total = 0;

        aux_ciudades_visitadas = ciudades_visitadas;
        aux_ciudades_visitadas.push_back(ciudades_sinvisitar[i]);
        aux_ciudades_sinvisitar = ciudades_sinvisitar;
        aux_ciudades_sinvisitar.erase(aux_ciudades_sinvisitar.begin()+i);
        // Calculamos la distancia real que tendremos en el camino al añadir la ciudad i de las ciudades sin visitar
        distancia_total += distancia_visitadas + distancias[ciudades_visitadas.back()][aux_ciudades_visitadas.back()];
        // Calculamos la distancia estimada mas optimista del resto de ciudades
        aux_distancia_estimada_opt = distancia_estimada_opt - menor_arista(aux_ciudades_visitadas.back());

        // Si la distancia real mas la distancia estimada son menores que la solucion real que tenemos resolvemos
        if (distancia_total + aux_distancia_estimada_opt < distancia_sol) {
          nodos_expandidos++;
          resolver(aux_ciudades_visitadas, aux_ciudades_sinvisitar, distancia_total, aux_distancia_estimada_opt);
        }
        // Si no podamos la rama
        else {
          n_podas++;
        }
      }
    }
    // No quedan ciudades por visitar, estamos en un nodo hoja
    else {

      distancia_total = 0;

      // Calculamos la distancia total del camino
      for (int i = 0; i < (int) ciudades_visitadas.size()-1; i++) {
        distancia_total += distancias[ciudades_visitadas[i]][ciudades_visitadas[i+1]];
      }
      // Unimos con el principio
      distancia_total += distancias[ciudades_visitadas.front()][ciudades_visitadas.back()];

      // Si la distancia calculada es menor que la mejor solucion obtenida esta pasa a ser la mejor solucion obtenida
      if (distancia_total < distancia_sol) {
        distancia_sol = distancia_total;
        camino_sol = ciudades_visitadas;
      }
    }

    return 0;
  }


  int greedy(vector<int> ciudades)
  {
  //  Declaración de variables auxiliares para Greedy.
      int distanciaMin,
          distanciaAct,
          indiceCiudad,
          camino = 0;

  //  Declaración de los nodos (ciudades) auxiliares para Greedy
      int nodoIni = ciudades[0],
          nodoVec,
          nodoFin = nodoIni;

  //  El vector Ciudades es la lista de Candidatos, se elimina el vector de inicio.
      ciudades.erase(ciudades.begin());

  //  Mientras queden Candidatos
      while (!ciudades.empty())
      {
  //      Tomando la ciudad actualmente elegida, se itera en el vector de Candidatos buscando otra ciudad que tiene la distancia más corta hacia ella.
  //      Si existen dos o más con la misma distancia, se toma la primera.
          distanciaMin = INT_MAX;
          for (int i = 0; i < (int) ciudades.size(); i++)
          {
              distanciaAct = distancias[nodoIni][ciudades[i]];

              if(distanciaMin > distanciaAct && nodoIni != i)
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
          nodoIni = nodoVec;

  //      Se elimina la ciudad más cercana de los candidatos, para evitar pasar por el mismo sitio dos veces.
          ciudades.erase(ciudades.begin() + indiceCiudad);
      }

  //  Calcular el camino de la ultima ciudad elegida y el comienzo, lo que finaliza el recorrido y se almacena también en la solución.
      camino += distancias[nodoIni][nodoFin];

      return camino;
    }

};

int main(int argc, char const *argv[]) {

  // Lectura de los parametros de entrada
  if (argc != 2)
  {
    cout << "Parametros de entrada: " << endl << "1.- Nombre del fichero TSP" << endl << endl;
    return 1;
  }

  ifstream infile(argv[1]);
  istringstream aux_stringstream;
  string line, text;
  int aux, dimension;
  float var1, var2, var3;
  vector<float> x, y;
  vector<int> n;
  vector<int> ciudades_visitadas, ciudades_sinvisitar;

  if (infile.is_open()) {
    while (line.compare("NODE_COORD_SECTION") != 0) {
      getline(infile, line);
      aux = line.find("DIMENSION");
      if (aux != -1) {
        aux = line.find(":");
        aux_stringstream.str(line.substr(aux+1,-1));
        aux_stringstream >> dimension;
      }
    }
  }
  else {
    cout << "Archivo no encontrado" << endl;
  }

  // Lectura del número del nodo, su posición x e y
  for (int i = 0; i < dimension; i++) {
    infile >> var1 >> var2 >> var3;
    n.push_back(var1-1);
    x.push_back(var2);
    y.push_back(var3);
  }

  infile.close();

  srandom(time(0));

  ciudades_sinvisitar = n;
  ciudades_sinvisitar.pop_back();
  ciudades_visitadas.push_back(n.back());
  int distancia_estimada_opt;
  distancia_estimada_opt = 0;

  TSP tsp(x, y, n);
  for (int i = 0; i < (int) ciudades_sinvisitar.size(); i++) {
    distancia_estimada_opt += tsp.menor_arista(ciudades_sinvisitar[i]);
  }

  clock_t t_inicial = clock();

  tsp.resolver(ciudades_visitadas, ciudades_sinvisitar, 0, distancia_estimada_opt);

  clock_t t_final = clock();

  cout << "Tiempo Ejecucion: " << ((double)(t_final - t_inicial)) / CLOCKS_PER_SEC << endl;
  cout << "Nodos expandidos: " << tsp.get_nodos_expandidos() << '\n';
  cout << "Numero de podas: " << tsp.get_n_podas() << '\n';
  cout << "Distancia solucion: " << tsp.get_distancia_sol() << '\n';
  ciudades_visitadas = tsp.get_camino_sol();
  for (int i = 0; i < (int) ciudades_visitadas.size(); i++) {
    cout << ciudades_visitadas[i]+1 <<"\t"<<x[ciudades_visitadas[i]]<<"\t"<<y[ciudades_visitadas[i]]<<endl;
  }
    cout << ciudades_visitadas[0]+1 <<"\t"<<x[ciudades_visitadas[0]]<<"\t"<<y[ciudades_visitadas[0]]<<endl;
  return 0;
}
