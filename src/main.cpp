#include <signal.h>
#include "alole.h"

const char aloleUsageStr[] = "usage: alole [--version] [--help]";

static void handleOptions(int &argc, char** argv) {
	if (argc == 2) {
		if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
			cout << "TODO" << endl;
			exit(0);
		} else if (strcmp(argv[1], "-v") == 0
				|| strcmp(argv[1], "--version") == 0) {
			cout << "alole version 1.0" << endl;
			exit(0);
		} else {
			cout << aloleUsageStr << endl;
			exit(0);
		}
	} else if (argc > 2) {
		cout << aloleUsageStr << endl;
		exit(0);
	}
}

void exitSignalHandler(int s) {
	exit(0);
}

void setSignalHanlder(int signame, void (*handler)(int)) {
	if (signal(signame, handler) == SIG_ERR ) {
		exit(0);
	}
}

int main(int argc, char** argv) {
	setSignalHanlder(SIGINT, &exitSignalHandler);

	handleOptions(argc, argv);

	Alole* alole = new Alole();
	alole->run();

	delete alole;

	return 0;
}
