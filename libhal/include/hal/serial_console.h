#include <hal/bitints.h>
#include <stddef.h>

/*
 * Gets a character from the serial console.
 */
char serial_getc();

/* 
 * Puts a character into the serial console.
 */
void serial_putc(char ch);

/*
 * Puts a string into the serial console, assuming
 * it is zero-terminated.
 */
void serial_puts(const char* s);

/*
 * Puts a byte in hex
 */
void serial_putb_hex(u8 x);

/*
 * Puts a number in hex into serial console.
 */
void serial_putl_hex(u64 x);

/*
 * Dump a bunch of data into serial console as hex..
 */
void serial_hexdump(const void* ptr, size_t sz);

/*
 * An oversimplified printf used in the `printf` macro.
 *
 * You are an engineer who is writing libHAL (a bios pretty much). If you forget
 * to give me a NULL-terminated string -- it is not my problem. This function will
 * crash your code if you don't.
 */
void __serial_printf(const char* fmt, const u64* args, size_t cnt);

#define serial_printf(fmt, ...) \
  { \
    u64 args[] = { __VA_ARGS__ }; \
    __serial_printf(fmt, args, sizeof(args) / sizeof(u64)); \
  }
