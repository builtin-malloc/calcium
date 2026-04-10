#include "calcium/lisp_macro.h"

#include <assert.h>

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPvalue
lispMacroExpand(LISPstate* state, LISPvalue form)
{
  assert(state);

  return form;
}
