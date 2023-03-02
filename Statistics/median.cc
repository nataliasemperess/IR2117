#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc,char** argv){
    
    double median = 0, suma_num = 0;
    int cantidad_num = 0, element;
    std::vector<int> elements;
    std::cin>>element;
    
    while (not std::cin.eof()){ // Cuando se aprete CTRL + D se parará la ejecución
        elements.push_back(element);
        cantidad_num += 1;
        std::cin >> element;
    }
    std::sort(elements.begin(), elements.end());
    int middle = (elements.size()/2);
    if (elements.size()%2 == 0){
        median = double (elements[middle] + elements[middle + 1])/2;
    } else{
        median = double (elements[middle]);
    }
    std::cout<<"Median: "<< median << std::endl;
    return 0;
    
}
    
    
