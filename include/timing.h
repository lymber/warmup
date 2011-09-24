#ifndef TIMING_H
#define TIMING_H

/* This function returns the total CPU user time consumed until now y the current */
/* process in microseconds */

/* Maybe we wish to consider system time here too: just add ru.ru_stime values*/

long int takethetime(void);

#endif
