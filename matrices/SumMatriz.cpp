#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

int main(){
    
    int rows, cols;
    std::cout<<"Enter matrix size: "<<std::endl;
    std::cin>>rows;
    cols = rows;
    
    MatrixXd m(rows, cols);
    std::cout<<"Enter elements (row-wise): "<<std::endl;
    for (int i=0;i < rows; i++){
        for (int j=0; j <cols; j++){
            std::cin>> m(i, j);
        }
    }
    std::cout<<"The matrix is: "<<std::endl;
    std::cout<< m <<std::endl;
    
    VectorXd s(rows);
    for (int i=0; i<rows;i++){
        s(i) = m.row(i).sum();
    }
    for (int i=0; i<cols;i++){
        s(i) = m.col(i).sum();
    }
    std::cout<<"The sum of rows is: "<<s<<std::endl;
    double maxRowSum = s.maxCoeff();
    std::cout<<"The maxium sum of rows is: "<<maxRowSum<<std::endl;

    std::cout<<"The sum of colums is: "<<s<<std::endl;
    double maxColSum = s.maxCoeff();
    std::cout<<"The maxium sum of colums is: "<<maxColSum<<std::endl;
    
    double maxRowColSum = maxRowSum > maxColSum ? maxRowSum : maxColSum;
    std::cout<<"The maxium sum of rows or colums is: "<<maxRowColSum<<std::endl;
}
            
    
    
