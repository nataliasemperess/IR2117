#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main(){
    int suma_max = 0;
    int filas;
    std::cout<<"Introduce el número de filas : ";std::cin>>filas;
    
    MatrixXd m = MatrixXd::Random(3,3);
    
    std::cout<<"La suma máxima es: "<<suma_max;
    
    return 0;
}
