#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>


#define MAXLINE 1024

int main()
 {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr, cliaddr;

   if((sockfd = socket(AF_INET, SOCK_DGRAM,0)) < 0 )
 {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family    = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(6303);


    if (bind(sockfd, (const struct sockaddr *)&servaddr,sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

     int len, n;
    n = recvfrom(sockfd,(char *)buffer,MAXLINE,0,(struct sockaddr *)&cliaddr,&len);
    buffer[n] = '\0';
    printf("Client : %s\n", buffer);
    sendto(sockfd, (const char *)buffer,MAXLINE,0,(const struct sockaddr *) &cliaddr,&len);
    printf("Server : %s  sent \n ",buffer);

    return 0;
}
