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
int main()
{
    int i,sockfd,length,count;
    int res,n,sum,arr[MAX];
    struct sockaddr_in sa;

    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    sa.sin_family=AF_INET;
    sa.sin_addr.s_addr=inet_addr("127.0.0.1");
    sa.sin_port=htons(6028);

    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    sendto(sockfd,&n,sizeof(int),0,(SA*)&sa,sizeof(sa));
    sendto(sockfd,arr,sizeof(arr),0,(SA*)&sa,sizeof(sa));
    
    length=sizeof(sa);
    count=0;
    while(1){
        recvfrom(sockfd,&res,sizeof(int),0,(struct sockaddr *)&sa, &length);
        count++;
        if(count==1)
            printf("Sum is: %d\n",res);
        else
            printf("%d Sum of digits is: %d",count,res);
        sum=0;
        while(res!=0){
            sum=sum+res%10;
            res=res/10;
        }
        printf("Sum of digits is: %d",sum);
        if(sum>=10) sendto(sockfd,&sum,sizeof(int),0,(SA*)&sa,sizeof(sa));
    }
    close(sockfd);
}
