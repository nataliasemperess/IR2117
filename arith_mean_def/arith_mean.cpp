#include <iostream>
#include <vector>

int main(int argc, char** argv){
    
    double m = 0, s = 0;
    int n = 0, element;
    std::vector<int> elements;
    
    std::cin>>element;
    
    while(not std::cin.eof() > 0){ //CTRL + D -> INDICAR FINAL DEL FICHERO
        elements.push_back(element);
        n+=1;
        std::cin>>element;
    }
    for (int i = 0; i < n; i++){
        s+= elements[i];
    }
    m = s/n;
    std::cout<<"Arithmetic mean: "<< m << std::endl;
    return 0;
    
}
