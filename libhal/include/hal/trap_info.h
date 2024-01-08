#ifndef TRAP_INFO_H
#define TRAP_INFO_H

enum trap_type {
  TRAP_M_MODE,
  TRAP_S_MODE,
};

/*
 * Formats the trap information based off `ty` in a human readable
 * format.
 */
void format_trap(enum trap_type ty);

#endif
