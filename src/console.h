#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <termios.h>
#include "buffer.h"
#include "data.h"

class Console {
public:
	Console(int width, int height);
	~Console(void);

	void ereaseUp();
	void ereaseScreen();
	void hideCursor();
	void showCursor();

	void draw(const Data*);
	void erase(const Data*);
	void fill(const string& fillChar);
	void flash(void);

	void msleep(unsigned int milliseconds);

private:
	class Impl;
	Impl* impl;
};

#endif
