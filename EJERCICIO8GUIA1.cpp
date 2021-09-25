#include <iostream> 
using namespace std;
void contadorMAS(int);
void contadorMEN(int);
void contador(int);


void contadorMAS (int num) {
     
    if (num < 1)return;
    contadorMAS (num - 1);
    cout<<num<<endl;
}
void contadorMEN (int num) {
      if (num < 2 ) return;
    cout << num-1 << endl;
    contadorMEN (num - 1);
}
void contador(int num){
  contadorMAS(num);
  contadorMEN(num);
}


int main()
{
    int num=0;
    cout<<"CONTADOR ASCENDENTE Y DESCENDENTE"<<endl;
    cout<<"Ingrese el numero entero: "<<endl;
    cin>>num;
    cout<<endl;
    contador(num);

}
//solo asi lo pude hacer :(
