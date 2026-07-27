#include <iostream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>
#include <print>


// server requires
/*
1. socket creation
2. struct sockaddr_in values configuration
3. bind
4. listen
5. accept
*/

int main(){
    char server_message[256] = "You have reached the server";
    int server_socket = socket(
        AF_INET, 
        SOCK_STREAM, 
        0
    );

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(1234);
    server_address.sin_addr.s_addr = INADDR_ANY; // accept connections from all interfaces in the network 0.0.0.0 

    // binding the socket
    /*
    bind arguments required
    arg1 = socket
    arg2 = typecast struct sockaddr_in variable to (struct sockaddr*)
    arg3 = size of sockaddr_in variable
    */
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    // listening
    // listen() arguments required
    /*
    arg1 = socket
    arg2 = number of connections to keep in queue waiting
    */
    listen(server_socket, 3);

    // accepting connections
    // accept() arguments required
    /*
    arg1 = socket
    */
    int client_socket = accept(
        server_socket,
        NULL,
        NULL
    );

    // after accepting connection from client
    // sending data to client from server
    // send() function
    // send() arguments required
    /*
        arg1 = client socket variable (during accept() function)
        arg2 = server message to send
        arg3 = size of server message
        arg4 = 0
    */
    send(
        client_socket, 
        server_message, 
        sizeof(server_message),
        0
    );

    close(server_socket);
    return 0;
}