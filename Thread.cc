#include "Thread.h"

using namespace chiyou;
ThreadData::ThreadData(const ThreadFunc& func,
					   const std::string& name,
					   pid_t* tid)
	: func_(func), name_(name), tid_(tid){
}

void ThreadData::Run(){
	try{
		func_();
	}catch (...){
		throw;
	}
}

void* StartThread(void* obj){
	ThreadData* data = static_cast<ThreadData*>(obj);
	data->Run();
	delete data;
	return NULL;
}

Thread::Thread(const ThreadFunc& func, const std::string& name)
	:pthread_id_(0),
	func_(func),
	name_(name),
	tid_(0)
{
}

Thread::~Thread(){
	pthread_detach(pthread_id_);
}

void Thread::Start(){
	ThreadData* data = new ThreadData(func_, name_, tid_);
	if (pthread_create(&pthread_id_, NULL, &StartThread, data)){
		delete data;
	} else {
	}
}

int Thread::Join(){
	return pthread_join(pthread_id_, NULL);
}

