#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("publisher");
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  geometry_msgs::msg::Twist message;
  rclcpp::WallRate loop_rate(500ms);

  for(int j=0; j<4; j++){

  int i=0,n=1000;
  while (rclcpp::ok() && (i<n)){
    message.linear.x = 0.1;
    message.angular.z = 0;
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    i++;
  }
  
  i=0, n=170;
  while (rclcpp::ok() && (i<n)){
    message.linear.x = 0;
    message.angular.z = 0.1;
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    i++;
  }
  
  while (rclcpp::ok()){
    message.linear.x = 0;
    message.angular.z = 0;
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    i++;
  }
  }
  
  rclcpp::shutdown();
  return 0;
}

