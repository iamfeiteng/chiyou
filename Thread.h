#ifndef _H_THREAD_
#define _H_THREAD_

#include <boost/noncopyable.hpp>
#include <boost/function.hpp>
#include <cstring>

namespace chiyou{
	typedef boost::function<void()> ThreadFunc;

	struct ThreadData {
		ThreadData(const ThreadFunc& func,
				   const std::string& name,
				   pid_t* tid);
		void Run();
		ThreadFunc func_;
		std::string name_;
		pid_t* tid_;
	};


	class Thread : boost::noncopyable{
		public:
			Thread(const ThreadFunc&, const std::string& name);
			~Thread();
			void Start();
			int Join();
		private:
			pthread_t pthread_id_;
			ThreadFunc func_;
			std::string name_;
			pid_t* tid_;
	};
}

#endif 
