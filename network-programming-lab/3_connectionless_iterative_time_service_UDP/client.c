#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>



#define MAXLINE 1024


int main() {
    int sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from client";
    struct sockaddr_in servaddr;
         if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 )
                {
                  perror("socket creation failed");
                    exit(EXIT_FAILURE);
                  }


                memset(&servaddr, 0, sizeof(servaddr));


                 servaddr.sin_family = AF_INET;
               servaddr.sin_port = htons(6303);
            servaddr.sin_addr.s_addr = INADDR_ANY;

         int n, len;
        printf("enter the message: ");
      fgets(buffer,MAXLINE,stdin);
 sendto(sockfd, (const char *)buffer, MAXLINE,MSG_CONFIRM,(const struct sockaddr *) &servaddr,sizeof(servaddr));
  printf(" message sent.\n");

 n = recvfrom(sockfd, (char *)buffer,MAXLINE,MSG_WAITALL,(struct sockaddr *) &servaddr,&len);
     buffer[n] = '\0';
    printf("Server : %s\n", buffer);

  close(sockfd);
 return 0;
}
