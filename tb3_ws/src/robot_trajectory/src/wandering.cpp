#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using namespace std::chrono_literals;

void wandering_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg){
	std::cout<< msg << std::endl; 
       double rango1 = msg-> ranges[0];
       double rango2 = msg-> ranges[90];
       double rango3 = msg-> ranges[180];
       double rango4 = msg-> ranges[270];
       std::cout<<"Rango 1 : "<<rango1<<std::endl;
       std::cout<<"Rango 2 : "<<rango2<<std::endl;
       std::cout<<"Rango 3 : "<<rango3<<std::endl;
       std::cout<<"Rango 4 : "<<rango4<<std::endl;
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

