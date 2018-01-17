#include "TCPServer.h" 

string TCPServer::Message;

/**
 *
 * @param arg
 * @return int
 */
void* TCPServer::Task(void *arg)
{
	int n;
	int newsockfd = (long)arg;
	char msg[MAXPACKETSIZE];
	pthread_detach(pthread_self());
	while(1)
	{
		n=recv(newsockfd,msg,MAXPACKETSIZE,0);
		if(n==0)
		{
		   close(newsockfd);
		   break;
		}
		msg[n]=0;
		//send(newsockfd,msg,n,0);
		Message = string(msg);
	}
	return 0;
}

/**
 * Configures the TCP server
 * @param port
 */
void TCPServer::setup(int port)
{
	sockfd=socket(AF_INET,SOCK_STREAM,0);
 	memset(&serverAddress,0,sizeof(serverAddress));
	serverAddress.sin_family=AF_INET;
	serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
	serverAddress.sin_port=htons(port);
	bind(sockfd,(struct sockaddr *)&serverAddress, sizeof(serverAddress));
 	listen(sockfd,5);
}

/**
 * Receives messages from client
 * @return
 */
string TCPServer::receive()
{
	string str;
	while(1)
	{
		socklen_t sosize  = sizeof(clientAddress);
		newsockfd = accept(sockfd,(struct sockaddr*)&clientAddress,&sosize);
		str = inet_ntoa(clientAddress.sin_addr);
		pthread_create(&serverThread,NULL,&Task,(void *)newsockfd);
	}
	return str;
}

/**
 * Accessor
 * @return
 */
string TCPServer::getMessage()
{
	return Message;
}

/**
 * send socket
 * @param msg
 */
void TCPServer::Send(string msg)
{
	send(newsockfd,msg.c_str(),msg.length(),0);
}

/**
 * clean socket
 */
void TCPServer::clean()
{
	Message = "";
	memset(msg, 0, MAXPACKETSIZE);
}

/**
 * close the connection
 */
void TCPServer::detach()
{
	close(sockfd);
	close(newsockfd);
} 
