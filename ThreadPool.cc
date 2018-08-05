#include <boost/bind.hpp>
#include "ThreadPool.h"
#include "Thread.h"
using namespace chiyou;

void ThreadPool::set_max_size(int max_size){
	max_size_ = max_size;
}

void ThreadPool::Start(int num_threads){
	threads_.reserve(num_threads);
	for (int i = 0; i < num_threads; i++){
		Thread* t = new chiyou::Thread(boost::bind(&ThreadPool::Run, this), "");
		threads_.push_back(t);
	}
}

void ThreadPool::Stop(){
	MutexLockGuard lock(mutex_);
	not_empty_.NotifyAll();
	for_each (threads_.begin(), threads_.end(), boost::bind(&Thread::Join, _1));
}

void ThreadPool::Run(const Task& task){
	MutexLockGuard lock(mutex_);
	while (IsFull()){
		not_full_.Wait();
	}
	queue_.push_back(task);
	not_empty_.Notify();
}

void ThreadPool::Run(){
	try{
		while (1){
			Task task = ThreadPool::Take();
			if (!task.empty()){
			}
		}
	}catch(...){
		throw;
	}
}

ThreadPool::Task ThreadPool::Take(){
	MutexLockGuard lock(mutex_);
	while (queue_.empty()){
		not_empty_.Wait();
	}
	Task task;
	if (!queue_.empty()){
		task = queue_.front();
		queue_.pop_front();	
		not_full_.Notify();
	}
	return task;
}

bool ThreadPool::IsFull() const {
	return max_size_ <= queue_.size();
}
