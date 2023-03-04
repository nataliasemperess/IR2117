#include <iostream>
#include <map>
#include <vector>

using namespace std;

std::vector<int> elements;
std::cin >> elements;
std::map<int, int> counts;
int main (){
    int m = 0;
    int m_count = 0;
    for (auto pair : counts){
        int value = pair.first;
        int count = pair.second;
        if (count > m_count){
            m = value;
            m_count = count;
        }
    }
    std::cout<<"Mode: " << m << std::endl;
    return 0;
}
  
