#ifndef LISP_STATE_H
#define LISP_STATE_H

#include "lisp_prelude.h"

/*****************************************************************************/
/*                                   TYPES                                   */
/*****************************************************************************/

typedef struct LISPstate
{
  int dummy;
} LISPstate;

/*****************************************************************************/
/*                                 LIFE CYCLE                                */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPbool8
lispStateInitialize(LISPstate* state);
LISP_EXPORT void
lispStateFinalize(LISPstate* state);

#endif /* LISP_STATE_H */
