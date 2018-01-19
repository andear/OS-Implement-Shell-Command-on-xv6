#ifndef _PROCESSINFO_H_
#define _PROCESSINFO_H_
#include "types.h"

struct ProcessInfo{
	int pid;
	int ppid;
	int state;
	uint sz;
	char name[16];
};
#endif
