#include "alole.h"

class Alole::Impl {

public:
	const int width = 36;
	const int height = 36;
	Console* console;
	int currKey;
	bool bufferDirty;

	Data* cursor;
	Data* key;

	Impl(void) {
		currKey = 0;
		bufferDirty = false;

		console = new Console(width, height);
		console->ereaseUp();
		console->hideCursor();

		cursor = new Data(0, 0, "|");
		key = new Data(3, 3, "k");
	}

	~Impl(void) {
		delete console;
	}

	void update(void) {
		switch (currKey) {
		case Input::KEY_LEFT:
			if (cursor->x > 0) {
				--cursor->x;
				console->draw(cursor);
				bufferDirty = true;
			}
			break;
		case Input::KEY_UP:
			if (cursor->y > 0) {
				--cursor->y;
				console->draw(cursor);
				bufferDirty = true;
			}
			break;
		case Input::KEY_RIGHT:
			if (cursor->x < width) {
				++cursor->x;
				console->draw(cursor);
				bufferDirty = true;
			}
			break;
		case Input::KEY_DOWN:
			if (cursor->y < height) {
				++cursor->y;
				console->draw(cursor);
				bufferDirty = true;
			}
			break;
		case Input::KEY_CONTROL_C:
			exit(0);
			break;
		default:
			key->content = currKey;
			console->draw(key);
			bufferDirty = true;
			break;
		}
	}

	void draw(void) {
		bufferDirty = false;
		console->flash();
		console->ereaseScreen();
	}
};

Alole::Alole(void) :
		impl(new Alole::Impl()) {
	impl->console->fill("-");
	impl->bufferDirty = true;
}

Alole::~Alole(void) {
	delete impl;
}

void Alole::run(void) {

	while (1) {

		impl->currKey = Input::getKey();
		if (impl->currKey == Input::KEY_CONTROL_C) {
			quit(0);
		}

		impl->update();
		if (impl->bufferDirty) {
			impl->draw();
		}
		impl->console->msleep(50);
	}
}

void Alole::quit(int exitStatus = 0) {
	delete this;
	exit(exitStatus);
}

