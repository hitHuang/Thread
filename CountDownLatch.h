/************************************************************************
    > File Name: CountDownLatch.h
    > Author: huang
    > Mail: 13100937921@163.com 
    > Created Time: 2019年07月18日 星期四 20时29分50秒
************************************************************************/
#ifndef COUNTDOWNLATCH_H
#define COUNTDOWNLATCH_H

#include "noncopyable.h"
#include "MutexLock.h"
#include "Condition.h"

class CountDownLatch : noncopyable {
public:
	CountDownLatch(int count) : mutex_(), condition_(mutex_), count_(count) {
		
	}
	void wait() {
		MutexLockGuard lock(mutex_);
		while (count_ > 0) {
			condition_.wait();
		}
	}
	void countdown() {
		MutexLockGuard lock(mutex_);
		--count_;
		if (count_ == 0) {
			condition_.notifyAll();
		}
	}

private:
	mutable MutexLock mutex_;
	Condition condition_;
	int count_;
};

#endif
