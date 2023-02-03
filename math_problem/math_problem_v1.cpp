   
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  float sum = 0, media;
  vector<int> muestra;

  cout << "Introduce el número total de elementos de la muestra: "; cin >> n;

  for (int i = 0; i < n; i++) {
    int num;
    cout << "Introduce el número de la posición " << i << ": "; cin >> num;
    muestra.push_back(num);
  }
  
  cout<<"Los elementos se han guardado correctamente en la muestra."<<endl;;

  return 0;
}

/*
 V1 -  Pedimos la cantidad y los datos de una muestra, 
       Inicializamos media
       Imprimimos mensaje de salida
       
       
V2 - Creamos una función para pedir los datos de la muestra

V3 - Calculamos la suma de los datos, y dividimos entre el num de elementos (media), imprimimos por pantalla la media

V4 - Si la cantidad introducida es 0 o menor a 0, saltará mensaje de error, y lo volverá a pedir
     */  
