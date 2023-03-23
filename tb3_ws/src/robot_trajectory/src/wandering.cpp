#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/laserscan.hpp"

using namespace std::chrono_literals;

void wandering_callback(const sensor_msgs::msg::LaserScan msg){
	std::cout<< msg << std::endl;
}


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("wandering");
  auto publisher = node->create_publisher<sensor_msgs::msg::LaserScan>("cmd_vel", 10);
  sensor_msgs::msg::LaserScan message;
  auto publish_count = 0;
  rclcpp::WallRate loop_rate(10ms);

  while (rclcpp::ok()) {
    message.data = "Hello, world! " + std::to_string(publish_count++);
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}

