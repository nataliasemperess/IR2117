#include <iostream>

int main(int argc, char** argv){
    
    double m = 0, s = 0;
    int n = argc -1;
    
    for (int i = 1; i <= n; i++){
        s += atoi(argv[i]); // Atoi convierte un texto a un num
    }
    m = s/n;
    
    std::cout<<"Arithmetic mean: "<< m << std::endl;
    return 0;
    
}

