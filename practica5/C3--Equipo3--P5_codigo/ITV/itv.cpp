#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <climits>
#include <ctime>

using namespace std;

class ITV {

private:

  vector<int> tiempos;
  vector< vector<int> > coches_listos;
  int lineas, t_min;

public:

  ITV (vector<int> t, int l) {
    lineas = l;
    tiempos = t;
    coches_listos.clear();
    t_min = INT_MAX;
  }

  int get_t_min() {
    return t_min;
  }

  vector< vector<int> > get_coches_listos() {
    return coches_listos;
  }

  // coches_c: coches en cola
  // coches_l: coches listos
  int resolver(vector<int> coches_c, vector< vector<int> > coches_l) {

    vector<int> aux_coches_c;
    vector< vector<int> > aux_coches_l;
    int aux_t, aux_t_max;

    // Hay coches en cola
    if (!coches_c.empty()) {

      aux_coches_c = coches_c;
      aux_coches_c.pop_back();

      for (int i = 0; i < lineas; i++) {
        aux_coches_l = coches_l;
        aux_coches_l[i].push_back(coches_c.back());
        resolver(aux_coches_c, aux_coches_l);
      }

    }
    // No quedan coches en la cola
    else {

      aux_t_max = 0;

      // Calculamos el tiempo
      for (int i = 0; i < lineas; i++) {

        aux_t = 0;

        for (int j = 0; j < (int) coches_l[i].size(); j++) {
          aux_t += tiempos[coches_l[i][j]];
        }

        if (aux_t > aux_t_max) {
          aux_t_max = aux_t;
        }
      }

      if (aux_t_max < t_min) {
        t_min = aux_t_max;
        coches_listos = coches_l;
      }
    }

    return 0;
  }
};

int main(int argc, char const *argv[]) {

  if (argc != 3) {
    cerr << "Parametros: <escenario>.txt <lineas>" << '\n';
    return 1;
  }

  ifstream infile(argv[1]);
  string line;
  int size, aux_n, aux_t, lineas;
  vector<int> coches, coches_encola;
  vector< vector<int> > coches_listos;
  clock_t tantes, tdespues;
  long double tiempo_transcurrido;

  srand(time(0));

  lineas = atoi(argv[2]);

  if (infile.is_open()) {

    infile >> size;

    while (infile >> aux_n >> aux_t) {
      coches.push_back(aux_t);
    }
  }
  else {
    cerr << "Escenario no encontrado" << '\n';
    return 1;
  }

  for (int i = 0; i < lineas; i++) {
    coches_listos.emplace_back();
  }
  coches_listos.back().push_back(size - 1);

  for (int i = 0; i < size - 1; i++) {
    coches_encola.push_back(i);
  }

  /*

  // IMPRESION DE DATOS PREPROCESADO

  int tiempo_total;
  tiempo_total = 0;

  cout << "\n--- DATOS PREPROCESADO ---\n\n";

  cout << "Coche:\tTiempo:\n";

  for (int i = 0; i < (int) coches.size(); i++) {
    cout << i + 1 << '\t' << coches[i] << '\n';
    tiempo_total += coches[i];
  }
  cout << "Tiempo total: " << tiempo_total << '\n';
  cout << '\n';

  cout << "Coches en cola:\n";
  for (int i = 0; i < (int) coches_encola.size(); i++) {
    cout << coches_encola[i] + 1 << ' ';
  }
  cout << "\n\n";

  cout << "Coches listos:\n";
  for (int i = 0; i < (int) coches_listos.size(); i++) {
    cout << "Linea " << i + 1 << ": ";
    if (!coches_listos[i].empty()) {
      for (int j = 0; j < (int) coches_listos[i].size(); j++) {
        cout << coches_listos[i][j] + 1<< ' ';
      }
    }
    else {
      cout << "---";
    }
    cout << '\n';
  }
  cout << '\n';

  // FIN IMPRESION PREPROCESADO

  */

  ITV itv(coches, lineas);

  tantes = clock();

  itv.resolver(coches_encola, coches_listos);

  tdespues = clock();

  tiempo_transcurrido = (double)(tdespues-tantes) / CLOCKS_PER_SEC;

  cout << size << '\t' << tiempo_transcurrido << '\n';

  coches_listos = itv.get_coches_listos();

  /*

  // IMPRESION SOLUCION

  cout << "\n--- SOLUCION ---\n\n";

  cout << "Tiempo solucion: " << itv.get_t_min() << "\n\n";

  for (int i = 0; i < lineas; i++) {
    aux_t = 0;
    cout << "Linea " << i + 1 << ": ";
    for (int j = 0; j < (int) coches_listos[i].size(); j++) {
      cout << coches_listos[i][j] + 1 << ' ';
      aux_t += coches[coches_listos[i][j]];
    }
    cout << "\nTiempo en linea " << i + 1 << ": " << aux_t << "\n\n";
  }

  // FIN IMPRESION SOLUCION

  */

  return 0;
}
