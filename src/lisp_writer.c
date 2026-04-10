#include "calcium/lisp_writer.h"

#include <assert.h>

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPchar8*
lispWrite(LISPstate* state, [[maybe_unused]] LISPvalue form)
{
  assert(state);

  return "TODO: Implement Write";
}
