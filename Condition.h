#ifndef _H_CONDITION_
#define _H_CONDITION_

#include <pthread.h>
#include <boost/noncopyable.hpp>

namespace chiyou{
	class MutexLock;
	class Condition : boost::noncopyable{
		public:
			Condition(MutexLock& mutex);
			~Condition();
			void Wait();
			void Notify();
			void NotifyAll();
		private:
			MutexLock& mutex_;
			pthread_cond_t pcond_;
	};
};

#endif
