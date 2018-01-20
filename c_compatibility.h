
/*
 * Header file with macros to provide compatibility with C89 compilers
 */

#define C89

#ifdef C89

#define bool        char
#define true        1
#define false       0
#define int64_t     long
#define inline

#else

#include <stdbool.h>
#include <stdint.h>

#endif
