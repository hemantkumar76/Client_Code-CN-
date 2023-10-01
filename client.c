// client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    char message[100];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error in socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);                   // Choose any available port for communication
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error in connect");
        exit(EXIT_FAILURE);
    }


        // Send message to server
    strcpy(message, "Hello, server!");
    send(sockfd, message, strlen(message), 0);

    // Close the socket
    close(sockfd);


    return 0;
}
