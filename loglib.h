/* loglib.h */
#ifndef LOGLIB_H
#define LOGLIB_H

/*
* Initialize logging system to log to a specified file.
* Return 0 on success -1 on error.
*/
int log_init(const char* file_name);

/*
* Clean up the logging system.
* Closes the file etc.
*/
void log_cleanup(void);

void log_message(const char* message);

#endif