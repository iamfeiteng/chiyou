#include <errno.h>

#include "SocketOps.h"

int createNonblockingSocket(sa_family_t family){
	// why SOCK_CLOEXEC here
	int sockfd = ::socket(family, SOCK_STREAM | SOCK_NONBLOCK, IPPROTO_TCP);
	if (sockfd < 0){
		//
	}
	return sockfd;
}

void bind(int fd, const struct sockaddr* addr){
	int ret = ::bind(fd, addr, sizeof(struct sockaddr));
	if (ret < 0){
	}
}

void listen(int fd){
	int ret = ::listen(fd, SOMAXCONN);
	if (ret < 0){
	}
}

int connect(int fd, const struct sockaddr* addr){
	int ret = ::connect(fd, addr, sizeof(struct sockaddr));
	if (ret < 0){
	}
	return ret;
}

int close(int fd){
	int ret = ::close(fd);
	if (ret < 0){
	}
}

void shutdownWrite(int fd){
	int ret = ::shutdown(fd, SHUT_WR);
	if (ret < 0){
	}
}

int accept(int fd, struct sockaddr* addr){
	socklen_t addr_len = sizeof(*addr);
	int connfd = ::accept4(fd, addr, &addr_len, SOCK_NONBLOCK | SOCK_CLOEXEC);
	if (connfd < 0){
	}
	return connfd;
}

ssize_t read(int fd, void *buf, size_t count){
	return ::read(fd, buf, count);
}

ssize_t write(int fd, const void *buf, size_t count){
	return ::write(fd, buf, count);
}
