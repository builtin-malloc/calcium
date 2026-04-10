#include "calcium/lisp_reader.h"

#include <assert.h>

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPvalue
lispRead(LISPstate* state, const LISPchar8* src)
{
  assert(state);
  assert(src);

  return (LISPvalue)NULL;
}
