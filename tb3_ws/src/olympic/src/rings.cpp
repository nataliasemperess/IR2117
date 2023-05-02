#include <cstdio>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;


class MinimalParam : public rclcpp::Node
{
public:
  MinimalParam() 
  : Node("minimal_param_node")
  {
    this -> declare_parameter("my_parameter", "world");
  
  timer_t = this -> create_wall_timer(
    1000ms, std::bind(&MinimalParam::timer_callback, this));
  }
  
  void timer_callback(){
    std::string my_param = this -> get_parameter("my_parameter").as_string();
    
    RCLCPP_INFO(this->get_logger(), "Hello ½s!", my_param.c_str();
    
    std::vector<rclcpp::Parameter> all_new_parameters{rclcpp::Parameter("my_parameter","world" this -> set_parameters(all_new_parameters);
    }
};

int main(int argc, char * argv[])
{
 rclcpp::init(argc, argv);
 
 auto node = rclcpp::Node::make_shared("rings");
 auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
 
 geometry_msgs::msg::Twist message;
 
 auto publish_count = 0;
 rclcpp::WallRate loop_rate(500ms);
 
 while (rclcpp::ok()) {
   message.linear.x = 1.0; 
   message.angular.z = 1.0; 
   publisher->publish(message);
   rclcpp::spin_some(node);
   loop_rate.sleep();
 }
 rclcpp::shutdown();
 return 0;
}

