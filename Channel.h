#ifndef _H_CHIYOU_CHANNEL_
#define _H_CHIYOU_CHANNEL_

#include <boost/noncopyable.hpp>
#include <boost/function.hpp>

namespace chiyou{
	namespace net{
		class Channel : boost::noncopyable{
			public:
				typedef boost::function<void()> EventCallbak;

			private:

		};
	}
}

#endif
