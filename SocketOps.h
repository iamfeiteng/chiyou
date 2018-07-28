#ifndef _H_CHIYOU_SOCKETOPS_
#define _H_CHIYOU_SOCKETOPS_

#include <arpa/inet.h>

namespace chiyou{
	namespace net{
		int createNonblockingSocket(sa_family_t family);
		void bind(int fd, const struct sockaddr* addr);
		void listen(int fd);
		int connect(int fd, const struct sockaddr* addr);
		void close(int fd);
		void shutdownWrite(int fd);
		int accept(int fd, struct sockaddr* addr);
		ssize_t read(int fd, void *buf, size_t count);
		ssize_t write(int sockfd, const void *buf, size_t count);
	}
}
#endif
