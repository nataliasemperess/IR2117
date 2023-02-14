#include <iostream>
#include <vector>
#include <algorithm>


int main(int argc, char** argv){
    
    double m = 0, s = 0;
    int n = 0, element;
    std::vector<int> elements;
    std::cin>>element;
    
    while(not std::cin.eof() > 0){ //CTRL + D -> INDICAR FINAL DEL FICHERO
        elements.push_back(element);  
        n += 1;
        std::cin>>element;
    }
    std::sort(elements.begin(), elements.end());
    std::cout<<"Median: "<< m << std::endl;
    return 0;
    
}
