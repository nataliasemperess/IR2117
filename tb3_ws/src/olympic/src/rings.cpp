#include <cstdio>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("rings");
    auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
    
    node -> declare_parameter("radius", 1.0); // Declare parameter

    geometry_msgs::msg::Twist message;
    rclcpp::WallRate loop_rate(500ms);
    
    double radius = node -> get_parameter("radius").get_parameter_value().get<double>();
    double time_circle = 2 * M_PI * radius ;
    int n_iterations = static_cast<int>(time_circle / 0.01); 


    // Call service SetPen
    // r -> 0;
    // g -> 0;
    // b -> 255;
    
    
    
    
    // Call service TeleportAbsolute
    
    // x -> 4.0;
    // y -> 5.5;
    // theta -> 0;
    
 
    
 
 
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

