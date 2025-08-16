/* core.c */
#include "loglib.h"

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

static FILE* log_file;

/* static function prototypes */
static const char* timestamp(void);

int log_init(const char* file_name)
{
  log_file = fopen(file_name, "a");
  time_t time_stamp = time(NULL);
  return 0;
}

void log_cleanup(void)
{
  fclose(log_file);
}

void log_message(const char* message)
{

}

static const char* timestamp(void)
{
  time_t ltime; /* calendar time */
  ltime=time(NULL); /* get current cal time */
  return asctime(localtime(&ltime));
}

