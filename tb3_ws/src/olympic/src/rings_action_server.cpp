#include <inttypes.h>
#include <memory>
#include "action_tutorials_interfaces/action/rings.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"


int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("action_server");
  auto action_server = 
    rclcpp_action::create_server<Rings>(node,
      "rings",
      handle_goal,
      handle_cancel,
      handle_accepted);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}




