//Server
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
	int sockfd,i,fd[2],length;
	struct sockaddr_in sa,ca[2];
    char buf1[100],buf2[100];

    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family=AF_INET;
    sa.sin_addr.s_addr=inet_addr("127.0.0.1");
    sa.sin_port=htons(6045);

    i=bind(sockfd, (SA*)&sa, sizeof(sa));
    printf("Test: %d %d\n",sockfd,i);

	listen(sockfd, 5);

    length=sizeof(sa);

    for(int j=0;j<2;j++)
        fd[j]=accept(sockfd,(SA *)&ca[i],&length);
    for(int j=0;j<2;j++){
        int k=recv(fd[j],buf1,100,0);
        buf1[k]='\0';
        printf("%s\n",buf1);
        printf("Enter message: ");
        scanf("%s",buf2);
        send(fd[j],buf2,strlen(buf2),0);
    }
    close(sockfd);
	for(int j=0;j<2;j++)
        close(fd[j]);
}
