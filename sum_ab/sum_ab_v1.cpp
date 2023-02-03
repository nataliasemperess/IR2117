#include <iostream>

using namespace std;

int main(){
    long int a, b, sum=0;
    
    cout<<"Introduce a: "; cin >> a;
    cout<<"Introduce b: "; cin >> b;
    for(long int i=a; i<=b; i++){
        sum+=i;
    }
    cout<< "La suma es " << sum << endl;
    
    return 0;
}
