#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/select.h>
#include<string.h>
#include<arpa/inet.h>
int main()
{
        int i,j,maxfd,maxi,sockfd,listenfd,connfd;
        int nread,client[FD_SETSIZE];
        ssize_t n;
        fd_set rset,allset;
        char buff[512];
        socklen_t clilen;
        struct sockaddr_in servaddr,cliaddr;
        listenfd=socket(AF_INET,SOCK_STREAM,0);
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=INADDR_ANY;
        servaddr.sin_port=htons(7524);
        bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
        listen(listenfd,5);
        maxfd=listenfd;
        maxi=-1;
        for(i=0;i<FD_SETSIZE;i++)
                client[i]=-1;
        FD_ZERO(&allset);
        FD_SET(listenfd,&allset);
        for(;;)
        {
                rset=allset;
                nread=select(maxfd+1,&rset,NULL,NULL,NULL);
                if(FD_ISSET(listenfd,&rset))
                {
                        clilen=sizeof(cliaddr);
                        connfd=accept(listenfd,(struct sockaddr *)&cliaddr,&clilen);
                        for(i=0;i<FD_SETSIZE;i++)
                                if(client[i]<0)
                                {
                                        client[i]=connfd;
                                        break;
                                }
                        if(i==FD_SETSIZE)
                        {
                                printf("\nToo many clients!!\n");
                                exit(1);
                        }
                        FD_SET(connfd,&allset);
                        if(connfd>maxfd)
                                maxfd=connfd;
                        if(i>maxi)
                                maxi=i;
                        if(--nread<=0)
                                continue;
                }
                for(i=0;i<=maxi;i++)
           {
                        if((sockfd=client[i])<0)
                                continue;
                        if(FD_ISSET(sockfd,&rset))
                        {
                                if((n=read(sockfd,buff,512))==0)
                                {
                                        close(sockfd);
                                        FD_CLR(sockfd,&allset);
                                        client[i]=-1;
                                }
                                else
                                {
                                        printf("\nData received from client:%s\n",buff);
                                        for(j=0;buff[j]!='\0';j++)
                                        {
                                                printf("%c",buff[j]);
                                                buff[j]=toupper(buff[j]);
                                        }
                                        printf("\n");
                                        write(sockfd,buff,512);
                                }
                                if(--nread<=0)
                                        break;
                        }
                }
        }
        return 0;
}