#ifndef LISP_EVAL_H
#define LISP_EVAL_H

#include "lisp_prelude.h"

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPvalue
lispEvaluate(LISPstate* state, LISPvalue form);

#endif /* LISP_EVAL_H */
