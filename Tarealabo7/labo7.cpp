#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *hijoIzq;
    nodo *hijoDer;
};

class ABB{
    private:
        nodo *pAbb;
    
    public:
        ABB();
        ~ABB();
        void insertar(void);
        void insNodoAbb(nodo **,int);

        void mostrarEnPeorden(void);
        void mostrarPre(nodo *);

        void mostrarEnInOrden(void);
        void mostrarIn(nodo *);
        
        void mostrarEnPosOrden(void);
        void mostrarPos(nodo *);

        bool buscarNodo(nodo *,int);
        void buscar(int);
        void borrarNodo(int);
        void borrarNodoRec(nodo **,int);       
};

ABB::ABB(void)
{
    pAbb = NULL;
}

ABB::~ABB()
{
    cout << "Destructor ejecutándose" << endl;
}

void ABB::insertar(void)
{
    int dato;
    char resp;

    do{
        cout<<"desea digitar un dato?: ";
        cin>>resp;
         if(resp == 's'){
            cout<<"digite el dato: ";
            cin>>dato;
            insNodoAbb(&pAbb,dato);
        }
    }while(resp =='s');
}

void ABB::insNodoAbb(nodo **p,int dato)
{
    if(!(*p)){
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->hijoIzq=NULL;
        (*p)-> hijoDer=NULL;
    }
    else 
        if(dato < (*p)->dato)
            insNodoAbb(&((*p)->hijoIzq),dato);
        else 
            if( dato >  (*p)->dato)
                insNodoAbb(&((*p)->hijoDer),dato);
            else
                cout<<"La llave ya esta en el arbol ";

}
 
void ABB::mostrarEnInOrden(void)
{
    mostrarIn(pAbb);
    
}

void ABB::mostrarIn(nodo *p)
{
    if(p){
        mostrarIn(p->hijoIzq);
        cout<<p->dato<<"  ";
        mostrarIn(p->hijoDer);
    }
}

bool ABB::buscarNodo(nodo *p,int n)
{
    if(p == NULL)
        return false;
    else if(p->dato == n)
        return true;
    else if(p->dato > n)
        return buscarNodo(p->hijoIzq,n);
    else if(p->dato < n)
        return buscarNodo(p->hijoDer,n);
}

void ABB::buscar(int n)
{
    if(buscarNodo(pAbb,n))
        cout << "Dato encontrado";
    else
        cout<<"Dato no encontrado";   
    
}

void ABB::mostrarEnPeorden(void)
{
    mostrarPre(pAbb);
    
}

void ABB::mostrarPre(nodo *p)
{
    if(p){
        cout << p->dato << "  ";
        mostrarPre(p->hijoIzq);
        mostrarPre(p->hijoDer);
    }
}

void ABB::mostrarEnPosOrden(void)
{
    mostrarPos(pAbb);
    
}

void ABB::mostrarPos(nodo *p)
{
    if(p){
        mostrarPos(p->hijoIzq);
        mostrarPos(p->hijoDer);
        cout << p->dato << "  ";
    }
}

void ABB::borrarNodo(int dato){
    borrarNodoRec(&pAbb,dato);
}

void ABB::borrarNodoRec(nodo **r, int dato) {
    nodo *p;
    if(!(*r))
    cout<<"El dato No esta en el arbol"<<endl<<endl;
    else
        if(dato<(*r)->dato)
        borrarNodoRec(&((*r)->hijoIzq),dato);
        else
            if(dato>(*r)->dato)
            borrarNodoRec(&((*r)->hijoDer),dato);
            else{
                if(!((*r)->hijoIzq) && !((*r)->hijoDer)){
                    p=*r=NULL;
                }
                else
                    if(!((*r)->hijoIzq) && ((*r)->hijoDer)){
                    p=*r=(*r)->hijoDer;
                    }
                    else
                        if(((*r)->hijoIzq) && !((*r)->hijoDer)){
                        p=*r=(*r)->hijoIzq;
                        }
                        else
                            if(((*r)->hijoIzq) && ((*r)->hijoDer)){
                            p=(*r)->hijoIzq;
                            if(!p->hijoDer){
                                (*r)->dato = p->dato;
                                (*r)->hijoIzq = p->hijoIzq;
                            }
                            else{
                                nodo *q;
                                while(p->hijoDer){
                                    q=p=p->hijoDer;
                                }
                                (*r)->dato = p->dato;
                                q->hijoDer = p->hijoIzq;
                            }
                        }
            delete p;                
       }
}
  
int main(void)
{
    int n;
    cout << endl;
    cout << "ARBOL BINARIO DE BUSQUEDA" << endl << endl;
    ABB objABB;
    cout << "Insertar datos en el arbol:" << endl;
    objABB.insertar();

    cout<<"mostrar en in-orden: ";
    objABB.mostrarEnInOrden();
    cout<<endl;

    cout<<"mostrar en Pre-orden: ";
    objABB.mostrarEnPeorden();
    cout<<endl;

    cout<<"mostrar en Post-orden: ";
    objABB.mostrarEnPosOrden();
    cout<<endl;
    
    cout<<"Que dato desea buscar? "<<endl;
    cin>>n;
    objABB.buscar(n);
    cout << endl;

    cout<<"Que dato desea eliminar? "<<endl;
    cin>>n;
    objABB.borrarNodo(n);
    cout<<"Dato eliminado"<<endl;

    cout<<"mostrar en in-orden: ";
    objABB.mostrarEnInOrden();

    cout << endl;
    return 0;
}