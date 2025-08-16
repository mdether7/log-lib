/* loglib.h */
#ifndef LOGLIB_H
#define LOGLIB_H

/* XXX defines */
#define MAX_LOG_SIZE 512 /* bytes */

/* XXX enums */
enum log_types { INFO = 0, WARNING, ERROR, DEBUG };

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

/*
* Logs the message to a file specified in init.
*/
void log_message(enum log_types type, const char* fmt, ...);

#endif
