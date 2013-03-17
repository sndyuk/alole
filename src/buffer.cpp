#include "buffer.h"

class Buffer::Impl {
public:
	const int width;
	const int height;
	string **buffer;

	Impl(int width, int height) :
			width(width), height(height), buffer(new string*[height]) {
		for (int y = 0; y < height; y++) {
			this->buffer[y] = new string[width];
		}
	}

	~Impl() {
		for (int y = 0; y < height; y++) {
			delete[] this->buffer[y];
		}
		delete[] this->buffer;
	}
};
Buffer::Buffer(int width, int height) :
		impl(new Buffer::Impl(width, height)) {
}

Buffer::~Buffer(void) {
}

void Buffer::fill(const string& str) {
	for (int y = 0; y < impl->height; y++) {
		for (int x = 0; x < impl->width; x++) {
			impl->buffer[y][x] = str;
		}
	}
}

const string Buffer::get(int x, int y) {
	if (x >= 0 && x < impl->width && y >= 0 && y < impl->height) {
		return impl->buffer[y][x];
	}
	return "";
}

const int Buffer::put(int x, int y, const string& content) {
	if (x >= 0 && x < impl->width && y >= 0 && y < impl->height) {
		impl->buffer[y][x] = content;
		return 1;
	}
	return 0;
}

void Buffer::foreach(std::function<void(int, int, string&)> fx, std::function<void(int)> fy) {
	for (int y = 0; y < impl->height; y++) {
		for (int x = 0; x < impl->width; x++) {
			fx(x, y, impl->buffer[x][y]);
		}
		fy(y);
	}
}
