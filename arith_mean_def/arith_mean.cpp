#include <iostream>

int main(int argc, char** argv){
    
    double m = 0, s = 0;
    int n = 0, element;
    
    std::cin>>element;
    
   while(!std::cin.eof() > 0){ //CTRL + D -> INDICAR FINAL DEL FICHERO
        n+=1;
        s+=element;
        std::cin>>element;
    }
    m = s/n;
    
    std::cout<<"Arithmetic mean: "<< m << std::endl;
    return 0;
    
}
