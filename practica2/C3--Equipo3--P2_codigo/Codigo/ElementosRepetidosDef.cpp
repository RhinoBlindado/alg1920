#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <ctime>


using namespace std;

// Umbral determinado haciendo uso del método teórico y el método experimental.
static int UMBRAL = 1310;

//Método auxiliar implementado para generar valores aleatorios para el vector
double uniforme() 
{
  int t = rand();
  double f = ((double)RAND_MAX+1.0);
  return (double)t/f;
}


//Método pertenenciente al algoritmo divide y vencerás.
//Se encarga de unir todos los elementos separados una vez que estos
//se han separado en la primera etapa
vector<int> joinVector(vector<int> &vIzq, vector<int> &vDer){
    int i = 0;
    int j = 0;
    bool fin = false;
    vector<int> Vfinal;

    while(!fin){

    	//Primer caso: El elemento analizado del vector derecho sea mayor que el del izquierdo
        if(vIzq[i] < vDer[j]){
        	//Insertamos el elemento menor en el vector final
            Vfinal.push_back(vIzq[i]);

            //Comprobamos si era el último elemento de este subvector
            //En caso afirmativo, copiamos los elementos del vector derecho en el vector final y salimos del bucle
            if(i == (vIzq.size()-1)){
                fin = true;

                for(int h = j; h < vDer.size(); h++){
                    Vfinal.push_back(vDer[h]);
                }
            }

            //En caso de que no sea el último elemento, incrementamos el indice que se encarga de analizar
            //los valores del vector Vizq, de esta forma seguimos examinando elementos sin salir del bucle
            else i++;
        }

        //Segundo caso: El elemento analizado del vector derecho es menor que el del izquierdo
        else if(vIzq[i] > vDer[j]){
        	//En este caso, insertamos en el elemento de vDer en el vector final
            Vfinal.push_back(vDer[j]);

			//Comprobamos si dicho elemento era el último de este subvector
            //En caso afirmativo, copiamos los elementos del vector izquierdo (vIzq) en el vector final y salimos del bucle
            if(j == (vDer.size()-1)){
                fin = true;

                for(int h = i; h < vIzq.size(); h++){
                    Vfinal.push_back(vIzq[h]);
                }
            }
			//En caso de que no sea el último, incrementamos el indice que se encarga de analizar
            //los valores del vector vDer.
            else j++;
        }

        //Tercer caso: Ambos elementos analizados son el mismo
        else {
        	//En este caso, no importa que elemento insertemos en el vector final, pues ambos son el mismo
        	//pero nos hemos decantado por insertar el de vIzq
            Vfinal.push_back(vIzq[i]);

            //Como en todos los casos anteriores, comprobamos si este era el último elemento del vector para copiar
            //el otro en el final (copia elementos de vDer en Vfinal si no quedan mas elementos en vIzq)
            if(i == (vIzq.size()-1)){
                fin = true;

                for(int h = j+1; h < vDer.size(); h++){
                    Vfinal.push_back(vDer[h]);
                }
            }


            //Aquí realizamos la misma comprobación anterior, solo que en este caso nos centramos en los elementos de vIzq.
            else if(j == (vDer.size()-1)){
                fin = true;

                for(int h = i+1; h < vIzq.size(); h++){
                    Vfinal.push_back(vIzq[h]);
                }
            }

            //Si ninguno de los casos anteriores se ha cumplido, incrementamos el valor de los indices de los vectores para 
            //continuar con el análisis
            else {i++;j++;}

        }

    }

    //Devolvemos el vector unificado 
    return Vfinal;

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

  // Para que funcione debidamente el código FB acoplado al DyV, se debe ordenar el vector saliente.
  int i, j;
  int aux;
  for (i = 0; i < Vaux.size() - 1; i++)
    for (j = Vaux.size() - 1; j > i; j--)
      if (Vaux[j] < Vaux[j-1])
	{
	  aux = Vaux[j];
	  Vaux[j] = Vaux[j-1];
	  Vaux[j-1] = aux;
	}
  
  //devolvemos el vector de elementos no repetidos
  return Vaux;  
}


//Método principal del enfoque "divide y vencerás" empleado para el problema de Elementos repetidos
vector<int> divideyVenceras(vector<int> &V){
	//Obtenemos el tamaño del vector
    int tam = V.size();

    //Si su tamaño es menor que el umbral establecido, se utiliza el algoritmo de Fuerza Bruta.
    if(tam <= UMBRAL)
    {
        return fuerzaBruta(V);
    }
    else
    {
      //Si su tamaño es mayor que 1, dividimos el vector en dos, calculando el nuevo tamaño con una division banal
      int mitadPos = tam/2;
      vector<int> vMitadIzq;
      vector<int> vMitadDer;
      //Ahora, una vez que sabemos el nuevo tamaño que tendrá cada vector dividido, asignamos los valores pertenecientes
      //a las posiciones que se encuentran dentro del rango del nuevo tamaño.
      //De esta forma, creamos dos vectores, uno denominado vMitadIzq, que contiene los valores de la mitad izquierda del
      //vector dividido, y otro denominado vMitadDer, que contiene los valores de la mitad derecha del vector original
      vMitadIzq.assign(V.begin(), V.end()-mitadPos);
      vMitadDer.assign(V.end()-mitadPos, V.end());

      //De forma recursiva, utilizamos el mismo metodo dividide y vencerás para cada nuevo vector divido
      vMitadIzq = divideyVenceras(vMitadIzq);
      vMitadDer = divideyVenceras(vMitadDer);
      //Una vez que tenemos ambos vectores, los unimos con el metodo joinVector
      V = joinVector(vMitadIzq, vMitadDer);
      //Devolvemos el Vector final, que contiene los elementos no repetidos y ordenados
      return V;
    }

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
  //vector<int> ordenado = fuerzaBruta(Voriginal);
  //vector<int> ordenado = divideyVenceras(Voriginal);

/*  for (int j=0; j<n; j++) 
  {
    cout<<Voriginal[j]<<" ";
  }
  cout << endl;
*/
  vector<int> ordenado = divideyVenceras(Voriginal);

  tdespues = clock();
  tiempo_transcurrido = (double)(tdespues-tantes) / CLOCKS_PER_SEC;
/*  
    for (int j=0; j<ordenado.size(); j++) 
  {
    cout<<ordenado[j]<<" ";
  }
  cout << endl;*/
  cout << n << "\t" << tiempo_transcurrido << endl;

}