#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *subLeft;
    nodo *subRight;
};

class BinarySearchTree{
    private:
        nodo *pBinarySearchTree;
    public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insertar(void);
    void insertarBST(nodo **, int);
    void showPreorder(nodo *);
    void showInorder(void);
    void showIn(nodo *);
    void showPost(nodo *);
    void showPostOrder(void);
    void showPreorder(void);
    void showPre(nodo *);
    bool searchNode(nodo *,int);
    void search(int);
    void removeNode(nodo **,int);
    void remove(int);
};

BinarySearchTree::BinarySearchTree(void)
{
    pBinarySearchTree = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    cout << "Program Execution" << endl;
}

void BinarySearchTree::insertar(void)
{
    int dato;
    char resp;

    do{
        cout << "Escriba y para continuar" << endl;
        cout << "Desea digitar un dato?: ";
        cin >> resp;
        if(resp == 'y'){
            cout << "Elemento que desea ingresar: ";
            cin >> dato;
            insertarBST(&pBinarySearchTree, dato);
        }

    }while(resp == 'y');
}

void BinarySearchTree::insertarBST(nodo **p, int dato)
{
    if(!(*p)){
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->subLeft = NULL;
        (*p)->subRight = NULL; 
    }
    else{
        if(dato < (*p)->dato)
            insertarBST(&((*p)->subLeft), dato);
        else
            if(dato > (*p)->dato)
                insertarBST(&((*p)->subRight), dato);
            else
                cout << "El dato ya esta ingresado" << endl << endl;
    }
}

void BinarySearchTree::showInorder(void)
{
    showIn(pBinarySearchTree);
}

void BinarySearchTree::showIn(nodo *p)
{
    if(p){
        showIn(p->subLeft);
        cout << p->dato << "  ";
        showIn(p->subRight);
    }
}

void BinarySearchTree::showPreorder(void)
{
    showPre(pBinarySearchTree);
}

void BinarySearchTree::showPre(nodo *p)
{
    if(p){
        cout << p->dato << "  ";
        showPre(p->subLeft);
        showPre(p->subRight);
    }
}

void BinarySearchTree::showPostOrder(void)
{
    showPost(pBinarySearchTree);
}

void BinarySearchTree::showPost(nodo *p)
{
    if(p)
    {
        showPost(p->subLeft);
        showPost(p->subRight);
        cout << p->dato << "  ";
    }
}

    bool BinarySearchTree::searchNode(nodo *p,int n){
        if(p == NULL)
        return false;
    else if(p->dato == n)
        return true;
    else if(p->dato > n)
        return searchNode(p->subLeft,n);
    else if(p->dato < n)
        return searchNode(p->subRight,n);
    }

    void BinarySearchTree::search(int n){
        if(searchNode(pBinarySearchTree,n))
        cout << "Dato encontrado"<<endl;
    else
        cout<<"Dato no encontrado"<<endl; 

    }

    void BinarySearchTree::removeNode(nodo **r,int dato){
    nodo *p;
    if(!(*r))
    cout<<"El dato No esta en el arbol"<<endl<<endl;
    else
        if(dato<(*r)->dato)
        removeNode(&((*r)->subLeft),dato);
        else
            if(dato>(*r)->dato)
            removeNode(&((*r)->subRight),dato);
            else{
                if(!((*r)->subLeft) && !((*r)->subRight)){
                    p=*r=NULL;
                }
                else
                    if(!((*r)->subLeft) && ((*r)->subRight)){
                    p=*r=(*r)->subRight;
                    }
                    else
                        if(((*r)->subLeft) && !((*r)->subRight)){
                        p=*r=(*r)->subRight;
                        }
                        else
                            if(((*r)->subLeft) && ((*r)->subRight)){
                            p=(*r)->subLeft;
                            if(!p->subRight){
                                (*r)->dato = p->dato;
                                (*r)->subLeft = p->subLeft;
                            }
                            else{
                                nodo *q;
                                while(p->subRight){
                                    q=p=p->subRight;
                                }
                                (*r)->dato = p->dato;
                                q->subRight = p->subLeft;
                            }
                        }
            delete p;
            cout<<"Dato eliminado"<<endl;                
       }
    }
    void BinarySearchTree::remove(int dato){
        removeNode(&pBinarySearchTree,dato);
    }

int main(void)
{
    int n;
    cout << endl;
    cout << "Binary Search Tree :D" << endl;

    BinarySearchTree objBinarySearchTree;

    cout << "Insertar datos en el arbol:" <<  endl;
    objBinarySearchTree.insertar();

    cout << "Mostrar Pre-orden: " << endl;
    objBinarySearchTree.showPreorder();
    cout << endl;

    cout << "Mostrar In-Orden: " << endl;
    objBinarySearchTree.showInorder();
    cout << endl;

    cout << "Mostrar Post-Orden: " << endl;
    objBinarySearchTree.showPostOrder();
    cout << endl;

    cout<<"Que dato desea buscar?"<<endl;
    cin>>n;
    objBinarySearchTree.search(n);

    cout<<"Que dato desea eliminar?"<<endl;
    cin>>n;
    objBinarySearchTree.remove(n);

    cout << "Mostrar In-Orden despues de haber eliminado un dato: " << endl;
    objBinarySearchTree.showInorder();
    cout << endl;
    return 0;
}
