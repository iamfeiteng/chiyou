#ifndef _H_COUNTDOWN_LATCH_
#define _H_COUNTDOWN_LATCH_

#include <boost/noncopyable.hpp>
#include "Mutex.h"
#include "Condition.h"

namespace chiyou{
	class CountDownLatch : boost::noncopyable{
		public:
			CountDownLatch(int count);
			void CountDown();
			int get_count() const;
			void Wait();
		private:
			mutable MutexLock mutex_;
			Condition condition_;
			int count_;
	};
};

#endif
