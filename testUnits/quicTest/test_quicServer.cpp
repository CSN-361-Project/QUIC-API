#include "../../quicAPI.hpp"

int main(){
    
    // First we Set Up the QUIC Server Socket Object
    quicServer server = quicServer();

    // Server Details
    char *port = SERVER_PORT;

    // We Open a Listener on the Server on the Specified Port
    server.OpenListener(port);

    // Start Listening [This will make server ready to accept connections]
    server.StartListener();
    std::cout << "Server is listening on port : " << port << std::endl;
    
    // Initialize a new connection object
    quicConnection newConnection = quicConnection(0); // 0 for server

    // We will recieve the request in this buffer
    int length = 1024;
    char *request = new char[length];

    // We will keep the server running until we stop it [This is just for testing]
    while(server.isListening){

        // Accept a new connection
        std::cout << "Waiting for New Connection" << std::endl;
        newConnection = server.acceptConnection(); // It's a blocking call

        // Recieve the request
        int t = newConnection.recieveData(request, length);
        request[t] = '\0';
        std::cout << "Recieved Data : " << request << std::endl;

        // Open a new stream for sending response
        quicStream newStream = newConnection.openNewStream();
        std::cout << "New Stream Opened" << std::endl;

        // Send a response
        char response[] = "Hello Client\n";
        newStream.sendData(response, strlen(response));
        std::cout << "Response Sent : " << response << std::endl;
        
        // Close the connection
        std::cout << "Closing Connection" << std::endl;
        newConnection.closeConnection();

        std::cout << "---------------------------------" << std::endl;
    }

    // Stop the server
    server.StopListener();
    server.CloseListener();
    
    // --The End--
    return 0;
}

