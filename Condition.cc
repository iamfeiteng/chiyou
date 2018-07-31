#include "Condition.h"
#include "Mutex.h"
using namespace chiyou;

Condition::Condition(MutexLock& mutex)
	:mutex_(mutex){
	pthread_cond_init(&pcond_, NULL);
}

Condition::~Condition(){
	pthread_cond_destroy(&pcond_);
}

void Condition::Wait(){
	pthread_cond_wait(&pcond_, mutex_.get_mutex());
}

void Condition::Notify(){
	pthread_cond_signal(&pcond_);
}

void Condition::NotifyAll(){
	pthread_cond_broadcast(&pcond_);
}
