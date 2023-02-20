#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n = 0, element, frec = 1;
    std::vector<int> elements;
    std::cin>>element;
    
    while(not std::cin.eof()){ //CTRL + D -> INDICAR FINAL DEL FICHERO
        elements.push_back(element);  
        n += 1;
        std::cin>>element;
    }
    std::sort(elements.begin(), elements.end());
    int moda = elements[0];
    return 0;
}
