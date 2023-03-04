#include <iostream>

int suma(int num){
    int sum = 0;
    sum = (num *(num + 1))/2;
    return sum;
}

int main(){
    int numero;
    std::cout<<"Introduce un número: ";
    std::cin >> numero;
    if (numero >= 1){
        std::cout<<"El número introducido es: "<<numero<<", por tanto, la suma es: "<<suma(numero)<<std::endl;
    }
    else{
        std::cout<<"El número introducido no es admitido"<<std::endl;
    }
    return 0;
}
    
