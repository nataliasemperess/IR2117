#include "utils.hpp"

std::vector<int> ReadElements(){
    int element;
    std::vector<int> elements;
    std::cin >> element;
    
    while (not std::cin.eof()){
        elements.push_back(element);
        std::cin >> element;
    }
    return elements;
}
        

std::istream& operator>>(std::istream& in, std::vector<int>& v){
    int element;
    in >> element;
    while (not in.eof()){
        v.push_back(element);
        in >> element;
    }
    return in;
}
