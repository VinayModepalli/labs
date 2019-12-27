#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
main(int argc, char *argv[])
{
int sockfd, rval;
char buff1[256],buff2[256];
struct sockaddr_in server, client;
int len;
sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
if(sockfd==-1)
{
perror("\n SOCK_ERR\n");
exit(1);
}
server.sin_family=AF_INET;
server.sin_addr.s_addr = INADDR_ANY;
server.sin_port=htons(1375);
rval=connect(sockfd,(struct sockaddr *)&server, sizeof(server));
if(rval!=-1)
{
printf("\n enter a message \n");
scanf("%s",buff1);
rval=send(sockfd,buff1,sizeof(buff1),0);
if(rval==-1)
{
perror("\n SEND_ERR\n");
exit(1);
}
rval=recv(sockfd,buff2,sizeof(buff2),0);
if(rval!=-1)
{
printf("\n Received message is %s \n", buff2);
}
else
{
perror("\nRECV_ERR\n");
exit(1);
}
}
else
{
printf("\n CONNECT_ERR\n");
exit(1);
}
}
