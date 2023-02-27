#include <iostream>
#include <Eigen/Dense>


/* Versión  1

using Eigen::MatrixXd;
using Eigen::VectorXd;

int main(){
    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout<<m<<std::endl;
}

*/

/* Versión 2
 
using Eigen::MatrixXd;
using Eigen::VectorXd;

int main(){
    
    MatrixXd m = MatrixXd::Random(3,3);
    m = (m + MatrixXd::Constant(3,3,1.2))*50;
    std::cout<<"m = \n"<< m <<std::endl;
    
    VectorXd v(3);
    v << 1,2,3;
    std::cout<<"m * v = \n"<< m * v <<std::endl;
} 
*
*/

// Otra forma

using Eigen::Matrix3d;
using Eigen::Vector3d;

int main(){
    
    Matrix3d m = Matrix3d::Random();
    m = (m + Matrix3d::Constant(1.2))*50;
    std::cout<<"m = \n"<< m <<std::endl;
    
    Vector3d v(1, 2, 3);
    std::cout<<"m * v = \n"<< m * v <<std::endl;
} 
