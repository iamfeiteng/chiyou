#ifndef _H_THREAD_POOL_
#define _H_THREAD_POOL_

#include <deque>

#include <boost/noncopyable.hpp>
#include <boost/function.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include "Condition.h"
#include "Mutex.h"

namespace chiyou{
	class Thread;
	class ThreadPool : boost::noncopyable {
		public:
			typedef boost::function<void()> Task;
			void Start(int num_threads);
			void Stop();
			void Run(const Task& task);
			Task Take();
			void set_max_size(int max_size);
		private:
			bool IsFull() const;
			void Run();

			boost::ptr_vector<chiyou::Thread> threads_;
			std::deque<Task> queue_;
			Condition not_empty_;
			Condition not_full_;
			MutexLock mutex_;
			int max_size_;
	};
};

#endif 
