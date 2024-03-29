#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

int maxSocket;
int clientIds[5000];
char *clientBuff[5000];
char *msg = 0;

fd_set active, read_set, write_set;

char buff_read[1001];
char buff_send[1001];

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void    ft_error(char *str)
{
	write(2, str, strlen(str));
	write(2, "\n", 1);
	exit(1);
}

void    send_msg(int fd)
{
	for (int sockId = 3; sockId <= maxSocket; ++sockId)
	{
		if (FD_ISSET(sockId, &write_set) && sockId != fd)
		{
			send(sockId, buff_send, strlen(buff_send), 0);
			if (msg)
				send(sockId, msg, strlen(msg), 0);
		}
	}
}

int main(int ac, char **av) 
{
	if (ac != 2)
		ft_error("Wrong number of arguments");
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)
		ft_error("Fatal error");
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		ft_error("Fatal error");
	if (listen(sockfd, 10) != 0)
		ft_error("Fatal error");
	len = sizeof(cli);
	maxSocket = sockfd;
	FD_ZERO(&active);
	FD_SET(sockfd, &active);
	int clientId = 0;
	while (1)
	{
		read_set = write_set = active;
		if (select(maxSocket + 1, &read_set, &write_set, 0, 0) <= 0)
			continue;
		if (FD_ISSET(sockfd, &read_set))
		{
			connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
			if (connfd < 0)
				ft_error("Fatal error");
			clientIds[connfd] = clientId++;
			FD_SET(connfd, &active);
			maxSocket = connfd > maxSocket ? connfd : maxSocket;
			sprintf(buff_send, "server: client %d just arrived\n", clientIds[connfd]);
			send_msg(connfd);
			clientBuff[connfd] = 0;
			continue;
		}
		for (int sockId = 3; sockId <= maxSocket; ++sockId)
		{
			if (FD_ISSET(sockId, &read_set) && sockId != sockfd)
			{
				int read = recv(sockId, buff_read, 1000, 0);
				if (read <= 0)
				{
					FD_CLR(sockId, &active);
					sprintf(buff_send, "server: client %d just left\n", clientIds[sockId]);
					send_msg(sockId);
					close(sockId);
					if (clientBuff[sockId] != 0)
						free(clientBuff[sockId]);
				}
				else
				{
					buff_read[read] = 0;
					clientBuff[sockId] = str_join(clientBuff[sockId], buff_read);
					msg = 0;
					while (extract_message(&clientBuff[sockId], &msg))
					{
						sprintf(buff_send, "client %d: ", clientIds[sockId]);
						send_msg(sockId);
						free(msg);
						msg = 0;
					}
				}
			}
		}
	}
	return 0;
}