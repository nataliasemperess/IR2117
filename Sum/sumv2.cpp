#include <iostream>

using namespace std;

int main(){
    int num, sum = 0;
    cout<<"Introduce un número: "; cin >> num;
    sum = num *(num+1)/2;
    cout<<"La suma es: "<< sum<<endl;
    return 0;
}
