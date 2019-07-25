/************************************************************************
    > File Name: MutexLock.h
    > Author: huang
    > Mail: 13100937921@163.com 
    > Created Time: 2019年07月18日 星期四 20时03分45秒
************************************************************************/
#ifndef MutexLock_H
#define MutexLock_H

#include "noncopyable.h"
#include <pthread.h>
class MutexLock : noncopyable {
public:
	MutexLock(){
		pthread_mutex_init(&mutex_, NULL);
	}
	~MutexLock(){
		pthread_mutex_destroy(&mutex_);
	}
	void lock() {
		pthread_mutex_lock(&mutex_);
	}
	void unlock() {
		pthread_mutex_unlock(&mutex_);
	}
	pthread_mutex_t* getPthreadMutex() {
		return &mutex_;
	}
private:
	pthread_mutex_t mutex_;
};

class MutexLockGuard : noncopyable {
public:
	explicit MutexLockGuard(MutexLock& mutex) : mutex_(mutex) {
		mutex_.lock();
	}
	~MutexLockGuard() {
		mutex_.unlock();
	}
private:
	MutexLock& mutex_;
};

#define MutexLockGuard(x) static_assert(false, "missing mutex guard var name")

#endif
