#include <stdio.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/uio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define	MAXLINE	4096
#define	LISTENQ	10
#define	SERV_TCP_PORT	6666  
#define	SA	struct sockaddr
