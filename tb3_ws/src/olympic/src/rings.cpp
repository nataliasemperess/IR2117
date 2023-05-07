#include <cstdio>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/srv/set_pen.hpp"
#include "turtlesim/srv/teleport_absolute.hpp"

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
    
    auto SetPen_client = node -> create_client<turtlesim::srv::SetPen>("/turtle1/set_pen")
    auto SetPen_request = std::make_shared<turtlesim::srv::SetPen::Request>();
    
    SetPen_request -> r = 0;
    SetPen_request -> g = 0;
    SetPen_request -> b = 255;
    SetPen_request -> width = 4;
    SetPen_request -> off = true;
    
    SetPen_client->async_send_request(SetPen_request);
    
    
    // Call service TeleportAbsolute

    auto teleport_client = node->create_client<turtlesim::srv::TeleportAbsolute>("/turtle1/teleport_absolute");
    auto teleport_request = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    
    teleport_request->x = 3.5;
    teleport_request->y = 5.5;
    
    teleport_request->theta = 0;
    
    teleport_client->async_send_request(teleport_request);

    SetPen_request->off = false;
    
    for (int = 0; i < 14;i++){
        
    message.linear.x = 1.0; 
    message.angular.z = 1.0; 
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
    }

