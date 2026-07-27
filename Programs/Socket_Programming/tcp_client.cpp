// building a client using socket programming
#include<iostream> // basic input output 
#include<cstdlib> // used for general utility functions
#include<sys/socket.h> // used for socket programming
#include<sys/types.h> // used for handling data received in sockets
#include <netinet/in.h> // header file for datat structures constants used in socket programming
// like sockaddr_in, in_addr, INADDR_ANY .etc...
#include <unistd.h> // Required for close()


// client requires
/*
1. socket creation
2. sockaddr_in struct values setup
3. connect
4. recv
*/


int main(){
    // creating a socket
    int client_socket = socket(
        AF_INET, // specify the IPv4 address family
        SOCK_STREAM, // handle TCP connections
        0 // use the default protocol   
    );

    // checkig whether socket creation was done properly or not
    if(client_socket < 0){
        std::perror("Socket creation failed");
        std::cout << std::endl;
        std::exit(EXIT_FAILURE); // exit_failure is a predefined macro constant in c/c++ that represents unecessary program termination
    }

    // creating address structure 
    // to specify where to connect to
    struct sockaddr_in server_address; // delaring structure variable for target server

    // below we are assigning details for the target server so that we can send our info    
    
    server_address.sin_family = AF_INET; // sin_family is for defining address family like IPV4 or IPV6 .etc...


    //WHY USE HTONS() OR HTONL() IN THE FIRST PLACE????
    /*
    network communication reads big endian
    our computer stores data in little endian
    so if we send the data like that, the big endian interpretation in the network communication would be wrong
    so we use htons to arrange the data in the right byte order
    */

    // arranges our port value to the correct byte order
    // the byte order should be network byte order which is big endian so htons() does that 
    // htons arranges unsinged 16 bit integer to network byte order
    server_address.sin_port = htons(1234); // connect to this port remotely or locally
    // server_address.sin_addr  can be used to assign our target server IP
    // but .sin_addr itself is a structure
    // so we need to assign .sin_addr.s_addr is the data memeber which actually contains the data holding the IP

    // htonl arranges unsigned 32 bit integer to network byte order
    server_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);// INADDR_LOOPBACK = "127.0.0.1" = localhost


    // connecting to target server
    int connection_status = connect(
        client_socket, 
        (struct sockaddr *)&server_address, 
        sizeof(server_address)
    );

    // args1 = socket fd
    // args2 = typecast struct sockaddr_in variable to (struct sockaddr *)
    // args3 = size of the structure variable struct sockaddr_in
    if(connection_status < 0){
        std::perror("Connection failed");
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }
    char server_response[256];
    int receive_status = recv(
        client_socket, 
        &server_response, 
        sizeof(server_response),
        0
    );
    // recv = receive data from target server
    // arg1 = socket used to connect to target server
    // arg2 = address of response variable 
    // arg3 = size of response variable
    // arg4 = flags parameter keep it 0

    // display response
    std::cout << server_response << std::endl;
    // closing socket
    close(client_socket);
    return 0;
}
