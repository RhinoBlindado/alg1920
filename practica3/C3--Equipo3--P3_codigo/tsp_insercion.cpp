 //Uso ./<nombre_ejecutable> <arhchivo.tsp>

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

int calcularDistancia(float x2, float x1, float y2, float y1){
    return (int)(round ( sqrt( pow(x2 - x1, 2) + pow(y2 - y1, 2) ) ) );
}

class nodo{
    private:
        int node;
        float coord, section;
    public:
        int getNode(){return node;}
        float getCoord(){return coord;}
        float getSection(){return section;}
        void setNode(int n){node = n;}
        void setCoord(float n){coord=n;}
        void setSection(float n){section=n;}
        int distancia(nodo n2){
            return (int) round(sqrt(pow(n2.getCoord()-getCoord(),2)+pow(n2.getSection()-getSection(),2)));
        }   
        bool operator==(const nodo & n){
            bool iguales = false;
            if(n.coord == coord && n.node == node && n.section == section)
                iguales = true;
            return iguales;
        }
};

class GrafoTSP{
    private:
        vector<nodo> v;
    public:
        GrafoTSP(){}

        void reservar(int a){ v.resize(a);}

        int size(){return v.size();}

        nodo detectarNodo(int a){
            nodo n;
            bool encontrado = false;
            for(vector<nodo>::iterator i=v.begin(); i != v.end() && !encontrado; ++i){
                if (a == (*i).getNode()){
                    encontrado = true;
                    n = *i;
                }
            }
            return n;
        }

        void eliminar(nodo n){
            bool eliminado=false;
            for(vector<nodo>::iterator i=v.begin(); i!= v.end() && !eliminado; ++i){
                if(n.getNode() == i->getNode()){
                    v.erase(i);
                    eliminado=true;
                }
            }
        }
        //Insertar nodo n, delante del nodo n1
        void insertar(nodo n, nodo n1){
            bool insertado = false;
            for(vector<nodo>::iterator i=v.begin(); i!=v.end() && !insertado; ++i){
                if(n1==(*i)){
                    v.insert(i, n);
                    insertado = true;
                }
            }
        }

        //Menor distancia desde el nodo n, hasta el nodo "menor" 
        void menorDistancia(nodo &n, float &dist_menor, nodo &menor){
            bool primera = true;
            for(vector<nodo>::iterator i=v.begin(); i != v.end(); ++i){
                if(primera){
                    dist_menor = n.distancia(*i);
                    menor = *i;
                    primera = false;       
                }
                else{
                    if(dist_menor >= n.distancia(*i) && !(menor == *i)){
                        dist_menor = n.distancia(*i);
                        menor = *i;
                    }
                }
            }
        }

        nodo masAlOeste(){
            nodo oeste;
            float coord_menor;
            bool primera = true;
            for(vector<nodo>::iterator i=v.begin(); i != v.end(); ++i){
                if(primera){
                    coord_menor = i->getCoord();
                    oeste = *i;
                    primera = false;     
                }
                else{
                    if(coord_menor >= i->getCoord()){
                        coord_menor = i->getCoord();
                        oeste = *i;
                    }
                }
            }
            return oeste;
        }
        nodo masAlEste(){
            nodo este;
            float coord_mayor;
            bool primera = true;
            for(vector<nodo>::iterator i=v.begin(); i != v.end(); ++i){
                if(primera){
                    coord_mayor = i->getCoord();
                    este = *i;
                    primera = false;     
                }
                else{
                    if(coord_mayor <= i->getCoord()){
                        coord_mayor = i->getCoord();
                        este = *i;
                    }
                }
            }
            return este;
        }
        nodo masAlNorte(){
            nodo norte;
            float section_mayor;
            bool primera = true;
            for(vector<nodo>::iterator i=v.begin(); i != v.end(); ++i){
                if(primera){
                    section_mayor = i->getSection();
                    norte = *i;
                    primera = false;     
                }
                else{
                    if(section_mayor <= i->getSection()){
                        section_mayor = i->getSection();
                        norte = *i;
                    }
                }
            }
            return norte;
        }    
 
        GrafoTSP recorridoParcial(){
            GrafoTSP res;
            res.v.push_back(masAlNorte());
            res.v.push_back(masAlEste());
            res.v.push_back(masAlOeste());
            return res;
        }

        float distanciaRecorrido(){
            float camino=0;
            int dim=size();
            float ** m=new float*[size()];
            for(int i=0; i<size();i++){
                m[i] = new float [3];
            }
            int i=0;
            for(vector<nodo>::iterator it= v.begin(); it != v.end(); i++,++it){
                m[i][0]=it->getNode();
                m[i][1]=it->getCoord();
                m[i][2]=it->getSection();
            }
            for (int i = 0; i < dim-1; i++)
            {
                camino += calcularDistancia(m[i+1][1], m[i][1], m[i+1][2], m[i][2]);
            }
            camino += calcularDistancia(m[0][1], m[dim-1][1], m[0][2], m[dim-1][2]);
            return camino;
        }

        void mostrar(){
            for (GrafoTSP::iterator i=begin(); i!=end(); ++i){
                cout << (*i).getNode()<< "\t"<< (*i).getCoord() << "\t" << (*i).getSection() << endl; 
            }
        }

        class iterator{
            private:
                vector<nodo>:: iterator it;
            public:
                iterator(){}
                bool operator==(const iterator &i){return i.it==it;}
                bool operator!=(const iterator &i){return i.it!=it;}
                nodo & operator * (){return *it;}
                iterator &operator ++(){++it; return *this;}
                iterator &operator --(){--it; return *this;}
                friend class GrafoTSP;
        };
        iterator begin(){
            iterator i;
            i.it = v.begin();
            return i;
        }
        iterator end(){
            iterator i;
            i.it = v.end();
            return i;
        }
        class const_iterator{
            private:
                vector<nodo>:: const_iterator it;
            public:
                const_iterator(){}
                bool operator==(const const_iterator &i){return i.it==it;}
                bool operator!=(const const_iterator &i){return i.it!=it;}
                const nodo & operator * (){return *it;}
                const_iterator &operator ++(){++it; return *this;}
                const_iterator &operator --(){--it; return *this;}
                friend class GrafoTSP;
        };
        const_iterator cbegin(){
            const_iterator i;
            i.it = v.cbegin();
            return i;
        }
        const_iterator cend(){
            const_iterator i;
            i.it = v.cend();
            return i;
        }        
        pair<nodo,nodo> seleccionar(GrafoTSP g){
            pair<nodo, nodo> res;
            nodo n, menor;
            float dist=INFINITY;
            bool primera=false;
            for(GrafoTSP::iterator i=begin(); i!=end(); ++i){
                for(GrafoTSP::iterator j=g.begin(); j!=g.end(); ++j){
                    if(dist >= (*i).distancia(*j)){
                        n= *i;
                        menor=*j;
                        dist= n.distancia(menor);  
                    }
                        
                }
            }
            res.first = n;
            res.second = menor;
            return res;
        }
        void insertafinal(nodo n){
            v.insert(v.end(), n);
        }

};

GrafoTSP insercionTSP(GrafoTSP g){
    //El grafo de la solucion es vacio inicialmente (optimo).
    //La copia de "g" que le pasamos a la funcion sera nuestro conjunto de candidatos
    GrafoTSP optimo; 
    int size_final = g.size();
    pair<nodo,nodo> aux;

    //Añado a optimo los nodos que constituyen el recorrido parcial
    optimo = g.recorridoParcial();

    //Los eliminamos de la lista de candidatos los elementos insertados inicialmente
    g.eliminar(g.masAlEste());
    g.eliminar(g.masAlOeste());   
    g.eliminar(g.masAlNorte()); 

    //Mientras S no sea solucion(hasta que el grafo no tenga el tamaño esperado) y C != 0 (la lista de candidatos quede vacia) ...
    while(optimo.size() < size_final && g.size() > 0){
        aux = optimo.seleccionar(g);
        optimo.insertar(aux.second, aux.first);        
        g.eliminar(aux.second);
    }
    optimo.insertafinal(*(optimo.begin()));
    return optimo;
}

int main(int argc, char **argv){
    if(argc != 2){
        cout << "Argumentos incorrectos\n";
        return -1;
    }
    string linea="";
    GrafoTSP g, h;
    ifstream f(argv[1]);
    int dim;
    if(!f.is_open()){
        cout << "Error al abrir el archivo\n";
        return -2;
    }
    else{
        int aux1, aux2;
        string prov;
        while(linea.compare("NODE_COORD_SECTION")!=0){
            getline(f, linea);
            aux1=linea.find("DIMENSION");
            if(aux1 != -1){
                aux1= linea.find(":");
                aux2= linea.find("\n");
                prov=linea.substr(aux1+1, aux2);
                dim = atoi(prov.c_str());
            }
        }
        g.reservar(dim);
        int n;
        float c, s;
        for(GrafoTSP::iterator i= g.begin(); i != g.end(); ++i){
            f >> n >> c >> s;
            (*i).setNode(n);
            (*i).setCoord(c); 
            (*i).setSection(s);
        }
        f.close();
    }
       
    float d;

    h = insercionTSP(g);
    d=h.distanciaRecorrido();
        

    cout << "\n\nGrafo inicial\n";

    g.mostrar();
    cout << endl << endl << endl << endl << endl; 
        
    cout << "Recorrido greedy por insercion\n";

    h.mostrar();

    cout << "\n\n\nDistancia:\n" << d << endl;

}
