#include <iostream>
#include <chrono>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"

using namespace std::chrono_literals;

bool ayuda = false;
double variable_x0, variable_y0, yaw_inicial,total_dif_pos, dif_angulo;

void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg){
	std::cout<< msg << std::endl;
}

void topic_callback(const nav_msgs::msg::Odometry::SharedPtr msg){
  
  double variable_x = msg -> pose.pose.position.x;
  double variable_y = msg -> pose.pose.position.y;
  std::cout<<"x : "<<variable_x<<std::endl;
  std::cout<<"y : "<<variable_y<<std::endl;
  
  
  
  double x1 = msg-> pose.pose.orientation.x;
  double y1 = msg-> pose.pose.orientation.y;
  double z1 = msg->pose.pose.orientation.z;
  double w1 = msg-> pose.pose.orientation.w;


  double siny_cosp = 2 * (w1 * z1 + x1 * y1);
  double cosy_cosp = 1 - 2 * (y1 * y1 + z1 * z1);
  double yaw = atan2(siny_cosp, cosy_cosp);
  std::cout<<"angle : "<<yaw<<std::endl;
  
  if (not ayuda){
    variable_x0 = msg -> pose.pose.position.x;
    variable_y0 = msg -> pose.pose.position.y;
    yaw_inicial = atan2(siny_cosp, cosy_cosp);
    ayuda = true;
   }  
   double dif_posiciones_x = variable_x - variable_x0;
   double dif_posiciones_y = variable_y - variable_y0;
   total_dif_pos = sqrt(pow(dif_posiciones_x, 2) + pow(dif_posiciones_y, 2));
   std::cout<<"La distancia entre la posicion actual y la inicial es : "<<total_dif_pos<<std::endl;	
   
   dif_angulo = abs(yaw - yaw_inicial);
   std::cout<<"La diferencia entre el angulo actual con el inicial es: "<<std::endl;
	
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("square_odom");
  auto square_odom = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  auto subscripcion = node->create_subscription<nav_msgs::msg::Odometry>("odom", 10, odom_callback);
  node -> declare_parameter("linear_speed", 0.1);
  node -> declare_parameter("angular_speed", 3.1416 / 20);
  geometry_msgs::msg::Twist message;
 
  
  rclcpp::WallRate loop_rate(10ms);

  double linear_speed = node->get_parameter("linear_speed").get_parameter_value().get<double>();
  double angular_speed = node->get_parameter("angular_speed").get_parameter_value().get<double>();
  for(int j=0; j<4; j++){
	while (rclcpp::ok() && (total_dif_pos < 1.0)){
	   message.linear.x = linear_speed;
	   message.angular.z = 0.0;
	   square_odom->publish(message);
	   rclcpp::spin_some(node);
	   loop_rate.sleep();
	 }
	  while (rclcpp::ok() && (dif_angulo < (M_PI)/2)){
	    message.linear.x = 0;
	    message.angular.z = angular_speed;
	    square_odom->publish(message);
	    rclcpp::spin_some(node);
	    loop_rate.sleep();
	  }
	  
  }
  
  rclcpp::shutdown();
  return 0;
}

