#include <iostream>

using namespace std;

struct nodo{
	int dato;
	nodo *sig;
	char nombre[20];
	int cantidad;
	char tipo[20];
	char bebida[20];
	char ingre[50];
};

typedef struct nodo *PLista;

class ListaSimple{

	private:
    	nodo *pInicio;
	
	public:
    	ListaSimple();
    	void menu(void);
    	void LlenarLis(PLista &lista);
    	void mostrarLista(PLista q);

};

ListaSimple::ListaSimple(void)
{
	pInicio = NULL;
}

void menu(void){

	cout<<"\n\t\t[	MENU DE COMEDOR	]\n";
	cout<<"\t\t----------------------------\n\n";
	cout<<"PUPUSAS DE MAIZ Y ARROZ"<<endl;
	cout<<"BEBIDAS: "<<endl;
    cout<<"GASEOSA EN LATA $0.75"<<endl;
    cout<<"CAFE $0.40"<<endl;
    cout<<"JUGO $0.50"<<endl;
    cout<<"CHOCOLATE $0.40 "<<endl;
	cout<<"PUPUSAS DE FRIJOL CON QUESO $0.50"<<endl;
    cout<<"PUPUSAS DE REVUELTAS $0.50"<<endl;
    cout<<"PUPUSAS DE QUESO $0.60"<<endl;
    cout<<"PUPUSAS DE AYOTE $0.60"<<endl;

}


void ListaSimple::LlenarLis(PLista &lista)
{
   
   PLista t,q = new(struct nodo);
  
	cout<<"\n\n\t\t[  PUPUSERIA DON JUAN  ]\n";
	cout<<"\t\t------------";
	cout<<"\n\tPEDIDOS";
	cin.ignore();cout<<"\n\nNOMBRE Y APELLIDO: "; cin.getline(q->nombre,20);
	cin.ignore();cout<<"CANTIDAD DE PUPUSAS "; cin>>q->cantidad;
	cin.ignore();cout<<"\nDE MAIZ O ARROZ: "; cin.getline(q->tipo,20);
	cin.ignore();cout<<"QUE TIPO DE BEBIDA: "; cin.getline(q->bebida,20);
	cin.ignore();cout<<"INGREDIENTES: "; cin.getline(q->ingre,50);
    cout<<endl;



	q->sig = NULL;

	if(lista==NULL){

    	lista = q;

	} else {

    	t = lista;

    	while(t->sig!=NULL){

            	t = t->sig;
    	}

    	t->sig = q;

	}
}


void ListaSimple::mostrarLista(PLista q)
{

	int i=1;

	while(q!=NULL){

    	cout<<"\n\tPUPUSERIA DON JUAN"<<endl;
        cout<<"ORDEN ["<<i<<"] ";
    	cout<<"\n\t------------------------";
    	cout<<"\n\tNOMBRE Y APELLIDO: "<<q->nombre<<endl;
    	cout<<"\tCANTIDAD DE PUPUSAS: "<<q->cantidad<<endl;
    	cout<<"\tMAIZ O ARROZ: "<<q->tipo<<endl;
    	cout<<"\tBEBIDA: "<<q->bebida<<endl;
    	cout<<"\tINGREDIENTES: "<<q->ingre<<endl;
    	q=q->sig;
    	i++;
	}
}

int main(void)
{
 PLista lista=NULL;
 ListaSimple objListaSimple;
menu();
int cantidad;
cout<<endl;
cout<<"Ingrese las ordenes de pupusas: ";
cin>>cantidad;
for(int i=1;i<=cantidad;i++){
objListaSimple.LlenarLis(lista);
}
objListaSimple.mostrarLista(lista);
cout<<endl;
	return 0;
}

