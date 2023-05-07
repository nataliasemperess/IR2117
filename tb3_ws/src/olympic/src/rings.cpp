#include <cstdio>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/srv/set_pen.hpp"

using namespace std::chrono_literals;


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("rings");
    auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
    
    geometry_msgs::msg::Twist message;
    rclcpp::WallRate loop_rate(500ms);
    
   
    node -> declare_parameter("radius", 1.0); // Declare parameter
    double radius = node->get_parameter("radius").as_double();


    // Call service SetPen
    
    auto client = node -> create_client<turtlesim::srv::SetPen>("/turtle1/set_pen")
    auto request = std::make_shared<turtlesim::srv::SetPen::Request>();
    
    request -> r = 0;
    request -> g = 0;
    request -> b = 255;

    request -> width = 4;
    request -> off = true;
    client->async_send_request(request);
    
    
    
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

