#include <iostream> 
using namespace std;

int MCD(int x, int y)
{
    if(y==0)
        return x;
    else
        return MCD(y, x%y);
}


int main()
{
    int num1=0,num2=0;
    cout<<endl;
    cout << "MCD POR EUCLIDES"<<endl<<endl;
    cout << "Introduce el primer numero: "<<endl;
    cin>>num1;
    cout << "Introduce el segundo numero: "<<endl;
    cin>>num2;
    cout << "El resultado es:  "<<MCD(num1,num2);
    return 0;
}