#include <iostream>
#include <string>
using namespace std;

struct Lista{
    int id;
    string nombreUs;
    string perfil;   
};
Lista solicitarLista(void){
    Lista p;
    cout << "Id: ";
    cin >> p.id;cin.ignore();
    cout << "Nombre de usuario: ";
    getline(cin, p.nombreUs);
    cout << "Perfil: ";
    getline(cin, p.perfil);
    return p;
}

void mostrarLista(Lista p){
    cout << "Id: " << p.id<<endl;
    cout << "Nombre de usuario: " << p.nombreUs<<endl;
    cout << "Perfil: " << p.perfil<< endl;
}

typedef Lista T;
const T noValido = {-1,"",""};

struct nodo{
    T dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{
    private:
        nodo *pInicio;
    public:
        ListaDoble();
        ~ListaDoble();
        void insInicio(T);
        void insFinal(T);
        void mostrarListaDirectoIter(void);
        void mostrarListaDIIter(void);
        void deleteItem(T);
        bool empty(void);
};

ListaDoble::ListaDoble(void){
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insInicio(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if(pInicio != NULL)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}

void ListaDoble::insFinal(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin = pInicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

void ListaDoble::mostrarListaDirectoIter(void){
    nodo *saltarin = pInicio;
    while(saltarin != NULL){
        mostrarLista(saltarin->dato);//cout << saltarin->dato << endl;
        saltarin = saltarin->sig;
    }
}

void ListaDoble::mostrarListaDIIter(void){
    if(!pInicio)
        return;
    nodo *p = pInicio;
    nodo *q = NULL;
    while(p){
        q = p;
        p = p->sig;
    }
    while(q){
        mostrarLista(q->dato);//cout << q->dato << endl;
        q = q->ant;
    }
}

void ListaDoble::deleteItem(T datoB){
    if(!pInicio){ // Lista vacía.
        cout << "Actualmente no hay usuarios." << endl;
    }
    else{ // Si la lista no está vacía, entonces:
        nodo *saltarin = pInicio;
        while(saltarin && (saltarin->dato).nombreUs.compare(datoB.nombreUs)!=0) // Saltar.
            saltarin = saltarin->sig; // Luego de saltar hay varias posibilidades:
        if(!saltarin) // a) saltarín se salió (el dato no está en la lista).
            cout << "El usuario no está en la lista" << endl;
        else{ // Si saltarín no se salió (está sobre el dato a eliminar):
              // el nodo puede estar al principio, puede estar al final,
              // puede estar entre dos nodos, puede ser el único nodo.
            if(!saltarin->ant && saltarin->sig){ // Al principio (y hay más nodos).
                pInicio = pInicio->sig;
                pInicio->ant = NULL;
                delete saltarin;
            }
            else
                if(saltarin->ant && !saltarin->sig){
                    saltarin->ant->sig = NULL;
                    delete saltarin;
                }
                else
                    if(saltarin->ant && saltarin->sig){
                        saltarin->ant->sig = saltarin->sig;
                        saltarin->sig->ant = saltarin->ant;
                        delete saltarin;
                    }
                    else{
                        pInicio = NULL;
                        delete saltarin;
                    }
            cout << "Usuario eliminado exitosamente!" << endl;
        }
    }
}
bool ListaDoble::empty(void){
    return pInicio == NULL;
}

int menu(){
    int opcion = 0;
    cout << endl << "1) Agregar al inicio." << endl;
    cout << "2) Agregar al final." << endl;
    cout << "3) Mostrar de principio al final." << endl;
    cout << "4) Mostrar de final al principio." << endl;
    cout << "5) Eliminar usuario"<<endl;
    cout << "6) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    cout<<endl;
    return opcion;
}

int main(void){
    ListaDoble objListaDoble;
    Lista p;
    bool continuar = true;
do{
        switch(menu()){
            case 1: //Agregar Inicio
                p=solicitarLista();
                objListaDoble.insInicio(p);
                cout <<"Usuario almacenado exitosamente!" << endl;
                break;
            case 2: //Agregar Final
                p=solicitarLista();
                objListaDoble.insFinal(p);
                cout <<"Usuario almacenado exitosamente!" << endl;
                break;
            
            case 3: //Mostrar desde inicio a fin
                objListaDoble.mostrarListaDirectoIter();
                break;
            case 4: //Mostrar desde fin a inicio
                objListaDoble.mostrarListaDIIter();
                break;
            case 5: //Eliminar Inicio
                  if(objListaDoble.empty())
                    cout << "No hay usuarios por eliminar" << endl;
                else{
                    p = solicitarLista();
                    objListaDoble.deleteItem(p);
                }
                break;
            case 6: //Salir
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    return 0;
}