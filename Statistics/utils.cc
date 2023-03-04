#include "utils.hpp"

     
std::istream& operator>>(std::istream& in, std::vector<int>& v){
    int element;
    in >> element;
    while (not in.eof()){
        v.push_back(element);
        in >> element;
    }
    return in;
}

