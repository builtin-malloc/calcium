#ifndef LISP_WRITER_H
#define LISP_WRITER_H

#include "lisp_prelude.h"

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPchar8*
lispWrite(LISPstate* state, LISPvalue form);

#endif /* LISP_WRITER_H */
