/*
	Dissanayake D.M.D.S.N
	IT19202532
*/

#include "utils.h"
#include<ctype.h>


int main(int argc, char **argv)
{
	int	sockfd, n,conn;
	char	recvline[MAXLINE + 1];
	struct sockaddr_in	servaddr;
	char rbuff[1024];
    char sendbuffer[100];
    
    memset(rbuff, '0', sizeof(rbuff));


	if (argc != 2) 
	{
		printf("usage: a.out <IPaddress>");
		return 1;
	}

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("socket error");
		return 1;
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(SERV_TCP_PORT);	
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
	{
		printf("inet_pton error for %s", argv[1]);
		return 1;
	}

	if (conn=connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0) 
	{
		printf("connect error");
		return 1; 
	}

	
	FILE *fl;
    
 	char name[20];  
  	printf("Enter file name to transfer : "); 
 	scanf("%s",&name);  
  	

     	fl=fopen(name,"r");
  
   
	while( (conn= fread(sendbuffer, 1, sizeof(sendbuffer), f))>0 ){
        send(sockfd, sendbuffer, conn, 0);
    	}
	printf("File sent successfully\n\n");
    	fclose(f);
    
    
      	
    return 0;


}
