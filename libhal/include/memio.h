#include <bitints.h>

static inline void __raw_writeb(u8 val, volatile void *addr) {
	asm volatile("sb %0, 0(%1)" : : "r"(val), "r"(addr));
}

static inline void __raw_writew(u16 val, volatile void *addr) {
	asm volatile("sh %0, 0(%1)" : : "r"(val), "r"(addr));
}

static inline void __raw_writel(u32 val, volatile void *addr) {
	asm volatile("sw %0, 0(%1)" : : "r"(val), "r"(addr));
}

static inline void __raw_writeq(u64 val, volatile void *addr) {
	asm volatile("sd %0, 0(%1)" : : "r"(val), "r"(addr));
}

static inline u8 __raw_readb(const volatile void *addr) {
	u8 val;

	asm volatile("lb %0, 0(%1)" : "=r"(val) : "r"(addr));
	return val;
}

static inline u16 __raw_readw(const volatile void *addr) {
	u16 val;

	asm volatile("lh %0, 0(%1)" : "=r"(val) : "r"(addr));
	return val;
}

static inline u32 __raw_readl(const volatile void *addr) {
	u32 val;

	asm volatile("lw %0, 0(%1)" : "=r"(val) : "r"(addr));
	return val;
}

static inline u64 __raw_readq(const volatile void *addr) {
	u64 val;

	asm volatile("ld %0, 0(%1)" : "=r"(val) : "r"(addr));
	return val;
}

#define __io_br()	do {} while (0)
#define __io_ar()	__asm__ __volatile__ ("fence i,r" : : : "memory");
#define __io_bw()	__asm__ __volatile__ ("fence w,o" : : : "memory");
#define __io_aw()	do {} while (0)

#define readb(c)	({ u8  __v; __io_br(); __v = __raw_readb(c); __io_ar(); __v; })
#define readw(c)	({ u16 __v; __io_br(); __v = __raw_readw(c); __io_ar(); __v; })
#define readl(c)	({ u32 __v; __io_br(); __v = __raw_readl(c); __io_ar(); __v; })
#define readq(c)	({ u64 __v; __io_br(); __v = __raw_readq(c); __io_ar(); __v; })

#define writeb(v,c)	({ __io_bw(); __raw_writeb((v),(c)); __io_aw(); })
#define writew(v,c)	({ __io_bw(); __raw_writew((v),(c)); __io_aw(); })
#define writel(v,c)	({ __io_bw(); __raw_writel((v),(c)); __io_aw(); })
#define writeq(v,c)	({ __io_bw(); __raw_writeq((v),(c)); __io_aw(); })
