#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#define ERROR -1
main()
{
int s,k;
struct sockaddr_in server, addr;
socklen_t len;
s=socket(AF_INET,SOCK_STREAM,0);
server.sin_family=AF_INET;
server.sin_addr.s_addr=INADDR_ANY;
server.sin_port=htons(8282);
k=connect(s,(struct sockaddr *)&server, sizeof(server));
if(k<0)
{
perror("connection error");
exit(0);
}
len = sizeof(addr);
getpeername(s, (struct sockaddr*)&addr, &len);
printf("Peer IP address: %s\n", inet_ntoa(addr.sin_addr));
printf("Peer port : %d\n", ntohs(addr.sin_port));
}
