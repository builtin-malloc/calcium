#ifndef LISP_PRELUDE_H
#define LISP_PRELUDE_H

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

/*****************************************************************************/
/*                                   MACROS                                  */
/*****************************************************************************/

#define LISP_EXPORT

/*****************************************************************************/
/*                                 INTERFACE                                 */
/*****************************************************************************/

typedef uintptr_t        LISPvalue;
typedef struct LISPstate LISPstate;

/*****************************************************************************/
/*                                 PRIMITIVES                                */
/*****************************************************************************/

typedef bool    LISPbool8;
typedef char    LISPchar8;
typedef size_t  LISPusize;
typedef uint8_t LISPbyte;

typedef int8_t   LISPint8;
typedef int16_t  LISPint16;
typedef int32_t  LISPint32;
typedef int64_t  LISPint64;
typedef uint8_t  LISPuint8;
typedef uint16_t LISPuint16;
typedef uint32_t LISPuint32;
typedef uint64_t LISPuint64;
typedef float    LISPfloat32;
typedef double   LISPfloat64;

static_assert(sizeof(LISPfloat32) == 4);
static_assert(sizeof(LISPfloat64) == 8);

#endif /* LISP_PRELUDE_H */
