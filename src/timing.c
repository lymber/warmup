#include <sys/time.h>
#include <sys/resource.h>

/* This function returns the total CPU user time consumed until now y the current */
/* process in microseconds */

/* Maybe we wish to consider system time here too: just add ru.ru_stime values*/

long int takethetime(void) {
        /* ProcessTime example */
	struct timeval time;
        /* structure for rusage */
	struct rusage ru;

	/* get the current time */
	/* - RUSAGE_SELF for current process */
	/* - RUSAGE_CHILDREN for *terminated* subprocesses */
	getrusage(RUSAGE_SELF, &ru);
	time = ru.ru_utime;

	return time.tv_sec*1000000 + (time.tv_usec);
}
