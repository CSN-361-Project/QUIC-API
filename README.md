# QUIC API Guide

## How to Use

### Steps to Get Started

1. **Clone the Repository**  
   Clone this repository to your local machine using:
   ```bash
   git clone <repository-url>
   ```

2. **Include the QUIC API Header**  
   Ensure to include `quicAPI.hpp` in your project:
   ```cpp
   #include "path/to/quicAPI.hpp"
   ```

## Server-Side Implementation

### `quicServer` Class Overview
The `quicServer` class facilitates the creation of a server-side socket for handling QUIC protocol connections.

- **Creating the Server**  
  Instantiate the server:
  ```cpp
  quicServer server;
  ```

- **Opening the Listener**  
  Use `OpenListener()` to bind the socket to a specific port:
  ```cpp
  server.OpenListener("port_number");
  ```

- **Starting the Listener**  
  Prepare the server to accept new connections:
  ```cpp
  server.StartListener();
  ```

- **Accepting Connections**  
  Accepts an incoming client connection and returns a `quicConnection` object for communication:
  ```cpp
  quicConnection newConnection = server.acceptConnection();
  ```

- **Stopping the Listener**  
  Stop the listener when needed:
  ```cpp
  server.StopListener();
  ```

## Client-Side Implementation

### `quicClient` Class Overview
The `quicClient` class is used to create and manage a client-side QUIC socket.

- **Creating the Client**  
  Instantiate the client:
  ```cpp
  quicClient client;
  ```

- **Connecting to a Server**  
  Establish a connection to a server using its IP and port:
  ```cpp
  quicConnection connection = client.connectToServer("server_ip", port_number);
  ```

## `quicConnection` Class

The `quicConnection` class handles the transmission of data between client and server.

- **Sending Data**  
  Send data using the `sendData()` function:
  ```cpp
  connection.sendData("message", length);
  ```

- **Receiving Data**  
  Receive data using the `receiveData()` function:
  ```cpp
  int len = connection.receiveData(buffer, buffer_length);
  ```

- **Opening a New Stream**  
  Open a new byte-stream for communication:
  ```cpp
  quicStream stream = connection.openNewStream();
  ```

## `quicStream` Class

Each stream provides a separate byte-stream for data transfer, enabling parallel data exchange.

- **Sending Data on a Stream**  
  Use `sendData()` to send a message:
  ```cpp
  stream.sendData("message", length);
  ```

- **Receiving Data on a Stream**  
  Use `receiveData()` to read incoming data:
  ```cpp
  int len = stream.receiveData(buffer, buffer_length);
  ```

## Summary
This API offers a straightforward way to set up and manage QUIC connections for both server and client applications. With classes tailored for creating sockets, handling connections, and managing streams, you can build efficient and high-performance networking applications.

Feel free to refer to the code examples provided and modify them as needed for your specific use case.
```
