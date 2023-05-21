// Rings corregido

 #include "rclcpp/rclcpp.hpp" // Bibliotecas de ROS2 para C++
#include <chrono> // Biblioteca para trabajar con duraciones y tiempos

#define _USE_MATH_DEFINES // Para constantes matemáticas como M_PI

#include <math.h> //Para usar funciones y constantes matemáticas
#include <memory> // Para trabajar con punteros inteligentes
#include "geometry_msgs/msg/twist.hpp" // Para publicar comandos de velocidad

#include "turtlesim/srv/set_pen.hpp" // Para configurar el lápiz de la tortuga 
#include "turtlesim/srv/teleport_absolute.hpp" // Para teletransportar la tortuga a una posición absoluta
#include "turtlesim/srv/teleport_relative.hpp" // Para teletransportar la tortuga a una posición relativa

using namespace std::chrono_literals; // Utilizar literales de tiempo como 100ms

// Importanción de diferentes servicios

using turtlesim::srv::SetPen; 
using turtlesim::srv::TeleportAbsolute;
using turtlesim::srv::TeleportRelative;


int main(int argc, char * argv[]) {
    
  rclcpp::init(argc, argv); 
  
  // NODE, PUBLISHER AND MESSAGE
  
  // Creación de un nodo compartido llamado "rings" utilizando construcción estático de la clase "Node"
	std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("rings"); 
    
    // Creación de un publicador para el tipo de mensaje Twist en el tema /cmd_vel con un cola de mensajes de tamaño 10
	auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
	
    geometry_msgs::msg::Twist message; // Crea una instancia del mensaje llamada message
	
	// Data
	node->declare_parameter("radius", 1.0); // Declaración del parametro "radius" con valor predeterminado de 1.0 en el nodo.
    
	double radius = node->get_parameter("radius").get_parameter_value().get<double>(); // Obtener el valor del parámetro "radius" del nodo y lo asigna a la variable "radius"
    
	float v_angular = 1.2, v_linear  = radius * v_angular; // Calcula v_angular y v_linear basadas en el radio y valor constante
    int j, iterations = 2*M_PI / (v_angular * 0.1); // Num de iteraciones necesarias para dibujar círculo completo basado en la velocidad angular
				 
	rclcpp::WallRate loop_rate(100ms); // Crea instancia de WallRate con frec de ciclo de 100ms, esto determina velocidad de bucle del programa
	
    
	// Iteration values
    
	int r[5] = {0, 0, 223, 244, 0}; // Define arreglo de enteros "r" con valores predefinidos para los componentes rojos de los colores de los círculos.
	
	int g[5] = {129, 0, 0, 195, 159}; // Define arreglo de enteros "g" con valores predefinidos para los componentes verdes de los colores de los círculos.
	
	int b[5] = {200, 0, 36, 0, 61}; // Define arreglo de enteros "b" con valores predefinidos para los componentes azules de los colores de los círculos.
	
	// Ahora definimos un arreglo de números de coma flotante "desplazamiento_x" con desplaz horizontales predefinidos para los circulos
	double desplazamiento_x[5] = {-2.166667, 0, 2.166667, -1.166667, 1.166667}; 
    
	// Después definimos un arreglo de números de coma flotante "desplazamiento_y" con desplaz verticales predefinidos para los circulos
	double desplazamiento_y[5] = {0, 0, 0, -1, -1};
	
    
    
	// Initialize SetPen service
    
    // Creamos un cliente para el servicio SetPen en el tema /turtle1/set_pen
	rclcpp::Client<SetPen>::SharedPtr client_set_pen = node->create_client<SetPen>("/turtle1/set_pen");
	
    // Creamos una solicitud de servicio SetPen utilizando un puntero inteligentes "shared_ptr"
    auto request_set_pen = std::make_shared<SetPen::Request>();
    
    // Envía asincrónicamente la solicitud de servicio SetPen utilizando el cliente creado anteriormente
	auto result_set_pen = client_set_pen->async_send_request(request_set_pen);
	
    
    
	// Initialize TeleportAbsolute service
    
    // Creamos un cliente para el servicio TeleportAbsolute en el tema /turtle1/teleport_absolute
	rclcpp::Client<TeleportAbsolute>::SharedPtr client_teleport_absolute =
    node->create_client<TeleportAbsolute>("/turtle1/teleport_absolute");
    
    // Creamos una solicitud de servicio TeleportAbsolute utilizando un puntero inteligentes "shared_ptr"
	auto request_teleport_absolute = std::make_shared<TeleportAbsolute::Request>();
    
    // Envía asincrónicamente la solicitud de servicio TeleportAbsolute utilizando el cliente creado anteriormente
	
    auto result_teleport_absolute = client_teleport_absolute->async_send_request(request_teleport_absolute);
	
	
	for (int i = 0; i < 5; i++) { // Inicia un bucle que itera cinco veces para dibujar cinco círculos.
        
		// Change colors and disable pen
		request_set_pen->r = r[i];  // Establece el componente rojo de la solicitud de servicio SetPen al valor correspondiente del arreglo r.
		
		request_set_pen->g = g[i]; //  Establece el componente verde de la solicitud de servicio SetPen al valor correspondiente del arreglo g.
		
		request_set_pen->b = b[i]; // Establece el componente azul de la solicitud de servicio SetPen al valor correspondiente del arreglo b.
		
		request_set_pen->width = 5; // Establece el ancho del lápiz en 5 en la solicitud de servicio SetPen.
		
		request_set_pen->off = 1;  // Establece el valor de apagado en 1 para desactivar el lápiz en la solicitud de servicio SetPen.
		
		while (!client_set_pen->wait_for_service(1s)) { // Espera hasta que el servicio SetPen esté disponible.
		 
            if (!rclcpp::ok()) {
                
		     RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Circle %i: Interrupted while waiting for the SetPen service.", i+1);
             
		    return 0;
		 	}
        
            // Mostrar un mensaje informativo cuando el servicio SetPen no está disponible y se está esperando       nuevamente.

		 	RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Circle %i: SetPen service not available, waiting again...", i+1);
            
            
     }
		result_set_pen = client_set_pen->async_send_request(request_set_pen); // Envía asincrónicamente la solicitud de servicio SetPen.
		
        // Ahora espera hasta que se complete el resultado de la solicitud de servicio SetPen
		if (rclcpp::spin_until_future_complete(node, result_set_pen) ==	rclcpp::FutureReturnCode::SUCCESS)
		{
          // Muestrará un mensaje informativo cuando se llama al servicio SetPen con éxito.
		  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Circle %i: Succesfully called SetPen service", i+1);
		} else {
        // Muestra un mensaje de error cuando falla la llamada al servicio SetPen.
		  RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Circle %i: Failed to call service SetPen", i+1);
		}
		
		// Circle absolute position
		request_teleport_absolute = std::make_shared<TeleportAbsolute::Request>();
        
        // Establecer la coordenada x de la solicitud de servicio TeleportAbsolute al valor calculado.
		request_teleport_absolute->x = 5.544445 + desplazamiento_x[i] * radius; 
        
        // Establecer la coordenada y de la solicitud de servicio TeleportAbsolute al valor calculado.
		request_teleport_absolute->y = 5.544445 + desplazamiento_y[i] * radius;
        
        // Establecer el ángulo theta de la solicitud de servicio TeleportAbsolute en 0.
		request_teleport_absolute->theta = 0;
		
		while (!client_teleport_absolute->wait_for_service(1s)) { // Espera hasta que el servicio TeleportAbsolute esté disponible.
		  if (!rclcpp::ok()) {
		    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), 
		     "Circle %i: Interrupted while waiting for the TeleportAbsolute service.", i+1);
		    return 0;
		 	}
		 	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
		   "Circle %i: TeleportAbsolute service not available, waiting again...", i+1);
  	}
        // Enviar asincrónicamente la solicitud de servicio TeleportAbsolute.
		result_teleport_absolute = client_teleport_absolute->async_send_request(request_teleport_absolute);
		
		if (rclcpp::spin_until_future_complete(node, 
       result_teleport_absolute) ==	rclcpp::FutureReturnCode::SUCCESS) //Espera hasta que se complete el resultado de la solicitud de servicio TeleportAbsolute.
        
		{
		  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
		   "Circle %i: Succesfully called TeleportAbsolute service", i+1);
		} else {
		  RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), 
		   "Circle %i: Failed to call service TeleportAbsolute", i+1);
		}
		
		// Turn pen back on
		request_set_pen->off = 0; // Se establece el valor de apagado en 0 para volver a encender el lápiz y permitir que la tortuga dibuje.
		result_set_pen = client_set_pen->async_send_request(request_set_pen); // Se envía la solicitud de servicio SetPen para encender el lápiz de la tortuga.
		
		loop_rate.sleep(); // Se duerme durante el tiempo restante del ciclo para mantener la frecuencia de ciclo establecida anteriormente.
        
        
		// Draw the circle
		j = 0; // para contar el número de iteraciones del bucle mientras se dibuja el círculo.
		
		// Ahora se inicia un bucle que continúa mientras ROS está en estado activo (rclcpp::ok()) y el número de iteraciones no ha excedido el valor de iterations.
		
		while (rclcpp::ok() && (j <= iterations)) {
			message.linear.x = v_linear; // Se establece la velocidad lineal en el mensaje Twist para que la tortuga se mueva en línea recta.
			message.angular.z = v_angular; // Se establece la velocidad angular en el mensaje Twist para que la tortuga gire.
			publisher->publish(message); //Se publica el mensaje Twist en el tema "/turtle1/cmd_vel" para mover la tortuga según las velocidades especificadas.
			
			j++;
			rclcpp::spin_some(node); //Se procesan las devoluciones de llamada pendientes para los nodos de ROS.
			loop_rate.sleep();
		}
		
        //Se establece la velocidad lineal y angular en cero para detener la tortuga.
		message.linear.x = 0.0;
		message.angular.z = 0.0;
		publisher->publish(message);
		rclcpp::spin_some(node);
		loop_rate.sleep();
	}
	
	rclcpp::shutdown(); // : Se apaga el sistema de comunicación de ROS 2.
	return 0;
}

/*#include <cstdio>
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
    
    auto SetPen_client = node -> create_client<turtlesim::srv::SetPen>("/turtle1/set_pen");
    auto SetPen_request = std::make_shared<turtlesim::srv::SetPen::Request>();
    
    SetPen_request -> r = 0;
    SetPen_request -> g = 0;
    SetPen_request -> b = 255;
    SetPen_request -> width = 4;
    SetPen_request -> off = false;
    
    SetPen_client->async_send_request(SetPen_request);
    
    
    // Call service TeleportAbsolute

    auto teleport_client = node->create_client<turtlesim::srv::TeleportAbsolute>("/turtle1/teleport_absolute");
    auto teleport_request = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    
    teleport_request->x = 0;
    teleport_request->y = 5.5;
    teleport_request->theta = 0;
    
    teleport_client->async_send_request(teleport_request);

    
    for (int i= 0; i < 14;i++){
        
        
    SetPen_request->off = true;
    message.linear.x = 1.0; 
    message.angular.z = 1.0; 
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    }
    SetPen_request ->off = false;
    // ARO  NEGRO

    // Call service SetPen
    
    auto SetPen_client_2 = node -> create_client<turtlesim::srv::SetPen>("/turtle1/set_pen");
    auto SetPen_request_2 = std::make_shared<turtlesim::srv::SetPen::Request>();
    
    SetPen_request_2 -> r = 0;
    SetPen_request_2 -> g = 0;
    SetPen_request_2 -> b = 0;
    SetPen_request_2 -> width = 4;
    SetPen_request_2 -> off = false;
    
    SetPen_client_2->async_send_request(SetPen_request_2);
    
    
    // Call service TeleportAbsolute

    auto teleport_client_2 = node->create_client<turtlesim::srv::TeleportAbsolute>("/turtle1/teleport_absolute");
    auto teleport_request_2 = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    
    teleport_request_2->x = 5.5;
    teleport_request_2->y = 5.5;
    teleport_request_2->theta = 0;
    
    teleport_client_2->async_send_request(teleport_request_2);
    

    
    for (int i = 0; i < 14;i++){
        
    SetPen_request_2 ->off = true;
    message.linear.x = 1.0; 
    message.angular.z = 1.0; 
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    }
    
    SetPen_request_2 ->off = false;


    // ARO  ROJO

    // Call service SetPen
    
    auto SetPen_client_3 = node -> create_client<turtlesim::srv::SetPen>("/turtle1/set_pen");
    auto SetPen_request_3 = std::make_shared<turtlesim::srv::SetPen::Request>();
    
    SetPen_request_3 -> r = 255;
    SetPen_request_3 -> g = 0;
    SetPen_request_3 -> b = 0;
    SetPen_request_3 -> width = 4;
    SetPen_request_3 -> off = false;
    
    SetPen_client_3->async_send_request(SetPen_request_3);
    
    
    // Call service TeleportAbsolute

    auto teleport_client_3 = node->create_client<turtlesim::srv::TeleportAbsolute>("/turtle1/teleport_absolute");
    auto teleport_request_3 = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    
    teleport_request_3->x = 7.5;
    teleport_request_3->y = 5.5;
    teleport_request_3->theta = 0;
    
    teleport_client_3->async_send_request(teleport_request_3);
    

    for (int i= 0; i < 14;i++){
    SetPen_request_3->off = true;
    
    message.linear.x = 1.0; 
    message.angular.z = 1.0; 
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    }
    
    SetPen_request_3 -> off = false;

    // ARO  VERDE

    // Call service SetPen
    
    auto SetPen_client_4 = node -> create_client<turtlesim::srv::SetPen>("/turtle1/set_pen");
    auto SetPen_request_4= std::make_shared<turtlesim::srv::SetPen::Request>();
    
    SetPen_request_4-> r = 0;
    SetPen_request_4 -> g = 255;
    SetPen_request_4 -> b = 0;
    SetPen_request_4 -> width = 4;
    SetPen_request_4 -> off = false;
    
    SetPen_client_4->async_send_request(SetPen_request_4);
    
    
    // Call service TeleportAbsolute

    auto teleport_client_4 = node->create_client<turtlesim::srv::TeleportAbsolute>("/turtle1/teleport_absolute");
    auto teleport_request_4 = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    
    teleport_request_4->x = 6.5;
    teleport_request_4->y = 4.5;
    teleport_request_4->theta = 0;
    
    teleport_client_4->async_send_request(teleport_request_4);
    
    
    for (int i = 0; i < 14;i++){
    
    SetPen_request_4->off = true;
    message.linear.x = 1.0; 
    message.angular.z = 1.0; 
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    }

    SetPen_request_4->off = false;

    // ARO  AMARILLO

    // Call service SetPen
    
    auto SetPen_client_5 = node -> create_client<turtlesim::srv::SetPen>("/turtle1/set_pen");
    auto SetPen_request_5 = std::make_shared<turtlesim::srv::SetPen::Request>();
    
    SetPen_request_5 -> r = 255;
    SetPen_request_5 -> g = 255;
    SetPen_request_5 -> b = 0;
    SetPen_request_5 -> width = 4;
    SetPen_request_5 -> off = false;
    
    SetPen_client_5->async_send_request(SetPen_request_5);
    
    
    // Call service TeleportAbsolute

    auto teleport_client_5 = node->create_client<turtlesim::srv::TeleportAbsolute>("/turtle1/teleport_absolute");
    auto teleport_request_5 = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    
    teleport_request_5->x = 4.5;
    teleport_request_5->y = 4.5;
    teleport_request_5->theta = 0;
    
    teleport_client_5->async_send_request(teleport_request_5);
    
    
    for (int i = 0; i < 14;i++){

    SetPen_request_5->off = true;

    message.linear.x = 1.0; 
    message.angular.z = 1.0; 
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    }
    
    SetPen_request_5 -> off = false;
    
    rclcpp::shutdown();
    return 0;
    }

*/
