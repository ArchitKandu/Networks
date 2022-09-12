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
    char s[100];
    char *y="PALINDROME";
    char *n="NOT PALINDROME";
    int flag,left,right;
    struct sockaddr_in sa,ca;

    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    sa.sin_family=AF_INET;
    sa.sin_addr.s_addr=inet_addr("127.0.0.1");
    sa.sin_port=htons(6028);

    i=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
    printf("test %d%d\n",sockfd,i);
    length=sizeof(sa);
    
    recvfrom(sockfd,s,sizeof(s),0,(struct sockaddr *)&ca,&length);
    printf("Received: %s\n",s);
    if(strlen(s)==0) flag=0;
    else{
        left=0;
        right=strlen(s)-1;
        flag=1;
        while(left<right && flag){
			if (s[left]!=s[right])
				flag=0;
			else{
				left++;
				right--;
			}
		}
    }
    if(flag==0){
        printf("Result is: %s\n",n);
        sendto(sockfd,n,strlen(n),0,(struct sockaddr *)&ca,sizeof(ca));
    }
    else {
        printf("Result is: %s\n",y);
        sendto(sockfd,y,strlen(y),0,(struct sockaddr *)&ca,sizeof(ca));
    }
    close(sockfd);
}
