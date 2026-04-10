#include "calcium/lisp_state.h"
#include "calcium/lisp_memory.h"

#include <assert.h>

/*****************************************************************************/
/*                                 LIFE CYCLE                                */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPbool8
lispStateInitialize(LISPstate* state)
{
  assert(state);

  auto mem = lispStateGetMemory(state);

  LISPbool8 success = true;

  success &= lispMemoryInitialize(mem);

  return success;
}

LISP_EXPORT void
lispStateFinalize(LISPstate* state)
{
  assert(state);

  auto mem = lispStateGetMemory(state);

  lispMemoryFinalize(mem);
}
