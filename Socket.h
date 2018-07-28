#ifndef _H_CHIYOU_SOCKET_
#define _H_CHIYOU_SOCKET_

#include <boost/noncopyable.hpp>

namespace chiyou{
	namespace net{
		class InetAddress;
		class Socket : boost::noncopyable {
			public:
				Socket(int fd)
					: fd_(fd) {}
				~Socket();
				
				void bindAddress(struct sockaddr* addr);
				void listen();
				void shutdownWrite();
				int accept(struct sockaddr* addr);
			private:
				int fd_;
		};
	}
}

#endif
