#include "calcium/lisp_eval.h"

#include <assert.h>

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPvalue
lispEvaluate(LISPstate* state, LISPvalue form)
{
  assert(state);

  return form;
}
