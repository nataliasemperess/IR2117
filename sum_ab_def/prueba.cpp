#include <iostream>

int main(){
    long int a, b, sum=0;
    
    std::cout<<"Introduce a: "; std::cin >> a;
    while(a<1){
        std::cout<<"a no es positivo. Pruebe otra vez: "; std::cin>>a;
    }
    std::cout<<"Introduce b: "; std::cin >> b;
    while(b<1 || b<=a){
        std::cout<<"b no es positivo, o bien b < a. Pruebe otra vez: "; std::cin>>b;
    }
    for(long int i=a; i<=b; i++){
        sum+=i;
    }
    std::cout<< "La suma es " << sum << std::endl;
    
    return 0;
}

