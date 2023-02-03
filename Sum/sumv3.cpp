#include <iostream>

using namespace std;

int suma(int num){
    int sum = 0;
    sum = num * (num+1)/2;
    return sum;
}



int main(){
    int num;
    cout<<"Introduce un número: "; cin >> num;
    cout<<"La suma es: "<<suma(num)<<endl;
    return 0;
}
