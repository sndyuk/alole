#ifndef INPUT_H
#define INPUT_H


#include <unistd.h>
#include <stdio.h>

class Input {

public:
	static int getKey();
	enum keys {
		KEY_NONE, KEY_LEFT, KEY_UP, KEY_RIGHT, KEY_DOWN, KEY_CONTROL_C,
	};

private:
	enum rowInput {
		CONTROL_C = 0x03, LEFT = 0x44, UP = 0x41, RIGHT = 0x43, DOWN = 0x42,
	};
};

#endif
