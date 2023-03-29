#include <chrono>
#include <iostream>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"

using namespace std::chrono_literals;

double distance_x1_actual, distance_y1_actual, distance1_actual, distance_yaw1_actual,variable_x_ini,variable_y_ini,yaw_ini;

bool prueba = false;

void topic_callback(const nav_msgs::msg::Odometry::SharedPtr msg){

    double variable_x = msg -> pose.pose.position.x;
    double variable_y = msg -> pose.pose.position.y;
    std::cout<< "x : " << variable_x <<std::endl;
    std::cout<< "y : " << variable_y <<std::endl;

    double x1 = msg -> pose.pose.orientation.x;
    double y1 = msg -> pose.pose.orientation.y;
    double z1 = msg -> pose.pose.orientation.z;
    double w1 = msg -> pose.pose.orientation.w;

    double siny_cosp = 2 * (w1*z1+x1*y1);
    double cosy_cosp = 1-2*(y1*y1+z1*z1);
    double yaw = atan2(siny_cosp, cosy_cosp);
    std::cout<<"angle : "<<yaw<<std::endl;
   	 
    if (prueba == false){
   	 variable_x_ini = msg -> pose.pose.position.x;
   	 variable_y_ini = msg -> pose.pose.position.y;
   	 yaw_ini = atan2(siny_cosp, cosy_cosp);
   	 prueba = true;
    }
    distance_x1_actual = variable_x - variable_x_ini;
    distance_y1_actual = variable_y - variable_y_ini;
    distance1_actual = sqrt(pow(distance_x1_actual,2)+ pow(distance_y1_actual,2));
    std::cout<<"La distancia entre la posición inicial y actual es : "<<distance1_actual<<std::endl;
    distance_yaw_ini_actual = abs(yaw - yaw_ini);
    std::cout<<"La distancia entre el angulo incial y el actual es : "<<distance_yaw_ini_actual<<std::endl;    
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("square_odom");
  auto square_odom = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  auto subscription = node->create_subscription<nav_msgs::msg::Odometry>("odom", 10, topic_callback);
  node->declare_parameter("linear_speed", 0.1);
  node->declare_parameter("angular_speed", 3.1416/20);
  geometry_msgs::msg::Twist message;
  rclcpp::WallRate loop_rate(10ms);

  double linear_speed = node->get_parameter("linear_speed").get_parameter_value().get<double>();
  double angular_speed = node->get_parameter("angular_speed").get_parameter_value().get<double>();
  for(int j=0; j<4; j++){
      distance1_actual = 0.0;
      while (rclcpp::ok() && (distance1_actual<1)) {
    	message.linear.x = linear_speed;
    	message.angular.z = 0.0;
    	square_odom->publish(message);
    	rclcpp::spin_some(node);
    	loop_rate.sleep();
      }
      
      while (rclcpp::ok() && (distance_yaw_ini_actual<(M_PI/2))) {
    	message.linear.x = 0.0;
    	message.angular.z = angular_speed;
    	square_odom->publish(message);
    	rclcpp::spin_some(node);
    	loop_rate.sleep();
      }
      prueba=false;
  }
  while (rclcpp::ok()) {
	message.linear.x = 0.0;
	message.angular.z = 0.0;
	square_odom->publish(message);
	rclcpp::spin_some(node);
	loop_rate.sleep();
  }
 
  rclcpp::shutdown();
  return 0;

}

