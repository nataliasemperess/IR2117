#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n = 0, element, frec = 1, max_frec;
    std::vector<int> elements;
    std::cin>>element;
    
    while(not std::cin.eof()){ //CTRL + D -> INDICAR FINAL DEL FICHERO
        elements.push_back(element);  
        n += 1;
        std::cin>>element;
    }
    std::sort(elements.begin(), elements.end());
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n;j++){
            if (elements[i] == elements[j])){
                frec += 1;
            }
        }
        if (frec > max_frec){
            m = elements[i];
            max_frec = frec;
        }
    }
    std::cout<<"Elemento: "<<element[0]<<std::endl;
    std::cout<<"Mode: "<< m <<endl;
    return 0;
}
