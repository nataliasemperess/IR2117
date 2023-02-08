#include <iostream>
#include <cmath>
#include <complex>

int main(){
    
    double a,b,c,x1,x2;
    std::cout<<"Introduce a : ";std::cin>>a;
    std::cout<<"Introduce b : ";std::cin>>b;
    std::cout<<"Introduce c : ";std::cin>>c;
    
    double discriminant = (b*b) -(4*a*c);
    
    if (discriminant < 0){
        std::complex<double> sqrtdisc = sqrt(std::complex<double>(discriminant));
        std::complex<double> x1c = (-b + sqrtdisc)/(2*a);
        std::complex<double> x2c = (-b - sqrtdisc)/(2*a);
        std::cout<< "complex x1 = "<<x1c<<std::endl;
        std::cout<< "complex x2 = "<<x2c<<std::endl;
    }
    else if (discriminant = 0){
        x1 = -b / (2*a);
        std::cout<<"x = "<<x1<<std::endl;
    }
    else{
        x1 = (-b + sqrt(discriminant))/(2*a);
        x2 = (-b - sqrt(discriminant))/(2*a);
        std::cout<< "x1 = "<<x1<<std::endl;
        std::cout<< "x2 = "<<x2<<std::endl;
    }
}
