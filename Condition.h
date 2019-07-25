/************************************************************************
    > File Name: Condition.h
    > Author: huang
    > Mail: 13100937921@163.com 
    > Created Time: 2019年07月18日 星期四 20时12分59秒
************************************************************************/
#ifndef CONDITION_H
#define CONDITION_H

#include "noncopyable.h"
#include "MutexLock.h"
#include <pthread.h>

class Condition : noncopyable {
public:
	Condition(MutexLock& mutex) : mutex_(mutex) {
		pthread_cond_init(&pcond_, NULL);
	}
	~Condition() {
		pthread_cond_destroy(&pcond_);
	}
	void wait() {
		pthread_cond_wait(&pcond_, mutex_.getPthreadMutex());
	}
	void notify() {
		pthread_cond_signal(&pcond_);
	}
	void notifyAll() {
		pthread_cond_broadcast(&pcond_);
	}
private:
	MutexLock& mutex_;
	pthread_cond_t pcond_;
};

#endif
