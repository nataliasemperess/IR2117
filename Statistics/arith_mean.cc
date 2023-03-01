#include <iostream>

int main(int argc,char** argv){
    
    double arith_mean = 0, suma_num = 0;
    int cantidad_num = 0, element;
    std::cin>>element;
    
    while (element > 0){
        cantidad_num += 1;
        suma_num += element;
        std::cin >> element;
    }
    arith_mean = suma_num/cantidad_num;
    std::cout<<"Arith_mean: "<<arith_mean<<std::endl;
    return 0;
}
    
    
