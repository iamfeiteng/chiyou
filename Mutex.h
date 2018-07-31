#ifndef _H_MUTEX_
#define _H_MUTEX_

#include <pthread.h>
#include <boost/noncopyable.hpp>

namespace chiyou{
	class MutexLock : boost::noncopyable {
		public:
			MutexLock();
			~MutexLock();
			void Lock();
			void Unlock();
			pthread_mutex_t* get_mutex(){return &mutex_;};
		private:
			pthread_mutex_t mutex_;
	};
	
	class MutexLockGuard : boost::noncopyable {
		public:
			MutexLockGuard(MutexLock& mutex);
			~MutexLockGuard();
		private:
			MutexLock& mutex_;
	};
}

#endif
