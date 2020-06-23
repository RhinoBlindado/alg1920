#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <ctime>


using namespace std;

//Método auxiliar implementado para generar valores aleatorios para el vector
double uniforme() 
{
  int t = rand();
  double f = ((double)RAND_MAX+1.0);
  return (double)t/f;
}


//Método implementado para eliminar elementos repetidos usando el enfoque denominado "Fuerza bruta"
vector<int> fuerzaBruta(vector<int> &V){
  vector<int> Vaux;
  int k=0;
  bool encontrado;


  //Como vamos a suponer que no importa si el vector está ordenado, añadiremos el primer valor del mismo a uno auxiliar en el 
  //cual se van a incluir todos los elementos no repetidos
   Vaux.push_back(V[0]);
  
  //Realizaremos un bucle para analizar si un elemento que ya hemos incluido en Vaux (vector auxiliar) se encuentra repetido en
  //vector original
  for(int i = 1; i < V.size(); i++){
    int j =0;
    encontrado = false;

    //El análisis de valores se realiza dentro de este bucle, en caso de que los valores de vAux y V sean iguales en un índice analizado,
    //salimos de este while y pasamos al siguiente valor del vector original a analizar.
    //Si no son valores iguales, incrementamos el indice del vector auxiliar para seguir comparando con los demas elementos considerados
    //como no repetidos
    while(j <= k and !encontrado){
      if(V[i] == Vaux[j])
        encontrado=true;
      else j++;
    }

    //Si hemos terminado la comprobación de todos los elementos no repetidos y no hemos encontrado ninguno igual en dicho vector,
    //añadimos el elemento analizado a Vaux y pasa a ser considerado como elemento no repetido.
    if(!encontrado){
      k++;
      Vaux.push_back(V[i]);
    }

  }
  
  //devolvemos el vector de elementos no repetidos
  return Vaux;  
}

int main(int argc, char * argv[])
{
  vector<int> Voriginal;
  clock_t tantes, tdespues;
  long double tiempo_transcurrido;

  //Comprobamos que la entrada de los datos es correcta y obtenemos los parametros deseados
  if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }
    int n = atoi(argv[1]);

    int * T = new int[n];
    assert(T);

  srand(time(0));

  //Creamos un vector con elementos aleatorios
  for (int j=0; j<n; j++) 
  {
    double u=uniforme();
    int k=(int)(n*u);
    T[j]=k;
  }

  //Pasamos dicho vector al Vector original que vamos a analizar
  for (int j=0; j<n; j++) 
  {
    Voriginal.push_back(T[j]);
  }

// INICIO CODIGO
  //Generar(Voriginal);
  tantes = clock();
  //Realizamos la función principal del programa utilizando el enfoque deseado
  vector<int> ordenado = fuerzaBruta(Voriginal);
  tdespues = clock();
  tiempo_transcurrido = (double)(tdespues-tantes) / CLOCKS_PER_SEC;
  
  cout << n << "\t" << tiempo_transcurrido << endl;

}