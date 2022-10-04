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
    int i,sockfd,length;
    struct sockaddr_in sa;
    char s1[200],s2[100];

    sockfd=socket(AF_INET,SOCK_DGRAM,0);

    sa.sin_family=AF_INET;
    sa.sin_addr.s_addr=inet_addr("127.0.0.1");
    sa.sin_port=htons(6028);
    printf("Enter two string: ");
    scanf("%s %s",s1,s2);

    sendto(sockfd,s1,sizeof(s1),0,(struct sockaddr *)&sa,sizeof(sa));
    sendto(sockfd,s2,sizeof(s2),0,(struct sockaddr *)&sa,sizeof(sa));

    length=sizeof(sa);
    recvfrom(sockfd,s1,sizeof(s1),0,(struct sockaddr *)&sa, &length);
    printf("Result is: %s\n",s1);
    close(sockfd);
}
