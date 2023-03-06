#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

void topic_callback(const std_msgs::msg::String::SharedPtr msg){
    std::cout<< msg -> data << std::endl;}




int main(int argc, char** argv){
    
    rclcpp::init(argc, argv); // inicializamos
    auto node = rclcpp::Node::make_shared("subscriber"); // creamos nuevo nodo
    auto subscriber = node -> create_subscription<std_msgs::msg::String>("topic", 10, topic_callback);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}


/* La creación de una Suscripción se realiza utilizando el nodo y proporcionando:
- Nombre de tema, 
- Tipo de tema, 
- Profundidad de la cola de publicación,
- Función de callback

La función topic_callback recibe los datos del mensaje de cadena publicado sobre el tema, y simplemente los imprime en la salida estándar.

*/


//Para el subscriber, spinning significa simplemente prepararse para recibir los mensajes cuando lleguen.

...
rclcpp::init()
...
rclcpp::spin();
rclcpp::shutdown()
