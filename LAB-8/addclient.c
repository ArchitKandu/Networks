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
    int a,sum;

    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family=AF_INET;
    sa.sin_addr.s_addr=inet_addr("127.0.0.1");
    sa.sin_port=htons(6045);

    i=connect(sockfd,(SA*)&sa,sizeof(sa));

    printf("Enter number: ");
    scanf("%d",&a);
    send(sockfd,&a,sizeof(int),0);

    int k=recv(sockfd,&sum,sizeof(int),0);

    printf("Sum is: %d\n",sum);

	close(sockfd);
}
