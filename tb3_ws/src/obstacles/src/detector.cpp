#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

void callback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
{
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  
  auto node = rclcpp::Node::make_shared("detector");
  auto suscription = node->create_subscription<sensor_msgs::msg::LaserScan>("scan", 10, callback);
  
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

