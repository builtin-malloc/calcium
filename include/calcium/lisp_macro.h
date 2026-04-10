#ifndef LISP_MACRO_H
#define LISP_MACRO_H

#include "lisp_prelude.h"

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPvalue
lispMacroExpand(LISPstate* state, LISPvalue form);

#endif /* LISP_MACRO_H */
