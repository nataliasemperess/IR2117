#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include <vector>
#include <Eigen/Dense>

using namespace std::chrono_literals;

std::vector<float> vector;
float min, min_rang1, min_rang2;
bool parada = false;
float giro;

void wandering_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg){
	
    // Versión 3 : Mostrar el valors del vector ranges:
    for (int i = 0; i <= 9; i++){
          double vector = msg -> ranges[i];
          std::cout<<"Rangos: "<<vector<<std::endl;}
    
    for (int j = 350; j <= 359; j++){
          double vector = msg -> ranges[j];
          std::cout<<"Rangos: "<<vector<<std::endl;}
          
    // Versión 5 : mover robot y parar cuando se encuentre un objeto a < de 1 metro.
    
    parada = false;
    if (vector[0] < 1){
        parada = true;}

          
    // Versión 7 : Calcular mínimo de los rangos anteriores (modificando versión 4)
    
    Eigen::Map<Eigen::VectorXf> vector_rang1(vector.data(), vector.size());
    Eigen::Map<Eigen::VectorXf> vector_rang2(vector.data() + 350, vector.size());
   
    // Versión 7 : Guardando los mínimos en variables globales y mostrandolas
    
    min_rang1 = vector_rang1.minCoeff();
    min_rang2 = vector_rang2.minCoeff();
    
    std::cout<<"El mínimo del vector en el rango [0-9] es : "<<min_rang1<<std::endl;
    std::cout<<"El mínimo del vector en el rango [350-359] es : "<<min_rang2<<std::endl;
   
}


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("wandering");
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  auto subscripcion = node->create_subscription<sensor_msgs::msg::LaserScan>("scan", 10, wandering_callback);
  geometry_msgs::msg::Twist message;
  auto publish_count = 0;
  rclcpp::WallRate loop_rate(10ms);

  while (rclcpp::ok() && (parada is false)) { // recto
    message.linear.x = 0.5;
    message.angular.z = 0.0;
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}

// Versión 7 : para elegir la dirección de giro

if (min_rang1 > min_rang){
    giro = 0.5; }
else{
    giro = -0.5;
}
// Versión 6 : Girar a la izquierda

  while (rclcpp::ok() && (parada is true)) { //Para poder girar a la izquierda/derecha
    message.linear.x = 0.0;
    message.angular.z = giro;
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}

