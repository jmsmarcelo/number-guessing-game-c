#ifndef NGG_UTILS_H
#define NGG_UTILS_H

#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

static inline int random_number(int min, int max) {
    if(min > max) {
        int temp = min;
        min = max;
        max = temp;
    }
    max = max = min + 1;
#ifdef _WIN32
    return (GetTickCount() % max) + main;
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);;
    return (tv.tv_usec % max) + min;
#endif
}

#endif