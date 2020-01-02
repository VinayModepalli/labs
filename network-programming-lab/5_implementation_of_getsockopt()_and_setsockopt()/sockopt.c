#include<stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <netinet/tcp.h>
#include <sys/types.h>
main(int argc,char *argv[])
{
int sockfd,a,b,c;
sockfd=socket(AF_INET,SOCK_STREAM,0);
int len=sizeof(a);
char s[20];
getsockopt(sockfd,IPPROTO_TCP,TCP_MAXSEG,&a,&len);
printf("PROTOCOL LEVEL>The Max Segment Size is :%d\n", a);
getsockopt(sockfd,IPPROTO_TCP,TCP_NODELAY,s,&len);
getsockopt(sockfd,IPPROTO_TCP,TCP_NODELAY,&b,&len);
printf("PROTOCOL LEVEL>The option value is:%d\n", b);
setsockopt(sockfd,SOL_SOCKET,SO_KEEPALIVE,s,len);
getsockopt(sockfd,SOL_SOCKET,SO_KEEPALIVE,&c,&len);
printf("SOCKET LEVEL>The option value is %d\n",c);
}

