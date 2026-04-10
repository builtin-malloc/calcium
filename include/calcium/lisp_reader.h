#ifndef LISP_READER_H
#define LISP_READER_H

#include "lisp_prelude.h"

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPvalue
lispRead(LISPstate* state, const LISPchar8* src);

#endif /* LISP_READER_H */
