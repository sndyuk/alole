#include "input.h"

struct _Input {
	int* keySequence;
} _Input { new int[3] };

int Input::getKey() {
	for (int i = 0; i < 3; i++) {
		_Input.keySequence[i] = 0;
		read(0, &_Input.keySequence[i], 1);
	}
	switch (_Input.keySequence[0]) {
	case CONTROL_C:
		return KEY_CONTROL_C;
		break;
	default:
		break;
	}
	if (_Input.keySequence[0] == 0x1B
			&& _Input.keySequence[1] == 0x5B) {
		switch (_Input.keySequence[2]) {
		case LEFT:
			return KEY_LEFT;
		case UP:
			return KEY_UP;
		case RIGHT:
			return KEY_RIGHT;
		case DOWN:
			return KEY_DOWN;
			break;
		}
	}
	return KEY_NONE;
}
