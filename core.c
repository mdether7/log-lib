/* core.c */
#include "loglib.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

static FILE* LOG_FILE;

/* static function prototypes */
static void timestamp(char* buffer, size_t size);
static const char* type_to_string(enum log_types type);

int log_init(const char* file_name)
{
  LOG_FILE = fopen(file_name, "a");
  if (!LOG_FILE) {
    return -1;
  }
  log_message(INFO, "LOG SUCCESSFULLY INITIALIZED");
  return 0;
}

void log_cleanup(void)
{
  fclose(LOG_FILE);
}

void log_message(enum log_types type, const char* fmt, ...)
{
  if (!LOG_FILE) {
    return;
  }

  char time[32];
  char log_entry[MAX_LOG_SIZE];
  char message[MAX_LOG_SIZE / 2];
  va_list args;

  va_start(args, fmt);
  vsnprintf(message, sizeof(message), fmt, args);
  va_end(args);

  timestamp(time, 32);
  snprintf(log_entry, MAX_LOG_SIZE, "[%s][%s]:[%s]\n", type_to_string(type), time, message);

  size_t len = strlen(log_entry);
  size_t written = fwrite(log_entry, 1, len, LOG_FILE);

  if (written != len) 
  {
    fprintf(stderr, "Writing log to file failed: %s", log_entry);
  }
  else
  {
    fflush(LOG_FILE);
  }
}

static void timestamp(char* buffer, size_t size)
{
  struct tm* ts;
  time_t ltime;
  ltime = time(NULL);
  ts = localtime(&ltime);
  strftime(buffer, size, "%c", ts);
}

static const char* type_to_string(enum log_types type)
{
  switch (type)
  {
    case INFO: return "INFO";
    case WARNING: return "WARNING";
    case ERROR: return "ERROR";
    case DEBUG: return "DEBUG";
    default: return "???";
  }
}



