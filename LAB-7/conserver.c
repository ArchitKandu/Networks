#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main()
{
    int sockfd,fd1,length,i;
    char s1[200],s2[100];
    struct sockaddr_in sa,ca;

    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    sa.sin_family=AF_INET;
    sa.sin_addr.s_addr=inet_addr("127.0.0.1");
    sa.sin_port=htons(6028);

    i=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
    printf("test %d %d\n",sockfd,i);
    length=sizeof(sa);
    
    recvfrom(sockfd,s1,sizeof(s1),0,(struct sockaddr *)&ca,&length);
    recvfrom(sockfd,s2,sizeof(s2),0,(struct sockaddr *)&ca,&length);
    
    printf("Received: %s %s\n",s1,s2);
    strcat(s1,s2);
    printf("Result is: %s\n",s1);
    sendto(sockfd,s1,sizeof(s1),0,(struct sockaddr *)&ca,sizeof(ca));
    close(sockfd);
}
