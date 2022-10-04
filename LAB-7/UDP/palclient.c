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
    char s[100],res[20];

    struct sockaddr_in sa;

    sockfd=socket(AF_INET,SOCK_DGRAM,0);

    sa.sin_family=AF_INET;
    sa.sin_addr.s_addr=inet_addr("127.0.0.1");
    sa.sin_port=htons(6028);
    printf("Enter string: ");
    scanf("%s",s);

    sendto(sockfd,s,sizeof(s),0,(struct sockaddr *)&sa,sizeof(sa));

    length=strlen(s);
    recvfrom(sockfd,res,sizeof(s),0,(struct sockaddr *)&sa, &length);
    printf("Result is: %s\n",res);
    close(sockfd);
}
