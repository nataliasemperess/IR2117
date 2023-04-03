#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using namespace std::chrono_literals;

int min_i = 0, min_j= 0;

void wandering_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg){
	
       for (int i = 0; i <= 9; i++){
          double vector = msg -> ranges[i];
          int min_i = 0;
          if (vector < min_i){
          	min_i = vector;}

       }
          
       for (int j = 350; j <= 359; j++){
          double vector = msg -> ranges[j];
          int min_j = 0;
          if (vector < min_j){
          	min_j = vector;
          }
   
       }
       std::cout<<"El mínimo del vector es: {"<<min_i<<","<<min_j<<"}"<<std::endl;

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

