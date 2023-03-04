#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main(){
    double median = 0;
    int element = 0, n = 0;
    std::vector<int> elements;
    std::cin >> elements;
    
    while (not std::cin.eof()){
        elements.push_back(element);
        std::cin>>element;
        n++;
    }
    int count[n], max = 0;
    std::map<int, int> counts;
    
    for (int i : elements){
        counts[i]++;
    }
    for (std::pair<int, int> key:counts){
        if (key.second) > max){
            max = key.first;
        }
    }
    std::cout<<"Mode: " << max << std::endl;
    return 0;
    }
    
