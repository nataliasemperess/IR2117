#include "rclcpp/rclcpp.hpp" // dependecias del paquete
#include "example_interfaces/srv/add_two_ints.hpp" // dependecias del paquete
#include <memory>

using example_interfaces::srv::AddTwoInts;

/* Función suma dos enteros de la petición, y devuelve la suma a la respuesta, 
   mientras notifica a la consola su estado usando logs */

void add(
  std::shared_ptr<AddTwoInts::Request>  request,
  std::shared_ptr<AddTwoInts::Response> response)
{
  response->sum = request->a + request->b; // suma

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
    "Incoming request\na: %ld" " b: %ld",
     request->a, request->b);
  
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
    "sending back response: [%ld]", 
     (long int)response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv); // Inicializa la libreria cliente ROS2

  // Crea un nodo llamado add_two_ints_server:
  
  std::shared_ptr<rclcpp::Node> node =  rclcpp::Node::make_shared("add_two_ints_server");
    
  // Crea un servicio llamado add_two_ints para ese nodo, y lo anuncia en las redes con &add

  rclcpp::Service<AddTwoInts>::SharedPtr service = node->create_service<AddTwoInts>("add_two_ints", &add);

  // Imprime el mensaje de registro cuando esta listo: 
  
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
    "Ready to add two ints.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}




