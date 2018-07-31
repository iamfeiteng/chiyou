#include "CountDownLatch.h"

using namespace chiyou;
CountDownLatch::CountDownLatch(int count)
	: count_(count), mutex_(), condition_(mutex_) {
}

int CountDownLatch::get_count() const{
	MutexLockGuard lock(mutex_);
	return count_;
}

void CountDownLatch::CountDown(){
	MutexLockGuard lock(mutex_);
	count_--;
	if (count_ == 0){
		condition_.NotifyAll();
	}
}

void CountDownLatch::Wait(){
	MutexLockGuard lock(mutex_);
	while (count_ > 0){
		condition_.Wait();
	}
}
