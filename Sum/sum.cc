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
    while (numero < 1){
        std::cout<<"El número introducido no es admitido, pruebe otra vez: ";
        std::cin >> numero;
    }
    std::cout<<"El número introducido es: "<<numero<<", por tanto, la suma es: "<<suma(numero)<<std::endl;
    return 0;
}
    
