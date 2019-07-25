/************************************************************************
    > File Name: noncopyable.h
    > Author: huang
    > Mail: 13100937921@163.com 
    > Created Time: 2019年07月18日 星期四 19时51分30秒
************************************************************************/
#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

struct noncopyable{
protected:
	noncopyable(){

	}
	~noncopyable(){

	}
private:
	noncopyable(const noncopyable&);
	noncopyable& operator=(const noncopyable&);
};

#endif
