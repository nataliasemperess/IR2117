#include <iostream>
#include <vector>

int main(int argc,char** argv){
    
    double arith_mean = 0, suma_num = 0;
    int cantidad_num = 0, element;
    std::vector<int> elements;
    std::cin>>element;
    
    while (not std::cin.eof()){ // Cuando se aprete CTRL + D se parará la ejecución
        elements.push_back(element);
        cantidad_num += 1;
        std::cin >> element;
    }
    for (int i = 0; i < cantidad_num; i++){
        suma_num += elements[i];
    }
    arith_mean = suma_num/cantidad_num;
    std::cout<<"Arith_mean: "<<arith_mean<<std::endl;
    return 0;
}
    
    
