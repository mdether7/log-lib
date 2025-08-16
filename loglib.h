/* loglib.h */
#ifndef LOGLIB_H
#define LOGLIB_H

/*
* Initialize logging system to log to a specified file.
* Return 0 on success -1 on error.
*/
int log_init(const char* file_name);

#endif