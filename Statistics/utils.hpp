#include <iostream>
#include <vector>

std::vector<int> ReadElements();

std::istream& operator>>(std::istream&, std::vector<int>&);
