#include "Socket.h"
#include "SocketOps.h"

using namespace chiyou::net;

Socket::~Socket(){
	chiyou::net::close(fd_);
}

void Socket::bindAddress(struct sockaddr* addr){
	chiyou::net::bind(fd_, addr);
}

void Socket::listen(){
	chiyou::net::listen(fd_);
}

void Socket::shutdownWrite(){
	chiyou::net::shutdownWrite(fd_);
}

int Socket::accept(struct sockaddr* addr){
	int connfd = chiyou::net::accept(fd_, addr);
	return connfd;
}
