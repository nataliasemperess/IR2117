#include <iostream>


int main(){
    int numero;
    int sum = 0;
    std::cout<<"Introduce un número: ";
    std::cin >> numero;
    sum = (numero *(numero + 1))/2;
    std::cout<<"El número introducido es: "<<numero<<", por tanto, la suma es: "<<sum<<std::endl;
    return 0;
}
    
