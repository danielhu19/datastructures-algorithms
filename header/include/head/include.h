#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ElemType int
#define INIT 100
#define STATUS int

// https://stackoverflow.com/questions/26053959/what-does-va-args-in-a-macro-mean
#define _LOG(...)        \
  do {                   \
    printf(__VA_ARGS__); \
  } while (0);

// https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix
#define LOG(format, ...)                                                       \
  _Log("\33[1;34m[%s,%d,%s] " format "\33[0m\n", __FILE__, __LINE__, __func__, \
       ##__VA_ARGS__)

#define Assert(cond, ...)           \
  do {                              \
    if (!(cond)) {                  \
      fflush(stdout);               \
      fprintf(stderr, "\33[1;31m"); \
      fprintf(stderr, __VA_ARGS__); \
      fprintf(stderr, "\33[0m\n");  \
      assert(cond);                 \
    }                               \
  } while (0)

#define panic(...) Assert(0, __VA_ARGS__)

#endif