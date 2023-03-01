#include <iostream>

int main(int argc,char** argv){
    
    double arith_mean = 0, suma_num = 0;
    int cantidad_num = argc - 1;
    
    for (int i = 1; i <= cantidad_num; i++){
        suma_num += atoi(argv[i]);
    }
    arith_mean = suma_num/cantidad_num;
    std::cout<<"Arith_mean: "<<arith_mean<<std::endl;
    return 0;
}
    
    
