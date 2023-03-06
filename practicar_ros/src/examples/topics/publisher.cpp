#include <chrono> // proporciona elementos temporales
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[]){
    
    rclcpp::init(argc, argv); // INICIALIZAMOS
    
    auto node = rclcpp::Node::make_shared("publisher"); // CREACIÓN DE UN NODO
    
    auto publisher = node -> create_publisher<std_msgs::msg::String>("topic", 10);
    std_msgs::msg::String message;
    
    auto publish_count = 0;
    
    rclcpp::WallRate loop_rate(500ms); //timing
    
    while (rclcpp::ok()){ // PARA COMPROBAR SI SE HA LLAMADO A SHUTDOWN
        message.data = "Hello, world!" + std::to_string(publish_count++);
        publisher -> publish(message); // para su publicación
        rclcpp::spin_some(node); //timing
        loop_rate.sleep(); //timing
    }
    rclpp::shutdown(); //APAGADO
    return 0;
}




// Antes de usar |rclcpp| debe ser inicializado exactamente una vez por proceso
 
 
// Los nodos pueden tener editores y suscriptores sobre temas, brindar o solicitar servicios, tener parámetros y muchas otras cosas.



// MANERAS DE CREAR UN NODO

std::shared_ptr<rclcpp::Node> node = std::shared_ptr<rclcpp::Node>(new rclcpp::Node("simple_node"));

std::shared_ptr<rclcpp::Node> node = std::make_shared<rclcpp::Node>("simple_node");

rclcpp::Node::SharedPtr node = std::make_shared<rclcpp::Node>("simple_node");

auto node = std::make_shared<rclcpp::Node>("simple_node");

auto node = rclcpp::Node::make_shared("simple_node");



// Antes de publicar, hay que crear un mensaje y llenarlo con información.
//Hay muchos mensajes predefinidos que se definen en los paquetes de mensajes comunes que vienen con ROS, por ejemplo:

std_msgs/msg/String.msg
geometry_msgs/msg/Point.msg



/* Un topic es un nombre con un tipo de mensaje asociado.
Los editores publican nuevos mensajes en el tema y los suscriptores que se hayan suscrito al mismo tema (y con el mismo tipo de mensaje) recibirán esos mensajes de forma asíncrona.*/



/* La CREACIÓN DE UN PUBLISHER se realiza mediante el nodo y proporcionando:
- Nombre de tema
- Tipo de tema
- Profundidad de la cola de publicación

Asi pues : */

auto publisher = node -> create_publisher<std_msgs::msg::String>("topic", 10);

// La publicación se consigue llamando al método publish con un Mensaje como primer parámetro.

publisher -> publish(message);
