#include "calcium/lisp_state.h"

#include <assert.h>

/*****************************************************************************/
/*                                 LIFE CYCLE                                */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPbool8
lispStateInitialize(LISPstate* state)
{
  assert(state);
  return true;
}

LISP_EXPORT void
lispStateFinalize(LISPstate* state)
{
  assert(state);
}
