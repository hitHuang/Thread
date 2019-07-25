/************************************************************************
    > File Name: test.cpp
    > Author: huang
    > Mail: 13100937921@163.com 
    > Created Time: 2019年07月18日 星期四 19时55分42秒
************************************************************************/
#include <iostream>
#include <pthread.h>
#include "CountDownLatch.h"
#include <stdio.h>
#include <unistd.h>

CountDownLatch cdl(3);

void* func1(void* arg) {
	printf("this is thread 1\n");
	sleep(2);
	cdl.countdown();
	printf("thread 1 over\n");
}

void* func2(void* arg) {
	printf("this is thread 2\n");
	sleep(3);
	cdl.countdown();
	printf("thread 2 over\n");
}

void* func3(void* arg) {
	printf("this is thread 3\n");
	sleep(5);
	cdl.countdown();
	printf("thread 3 over\n");
}

int main() {
	pthread_t t1,t2,t3;
	pthread_create(&t1, NULL, func1, NULL);
	pthread_create(&t2, NULL, func2, NULL);
	pthread_create(&t3, NULL, func3, NULL);
	cdl.wait();
	return 0;
}
