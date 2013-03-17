#include "console.h"

class Console::Impl {
	struct termios orgTermAttr, termAttr;
public:
	Buffer* buffer;

	Impl(int width, int height) {
		buffer = new Buffer(width, height);
		tcgetattr(fileno(stdin), &orgTermAttr);
		// Raw mode
		termAttr = orgTermAttr;
		termAttr.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
		termAttr.c_cc[VTIME] = 0;
		termAttr.c_cc[VMIN] = 0;
		tcsetattr(fileno(stdin), TCSANOW, &termAttr);
	}

	~Impl(void) {
		delete buffer;
		tcsetattr(fileno(stdin), TCSANOW, &orgTermAttr);
	}
};

Console::Console(int width, int height) :
		impl(new Console::Impl(width, height)) {
}
Console::~Console(void) {
	delete impl;
}
void Console::ereaseScreen() {
	// Erases the screen with the background color and moves the cursor to home.
	cout << "\033[H\033[2J";
}
void Console::ereaseUp() {
	// Erases the screen from the curr line up to the top of the screen.
	cout << "\033[H\033[1J";
}

void Console::hideCursor() {
	cout << "\033[?25l";
}
void Console::showCursor() {
	cout << "\033[?25h";
}

void Console::msleep(unsigned int milliseconds) {
	struct timespec req = { 0 };
	req.tv_sec = 0;
	req.tv_nsec = milliseconds * 1000000L;
	int cnt = 0;
	while (nanosleep(&req, &req) == -1) {
		if (++cnt > 10) {
			perror("sleep error");
			exit(0);
		}
		continue;
	}
}

void Console::draw(const Data* data) {
	impl->buffer->put(data->x, data->y, data->content);
}

void Console::fill(const string& fillChar) {
	impl->buffer->fill(fillChar);
}

void Console::flash() {
	impl->buffer->foreach([](int x, int y, string& str) -> void {
		cout << str;
	}, [](int x) -> void {
		cout << endl;
	});
}
