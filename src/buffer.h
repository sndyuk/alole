#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <string>
#include <functional>

using namespace std;

class Buffer {
public:
	Buffer(int width, int height);
	~Buffer(void);

	void fill(const string&);
	const string get(int, int);
	const int put(int, int, const string&);
	void foreach(function<void(int, int, string&)>, function<void(int)>);

private:
	class Impl;
	Impl* impl;
};

#endif
