#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

void topic_callback(const std_msgs::msg::String::SharedPtr msg)
{
   std::cout<< msg -> data << std::endl;
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("subscriber");
  auto suscription = node->create_subscription<std_msgs::msg::String>("topic", 10, topic_callback);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

