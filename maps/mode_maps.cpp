#include <iostream>

std::vector<int> elements;
std::cin >> elements;
std::map<int, int> counts;

for (int value : elements){
    counts[value]++;
}


/* EXPLICACIÓN
Recorremos lista, y apuntamos la frecuencia de cada número
14 -2
8 - 4
25 -1
32 -2
7 -1 
*/

