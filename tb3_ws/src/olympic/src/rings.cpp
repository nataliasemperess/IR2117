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

    // ARO  AZUL

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
    
    // ARO  NEGRO

    // Call service SetPen
    
    auto SetPen_client_2 = node -> create_client<turtlesim::srv::SetPen>("/turtle1/set_pen")
    auto SetPen_request_2 = std::make_shared<turtlesim::srv::SetPen::Request>();
    
    SetPen_request_2 -> r = 0;
    SetPen_request_2 -> g = 0;
    SetPen_request_2 -> b = 0;
    SetPen_request_2 -> width = 4;
    
    SetPen_client_2->async_send_request(SetPen_request_2);
    
    
    // Call service TeleportAbsolute

    auto teleport_client_2 = node->create_client<turtlesim::srv::TeleportAbsolute>("/turtle1/teleport_absolute");
    auto teleport_request_2 = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    
    teleport_request_2->x = 5.5;
    teleport_request_2->y = 5.5;
    teleport_request_2->theta = 0;
    
    teleport_client_2->async_send_request(teleport_request_2);

    
    for (int = 0; i < 14;i++){
        
    message.linear.x = 1.0; 
    message.angular.z = 1.0; 
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    }


    // ARO  ROJO

    // Call service SetPen
    
    auto SetPen_client_3 = node -> create_client<turtlesim::srv::SetPen>("/turtle1/set_pen")
    auto SetPen_request_3 = std::make_shared<turtlesim::srv::SetPen::Request>();
    
    SetPen_request_3 -> r = 255;
    SetPen_request_3 -> g = 0;
    SetPen_request_3 -> b = 0;
    SetPen_request_3 -> width = 4;
    
    SetPen_client_3->async_send_request(SetPen_request_3);
    
    
    // Call service TeleportAbsolute

    auto teleport_client_3 = node->create_client<turtlesim::srv::TeleportAbsolute>("/turtle1/teleport_absolute");
    auto teleport_request_3 = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    
    teleport_request_3->x = 7.5;
    teleport_request_3->y = 5.5;
    teleport_request_3->theta = 0;
    
    teleport_client_3->async_send_request(teleport_request_3);
    
    for (int = 0; i < 14;i++){
        
    message.linear.x = 1.0; 
    message.angular.z = 1.0; 
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    }

    // ARO  VERDE

    // Call service SetPen
    
    auto SetPen_client_4 = node -> create_client<turtlesim::srv::SetPen>("/turtle1/set_pen")
    auto SetPen_request_4= std::make_shared<turtlesim::srv::SetPen::Request>();
    
    SetPen_request_4-> r = 0;
    SetPen_request_4 -> g = 255;
    SetPen_request_4 -> b = 0;
    SetPen_request_4 -> width = 4;
    
    SetPen_client_4->async_send_request(SetPen_request_4);
    
    
    // Call service TeleportAbsolute

    auto teleport_client_4 = node->create_client<turtlesim::srv::TeleportAbsolute>("/turtle1/teleport_absolute");
    auto teleport_request_4 = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    
    teleport_request_4->x = 6.5;
    teleport_request_4->y = 4.5;
    teleport_request_4->theta = 0;
    
    teleport_client_4->async_send_request(teleport_request_4);

    
    for (int = 0; i < 14;i++){
        
    message.linear.x = 1.0; 
    message.angular.z = 1.0; 
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    }


    // ARO  AMARILLO

    // Call service SetPen
    
    auto SetPen_client_5 = node -> create_client<turtlesim::srv::SetPen>("/turtle1/set_pen")
    auto SetPen_request_5 = std::make_shared<turtlesim::srv::SetPen::Request>();
    
    SetPen_request_5 -> r = 255;
    SetPen_request_5 -> g = 255;
    SetPen_request_5 -> b = 0;
    SetPen_request_5 -> width = 4;
    
    SetPen_client_5->async_send_request(SetPen_request_5);
    
    
    // Call service TeleportAbsolute

    auto teleport_client_5 = node->create_client<turtlesim::srv::TeleportAbsolute>("/turtle1/teleport_absolute");
    auto teleport_request_5 = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    
    teleport_request_5->x = 4.5;
    teleport_request_5->y = 4.5;
    teleport_request_5->theta = 0;
    
    teleport_client_5->async_send_request(teleport_request_5);

    
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

