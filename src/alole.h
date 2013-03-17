#ifndef ALOLE_H
#define ALOLE_H

#include "input.h"
#include "console.h"
#include "data.h"

class Alole {

public:
	Alole(void);
	~Alole(void);

	void run(void);
	void quit(int);

private:
	class Impl;
	Impl* impl;
};

#endif
