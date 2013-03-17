#include <signal.h>
#include "alole.h"

const char aloleUsageStr[] = "usage: alole [--version] [--help]";

static void handleOptions(int &argc, char** argv) {
	if (argc == 2) {
		if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
			cout << "HELP! I need your help!" << endl;
			exit(0);
		} else if (strcmp(argv[1], "-v") == 0
				|| strcmp(argv[1], "--version") == 0) {
			cout << "alole version 1.0.0" << endl;
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

void signalHandler(int s) {
	exit(0);
}

void setSignal(int signame) {
	if (signal(signame, signalHandler) == SIG_ERR) {
		exit(0);
	}
}

int main(int argc, char** argv) {
	setSignal(SIGINT);

	handleOptions(argc, argv);

	Alole* alole = new Alole();
	alole->run();

	delete alole;

	return 0;
}
