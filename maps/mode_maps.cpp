#include <iostream>

/* VERSIÓN 1
std::vector<int> elements;
std::cin >> elements;
std::map<int, int> counts;

for (int value : elements){
    counts[value]++;
}
*/

// VERSIÓN 2

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
    std::cout<<"Mode: " << m << std::edl;
    return 0;
}

/* EXPLICACIÓN
Recorremos lista, y apuntamos la frecuencia de cada número
14 -2
8 - 4
25 -1
32 -2
7 -1 
*/

