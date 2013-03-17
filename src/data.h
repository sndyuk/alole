#ifndef DATA_H
#define DATA_H

#include <string>
using namespace std;

class Data {

public:
	char x, y;
	string content;

	Data(int, int, const string& content);
	~Data(void);
};

#endif
