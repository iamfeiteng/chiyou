#ifndef _H_CHIYOU_CHANNEL_
#define _H_CHIYOU_CHANNEL_

#include <boost/noncopyable.hpp>
#include <boost/function.hpp>

namespace chiyou{
	namespace net{
		class Channel : boost::noncopyable{
			public:
				typedef boost::function<void()> EventCallback;
				void SetReadCallback(const EventCallback& cb){
					readCallback_ = cb;
				}
				void SetWriteCallback(const EventCallback& cb){
					writeCallback_ = cb;
				}
				void SetCloseCallback(const EventCallback& cb){
					closeCallback_ = cb;
				}


			private:
				EventCallback readCallback_;
				EventCallback writeCallback_;
				EventCallback closeCallback_;
		};
	}
}

#endif
