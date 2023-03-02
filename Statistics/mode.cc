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
    std::cout<<"Mode: "<<arith_mean<<std::endl;
    return 0;
}
    
  
