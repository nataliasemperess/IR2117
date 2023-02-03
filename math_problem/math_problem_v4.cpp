#include <iostream>
#include <vector>
using namespace std;

vector<int> pedir_datos(int n){
    vector<int> muestra;
    for (int i = 0; i < n; i++) {
        int num;
        cout << "Introduce el número de la posición " << i << ": "; cin >> num;
        muestra.push_back(num);
    }
    return muestra;
}

int main() {
    int n;
    float sum = 0, media;
    vector<int> muestra;
    cout << "Introduce el número total de elementos de la muestra: "; cin >> n;
    while (n <= 0){
        cout<<"La cantidad de datos no puede ser 0 o menor. Pruebe otra vez: "; cin>>n;
    }
    muestra = pedir_datos(n);
    
    for (int i = 0; i < n; i++){
        sum += muestra[i];
    }
    
    media = sum / n;
    
    cout<<"La media de la muestra es: "<<media<<endl;

  return 0;
}
