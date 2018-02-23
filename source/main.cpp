#include <iostream>
#include "../include/sendMgr.h"
#include "../include/handleTrd.h"

using namespace std;

extern CSendMgr gSendMgr;
int main() {
	cout << "C Multi Thread Demo" << endl;

	CHandleTrd handle;
	handle.handle_start();
	gSendMgr.begin_pool(3);

	while(true) {
		printf("master process waiting...\n");
		sleep(10);
	}

	gSendMgr.end_pool();
	return 0;
}