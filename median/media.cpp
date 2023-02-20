#include <iostream>
#include <vector>
#include <algorithm>


int main(int argc, char** argv){
    
    double m,s, n, l = 0;
    std::vector<int> elements;
    std::cin>>element;
    
    while(not std::cin.eof() > 0){ //CTRL + D -> INDICAR FINAL DEL FICHERO
        elements.push_back(element);  
        n += 1;
        std::cin>>element;
    }
    std::sort(elements.begin(), elements.end());
    int middle = (elements.size()/2);
    if (elements.size()%2 == 0){
        m = double (elements[middle] + elements[middle + 1])/2;
    } else{
        m = double (elements[middle];
    }
    std::cout<<"Median: "<< m << std::endl;
    return 0;
    
}
