#ifndef MTIME_H
#define MTIME_H

#include <hal/bitints.h>

u64 get_timer(u64 base);
void delay(u64 usec);

#endif