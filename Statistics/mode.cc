#include <iostream>
#include <vector>

int main(int argc,char** argv){
    
    double moda = 0, suma_num = 0;
    int cantidad_num = 0, element;
    std::vector<int> elements;
    std::cin>>element;
    
    while (not std::cin.eof()){ // Cuando se aprete CTRL + D se parará la ejecución
        elements.push_back(element);
        cantidad_num += 1;
        std::cin >> element;
    }
    int count[cantidad_num], max = 0;
    for (int j = 0; j < cantidad_num; j++){
        count[j] = 0;
        for (int i = 0; i < cantidad_num; i++){
            if (elements[i] == elements[j]){
                count[j]++;
            }
        }
        if (count[j] > count[max]){
            max = j;
            moda = count[j];
        }
    }
    std::cout<<"Mode: "<<moda<<std::endl;
    return 0;
}
    
  
