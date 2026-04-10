#ifndef LISP_STATE_H
#define LISP_STATE_H

#include "lisp_memory.h"
#include "lisp_prelude.h"

#include <assert.h>

/*****************************************************************************/
/*                                   TYPES                                   */
/*****************************************************************************/

typedef struct LISPstate
{
  LISPmemory memory;
} LISPstate;

/*****************************************************************************/
/*                                 LIFE CYCLE                                */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPbool8
lispStateInitialize(LISPstate* state);
LISP_EXPORT void
lispStateFinalize(LISPstate* state);

/*****************************************************************************/
/*                                 ACCESSORS                                 */
/*****************************************************************************/

[[nodiscard, maybe_unused]] static inline LISPmemory*
lispStateGetMemory(LISPstate* state)
{
  assert(state);
  return &state->memory;
}

[[maybe_unused]] static inline void
lispStateSetMemoryContext(LISPstate* state, void* ctx)
{
  assert(state);
  state->memory.context = ctx;
}

[[maybe_unused]] static inline void
lispStateSetMemoryAllocFunc(LISPstate* state, LISPmemoryallocfunc alloc)
{
  assert(state);
  state->memory.alloc_func = alloc;
}

[[maybe_unused]] static inline void
lispStateSetMemoryReallocFunc(LISPstate* state, LISPmemoryreallocfunc realloc)
{
  assert(state);
  state->memory.realloc_func = realloc;
}

[[maybe_unused]] static inline void
lispStateSetMemoryFreeFunc(LISPstate* state, LISPmemoryfreefunc free)
{
  assert(state);
  state->memory.free_func = free;
}

#endif /* LISP_STATE_H */
