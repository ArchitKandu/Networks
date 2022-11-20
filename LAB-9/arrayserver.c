//WAP in C using UDP where the client sends an array of n integers to the server and
//sever calculates sum of all the elements and sends the sum value to the client.
//Now client calculates sum of all digits of all value and checks whether it is single digits or not. 
//If not them it sends the sum value to the server 
//and server calculates sum of all digits and checks whether it is single digit or not.
//If not, server sends digit to client. This process will continue until sum is single digit.
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#define MAX 100
#define SA struct sockaddr
void func(int sockfd){
    int arr[MAX];
    int clen,n,res;
    struct sockaddr_in cli;
    clen=sizeof(cli);
    recvfrom(sockfd,&n,sizeof(int),0,(SA *)&cli,&clen);
    recvfrom(sockfd,arr,sizeof(arr),0,(SA *)&cli,&clen);
    printf("\nFrom client Array is: ");
    res=0;
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
        res=res+arr[i];
    }
    printf("\nSum is: %d\n",res);
    sendto(sockfd,&res,sizeof(int),0,(SA *)&cli,clen);
}
int main(){
    int sockfd,i;
    struct sockaddr_in servaddr;
    
    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    servaddr.sin_port=htons(6028);

    i=bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    printf("Test: %d %d",sockfd,i);
    func(sockfd);
    close(sockfd);
}
