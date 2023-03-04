#include <iostream>

int main(){
    
    long int a, b, suma = 0;
    
    std::cout<<"Introduce a : "; std::cin>>a;
    std::cout<<"Introduce b : "; std::cin>>b;
    for (long int i = a; i <= b; i++){
        suma += 1;
    }   
    std::cout<<"El resultado de la suma es: "<<suma<<std::endl;
    return 0;
}
