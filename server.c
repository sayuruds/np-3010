
/* 
	Dissanayake D.M.D.S.N
	IT19202532

*/

#include "utils.h"
#include <ctype.h>


int main(int argc, char **argv)
{
	int			listenfd, connfd,a,b;
	socklen_t		len;
	struct sockaddr_in	servaddr, cliaddr;
	char			buff[MAXLINE];
	time_t			tm;
	int yes = 1;
	const char	*ptr;
	pid_t			childpid;
	char buffer[512];

	if ( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
	{
		fprintf(stderr, "failure of socket creation\n");
		exit (1);
	}
	
	    memset(&servaddr, '0', sizeof(servaddr));
    	    memset(buffer, '0', sizeof(buffer));


	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(SERV_TCP_PORT); 

	if ( (bind(listenfd, (SA *) &servaddr, sizeof(servaddr))) < 0) 
	{
		fprintf(stderr, "bind failed\n");
		exit (1);
	}
		

	if ( listen(listenfd, LISTENQ) < 0) 
	{
		fprintf(stderr, "listen failed\n");
		exit (1);
	}

	for ( ; ; ) 
	{
		len = sizeof(cliaddr);
		if ( (connfd = accept(listenfd, (SA *) &cliaddr, &len)) < 0 ) 
		{
			fprintf(stderr, "accept failed\n");
			exit (1);
		}

		
	
		if ((childpid =fork())==0){
		
		if( (ptr = inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff))) == NULL) 
		{
			fprintf(stderr, "inet_ntop error\n");
			exit (1);
		}
		
		printf("Connection from %s, port %d\n", ptr, ntohs(cliaddr.sin_port));
		tm = time(NULL);
		FILE * log;
		log = fopen("logs.txt","a");
 		fprintf(log,"Connection from %s, port %d ", ptr, ntohs(cliaddr.sin_port));
 		fprintf(log,"->->->-> %.24s\r\n", ctime(&tm));
		 
				
		
		
         FILE *fl;
         int ch = 0;
         fl = fopen("send.txt","a");            
         int cont;
		
          while((a=recv(connfd, buffer, 1024,0))>0)
       	   {
        	 
		 b + a = b;
                fwrite(buffer, 1, a, fl);

	   }
     	printf("File received successfully\n");
	   
	   
	close(listenfd);
		exit(0);	
	}
		}
		
		close(connfd);
	
}

