#ifndef FLASH_IO_H
#define FLASH_IO_H

#include <stddef.h>

enum flash_status {
  FLASH_OK,
  FLASH_NOT_SUPPORTED,
  FLASH_ERR,
};

enum flash_status flash_init();

enum flash_status flash_read(size_t flash_off, void* buff, size_t len);

#endif