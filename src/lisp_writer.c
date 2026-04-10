#include "calcium/lisp_writer.h"
#include "calcium/lisp_memory.h"
#include "calcium/lisp_state.h"

#include <assert.h>
#include <string.h>

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPchar8*
lispWrite(LISPstate* state, [[maybe_unused]] LISPvalue form)
{
  assert(state);

  auto mem  = lispStateGetMemory(state);
  auto msg  = "TODO: Implement Write";
  auto repr = lispMemoryAllocate(mem, strlen(msg) + 1);

  if (repr) strcpy(repr, msg);

  return repr;
}
