#ifndef _H_CHIYOU_EVENTLOOP_
#define _H_CHIYOU_EVENTLOOP_

#include <vector>
#include <boost/any.hpp>
#include <boost/noncopyable.hpp>

namespace chiyou
{
    namespace net 
	{
		class EventLoop : boost::noncopyable
		{
		public:
			EventLoop();
			~EventLoop();
			void Run();
	    };
    }
}

#endif
