//Client
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#define SA struct sockaddr
int main(){
	int sockfd,i;
	struct sockaddr_in sa;
    char buf1[100],buf2[100];

    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family=AF_INET;
    sa.sin_addr.s_addr=inet_addr("127.0.0.1");
    sa.sin_port=htons(6045);

    i=connect(sockfd,(SA*)&sa,sizeof(sa));

    printf("Enter message: ");
    scanf("%s",buf1);
    send(sockfd,buf1,strlen(buf1),0);

    int k=recv(sockfd,buf2,100,0);
    buf2[k]='\0';
    printf("%s\n",buf2);
    
	close(sockfd);
}
