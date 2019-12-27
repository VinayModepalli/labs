#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
main(int argc, char *argv[])
{
int sockfd,new_sockfd,rval,pid;
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
server.sin_addr.s_addr = INADDR_ANY ;
server.sin_port=htons(1375);
rval=bind(sockfd,(struct sockaddr*)&server,sizeof(server));
if(rval!=-1)
{
listen(sockfd,5);
while(1)
{
new_sockfd=accept(sockfd,(struct sockaddr*)&client,&len);
if(new_sockfd!=-1)
{
pid=fork();
if(pid==0)
{
printf("\n child process executing \n");
printf("\n child process is is %d", getpid());
len=sizeof(server);
rval=recv(new_sockfd, buff1,sizeof(buff1),0);
if(rval==-1)
{
perror("\n RECV_ERR\n");
exit(1);
}
else
{
printf("\n received message is %s\n", buff1);
}
rval=send(new_sockfd,buff1,sizeof(buff1),0);
if(rval!=-1)
{
printf("\n message sent successfully \n");
}
else
{
perror("\nSEND_ERR\n");
exit(1);
}
}
else
{
printf("\n parent process\n");
printf("parent process id is %d \n", getppid());
exit(1);
}
}
else
{
perror("\n ACCEPT_ERR\n");
exit(1);
}
}
}
else
{
perror("\nBIND_ERR\n");
close(sockfd);
}
}
