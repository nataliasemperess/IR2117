#include <iostream>
using namespace std;

int suma(int numero){
    int suma = 0;
    suma = (numero * (numero+1))/2;
    return suma;}
    
int main(){
    int numero;
    cout<<"Número insertado: ";cin>>numero;
    while (numero < 0){
        cout<<"El número introducido no es correcto"<<endl;
        return false;
    }
    if (true){
        cout<<"El resultado es: "<<suma(numero)<<endl;}
    return 0;
}
