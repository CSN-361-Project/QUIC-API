#include "../../quicAPI.hpp"

#define LOCALHOST INADDR_ANY

int main(){
    
    // First we Set Up the QUIC Client Socket Object
    quicClient client = quicClient();

    // Server IP and Port
    std::string ip = std::to_string(LOCALHOST); // We use Localhost for Testing
    int port = std::stoi(SERVER_PORT);

    // Next we Try Connect to the Server
    quicConnection connection = client.connectToServer(ip, port);

    // Open a new stream
    quicStream stream = connection.openNewStream();

    // Send a message
    char request1[] = "Hello Server\n";
    std::cout << "Sending Request : " << request1 << std::endl;
    stream.sendData(request1, strlen(request1));
    

    // Recieve the response
    int bufferlen = 1024;
    char *response = new char[bufferlen];
    int length = stream.receiveData(response, bufferlen);
    response[length] = '\0';

    // Print the response
    std::cout << "Response : " << response << std::endl;

    // Close the connection
    connection.closeConnection();
    std::cout << "---------------------------------" << std::endl;

    // --The End--
    return 0;
}