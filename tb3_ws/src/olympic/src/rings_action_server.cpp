#include <inttypes.h>
#include <memory>
#include "olympic_interfaces/action/rings.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/srv/set_pen.hpp"
#include "turtlesim/srv/teleport_absolute.hpp"

using namespace std::chrono_literals;
using turtlesim::srv::SetPen;
using turtlesim::srv::TeleportAbsolute;

using Rings = olympic_interfaces::action::Rings;
  
using GoalHandleRings = rclcpp_action::ServerGoalHandle<Rings>;

rclcpp::Node::SharedPtr node = nullptr;


  rclcpp_action::GoalResponse handle_goal( const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const Rings::Goal> goal)
  {
  RCLCPP_INFO(rclcpp::get_logger("server"), 
    "Got goal request with radius %.*f", 2, goal->radius);
  (void)uuid;
  return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }


  rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleRings> goal_handle)
{
  RCLCPP_INFO(rclcpp::get_logger("server"), 
    "Got request to cancel goal");
  (void)goal_handle;
  return rclcpp_action::CancelResponse::ACCEPT;
}

  void execute(const std::shared_ptr<GoalHandleRings>);

  void handle_accepted(const std::shared_ptr<GoalHandleRings> goal_handle)
  {
    std::thread{execute, goal_handle}.detach();
  }
  
  void execute(
  const std::shared_ptr<GoalHandleRings> goal_handle)
{
  RCLCPP_INFO(rclcpp::get_logger("server"), "Executing goal");
  rclcpp::Rate loop_rate(1);
  
  const auto goal = goal_handle->get_goal();
  
  auto feedback = std::make_shared<Rings::Feedback>();
  auto result = std::make_shared<Rings::Result>();
  
  auto & ring_number = feedback-> drawing_ring;  
  auto & ring_angle = feedback->ring_angle;  
  
  
  float radius = goal->radius;  
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
  geometry_msgs::msg::Twist message;
  
  
  float velocidad_angular = 1.2, velocidad_linear  = radius * velocidad_angular;
  int j, iterations = 2*M_PI / (velocidad_angular * 0.1);
  
  rclcpp::WallRate loop_rate(100ms);
  
  int r[5] = {0, 0, 223, 244, 0};
  int g[5] = {129, 0, 0, 195, 159};
  int b[5] = {200, 0, 36, 0, 61};
	
  double desplazamiento_x[5] = {-2.166667, 0, 2.166667, -1.166667, 1.166667};
  double desplazamiento_y[5] = {0, 0, 0, -1, -1};
	
//SETPEN
  rclcpp::Client<SetPen>::SharedPtr client_set_pen = node->create_client<SetPen>("/turtle1/set_pen");
  auto request_set_pen = std::make_shared<SetPen::Request>();
	
//TeleportAbsolute
  rclcpp::Client<TeleportAbsolute>::SharedPtr client_teleport_absolute = node->create_client<TeleportAbsolute>("/turtle1/teleport_absolute");
	
  auto request_teleport_absolute = std::make_shared<TeleportAbsolute::Request>();
  
  
  for (int i = 0; i < 5; i++) {
    if (goal_handle->is_canceling()) {
      goal_handle->canceled(result);
      RCLCPP_INFO(rclcpp::get_logger("server"), 
      "Goal Canceled");
      return;
    }
    
    request_set_pen->r = r[i];
    request_set_pen->g = g[i];
    request_set_pen->b = b[i];
    
    request_set_pen->width = 5;
    request_set_pen->off = 1;
    
    auto result_set_pen = client_set_pen->async_send_request(request_set_pen);
    
//-----------------------------------------------
    
    request_teleport_absolute = std::make_shared<TeleportAbsolute::Request>();
    request_teleport_absolute->x = 5.544445 + desplazamiento_x[i] * radius;
    request_teleport_absolute->y = 5.544445 + desplazamiento_y[i] * radius;
    request_teleport_absolute->theta = 0;

    auto result_teleport_absolute = client_teleport_absolute->async_send_request(request_teleport_absolute);

//---------------------------------------------------------------
    ring_number = i+1;
    ring_angle = 0;
    
    goal_handle->publish_feedback(feedback);
    RCLCPP_INFO(rclcpp::get_logger("server"), "Publish Feedback");
    
    request_set_pen->off = 0;
    result_set_pen = client_set_pen->async_send_request(request_set_pen);
		
    j = 0;
    while (rclcpp::ok() && (j <= iterations)) {
        if (j == iterations/4) {  
            ring_angle = 90;
            goal_handle->publish_feedback(feedback);
    		RCLCPP_INFO(rclcpp::get_logger("server"), "Publish Feedback");
        } 
        else if (j == iterations/2) {  
            ring_angle = 180;
            goal_handle->publish_feedback(feedback);
    		RCLCPP_INFO(rclcpp::get_logger("server"), "Publish Feedback");
        } 
        else if (j == 3*iterations/4) {  
            ring_angle = 270;
            goal_handle->publish_feedback(feedback);
    		RCLCPP_INFO(rclcpp::get_logger("server"), "Publish Feedback");
        }
        message.linear.x = velocidad_linear;
        message.angular.z = velocidad_angular;
        publisher->publish(message);
			
        j++;
        loop_rate.sleep();
		}
		
		message.linear.x = 0.0;
		message.angular.z = 0.0;
		publisher->publish(message);
		loop_rate.sleep();
  }
  
  
  if (rclcpp::ok()) {
    result->rings_completed = ring_number;
    goal_handle->succeed(result);
    RCLCPP_INFO(rclcpp::get_logger("server"), "Goal Succeeded");
  }
}

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("action_server");
  auto action_server = rclcpp_action::create_server<Rings>(node,
      "rings",
      handle_goal,
      handle_cancel,
      handle_accepted);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
