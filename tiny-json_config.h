
/*
 * Header file with macros to provide compatibility with C89 compilers
 */

#define TINYJSON_C89    1

#if TINYJSON_C89

#ifndef bool
typedef char bool;
#endif

#ifndef int32_t
typedef long int32_t;
#endif

#define true        1
#define false       0
#define inline

#define TINYJSON_USE_LONG_LONG_INTEGER   0  // long long integer is not C89-compliant

#else

#include <stdbool.h>
#include <stdint.h>

#define TINYJSON_USE_LONG_LONG_INTEGER   1  // integer can be used as long or long long

#endif
