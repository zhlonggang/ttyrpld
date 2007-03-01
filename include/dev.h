#ifndef TTYRPLD_DEV_H
#define TTYRPLD_DEV_H 1

#define K26_MINORBITS 20
#define K26_MINORMASK 0xFFFFF
#define K26_MAJOR(dev) (unsigned long)((dev) >> K26_MINORBITS)
#define K26_MINOR(dev) (unsigned long)((dev) & K26_MINORMASK)
#define K26_MKDEV(major, minor) \
	(((major) << K26_MINORBITS) | ((minor) & K26_MINORMASK))
#define KD26_PARTS(dev) K26_MAJOR(dev), K26_MINOR(dev)

/* FreeBSD and OpenBSD
 * Scheme is:
 *   bits  0 - 7      (8 bits)    minor, lower part
 *   bits  8 - 15     (8 bits)    major
 *   bits 16 - 31    (16 bits)    minor, upper part
 */
#if defined(__FreeBSD__) || defined(__OpenBSD__)
#	define COMPAT_MAJOR(dev) \
		(unsigned long)(((dev) & 0xFF00) >> 8)
#	define COMPAT_MINOR(dev) \
		(unsigned long)(((dev) & 0xFF) | (((dev) & 0xFFFF0000) >> 8))
#	define COMPAT_MKDEV(major, minor) \
		(unsigned long)((((major) & 0xFF) << 8) | ((minor) & 0xFF) | \
		(((minor) & 0xFFFF00) << 8))

/* Glibc-Linux and NetBSD
 * Scheme is:
 *   bits  0 -  7     (8 bits)    minor, lower part
 *   bits  8 - 19    (12 bits)    major
 *   bits 20 - 31    (12 bits)    minor, upper part
 */
#else
#	define COMPAT_MAJOR(dev) \
		(unsigned long)(((dev) & 0xFFF00) >> 8)
#	define COMPAT_MINOR(dev) \
		(unsigned long)(((dev) & 0xFF) | (((dev) & 0xFFF00000) >> 12))
#	define COMPAT_MKDEV(major, minor) \
		(unsigned long)(((minor) & 0xFF) | \
		(((minor) & 0xFFF00) << 12) | \
		(((major) & 0xFFF) << 8))
#endif

#endif /* TTYRPLD_DEV_H */
