#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include <vector>
#include <Eigen/Dense>

using namespace std::chrono_literals;

std::vector<float> vector;
int min;

void wandering_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg){
	
    // Versión 3 : Mostrar el valors del vector ranges:
    for (int i = 0; i <= 9; i++){
          double vector = msg -> ranges[i];
          std::cout<<"Rangos: "<<vector<<std::endl;}
    
    for (int j = 350; j <= 359; j++){
          double vector = msg -> ranges[j];
          std::cout<<"Rangos: "<<vector<<std::endl;}
          
          
          
    // Versión 4 : Calcular y mostrar el mínimo del vector:
    
    Eigen::Map<Eigen::VectorXf> vector_Eigen(vector.data(), vector.size());
    
    min = vector_Eigen.minCoeff();
    
    std::cout<<"El mínimo del vector es: "<<min<<std::endl;
    
   
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

  while (rclcpp::ok()) {
    message.linear.x = 0.0;
    message.angular.z = 0.0;
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}

