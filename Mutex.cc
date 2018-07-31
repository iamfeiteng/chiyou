#include "Mutex.h"
using namespace chiyou;

MutexLock::MutexLock(){
	pthread_mutex_init(&mutex_, NULL);
}

MutexLock::~MutexLock(){
	pthread_mutex_destroy(&mutex_);
}

void MutexLock::Lock(){
	pthread_mutex_lock(&mutex_);
}

void MutexLock::Unlock(){
	pthread_mutex_unlock(&mutex_);
}

MutexLockGuard::MutexLockGuard(MutexLock& mutex)
	:mutex_(mutex){
	mutex_.Lock();
}

MutexLockGuard::~MutexLockGuard(){
	mutex_.Unlock();
}
