#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <math.h>
#include <sstream>

using namespace std;

class TSP {

private:

  vector< vector<int> > distancias;
  int distancia_sol;
  vector<int> camino_sol;

public:

  int calcular_distancia(float x1, float x2, float y1, float y2) {
    return (int) round((sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))));
  }

  int get_distancia_sol() {
    return distancia_sol;
  }

  vector<int> get_camino_sol() {
    return camino_sol;
  }

  TSP (vector<float> x, vector<float> y) {

    int dimension;

    distancia_sol = INT_MAX;

    camino_sol.clear();

    distancias.clear();

    dimension = (int) x.size();
    distancias.resize(dimension);

    for (int i = 0; i < dimension; i++) {
      for (int j = 0; j < dimension; j++) {
        distancias[i].push_back(calcular_distancia(x[i], x[j], y[i], y[j]));
      }
    }
  }

  int resolver(vector<int> ciudades_visitadas, vector<int> ciudades_sinvisitar) {

    vector<int> aux_ciudades_visitadas, aux_ciudades_sinvisitar;
    int distancia_total;

    if (!ciudades_sinvisitar.empty()) {

      aux_ciudades_visitadas = ciudades_visitadas;

      for (int i = 0; i < (int) ciudades_sinvisitar.size(); i++) {

        aux_ciudades_visitadas = ciudades_visitadas;
        aux_ciudades_visitadas.push_back(ciudades_sinvisitar[i]);
        aux_ciudades_sinvisitar = ciudades_sinvisitar;
        aux_ciudades_sinvisitar.erase(aux_ciudades_sinvisitar.begin()+i);
        resolver(aux_ciudades_visitadas, aux_ciudades_sinvisitar);
      }
    }
    else {

      distancia_total = 0;

      for (int i = 0; i < (int) ciudades_visitadas.size()-1; i++) {
        distancia_total += distancias[ciudades_visitadas[i]][ciudades_visitadas[i+1]];
        //std::cout << ciudades_visitadas[i] + 1 << ' ';
      }
      //std::cout << ciudades_visitadas.back() + 1 << '\n';
      distancia_total += distancias[ciudades_visitadas.front()][ciudades_visitadas.back()];

      if (distancia_total < distancia_sol) {
        distancia_sol = distancia_total;
        camino_sol = ciudades_visitadas;
      }
    }

    return 0;
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
   // std::cout << var1 - 1 << '\n';
  }

  infile.close();

  ciudades_sinvisitar = n;
  ciudades_sinvisitar.pop_back();
  ciudades_visitadas.push_back(n.back());

  TSP tsp(x, y);
  clock_t t_inicial = clock();
  tsp.resolver(ciudades_visitadas, ciudades_sinvisitar);
  clock_t t_final = clock();

  cout << "Tiempo: " << ((double)(t_final - t_inicial)) / CLOCKS_PER_SEC << endl;
  cout << "Distancia solucion: " << tsp.get_distancia_sol() << '\n';
  ciudades_visitadas = tsp.get_camino_sol();
  for (int i = 0; i < (int) ciudades_visitadas.size(); i++) {
    cout << ciudades_visitadas[i]+1 <<"\t"<<x[ciudades_visitadas[i]]<<"\t"<<y[ciudades_visitadas[i]]<<endl;
  }
  cout << ciudades_visitadas[0]+1 <<"\t"<<x[ciudades_visitadas[0]]<<"\t"<<y[ciudades_visitadas[0]]<<endl;
  return 0;
}
