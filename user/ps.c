#include "ProcessInfo.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"


int main(void)
{
	enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
	 static char *states[] = {
  		[UNUSED]    "UNUSED  ",
  		[EMBRYO]    "EMBRYO  ",
  		[SLEEPING]  "SLEEPING",
  		[RUNNABLE]  "RUNNABLE",
  		[RUNNING]   "RUNNING ",
  		[ZOMBIE]    "ZOMBIE  "
  		};
  	
	struct ProcessInfo processInfoTable[NPROC];
	int numbers = getprocs(processInfoTable);
	int lineNumber;
	for (int i = 0; i < numbers; i++)
	{
		lineNumber = i + 1;
		printf(1, "%d %d ",lineNumber ,processInfoTable[i].ppid);

		printf(1, "%s",states[processInfoTable[i].state]);
		printf(1, " %d %s", processInfoTable[i].sz,processInfoTable[i].name);
		printf(1, "\n");
	}
	exit();
}
