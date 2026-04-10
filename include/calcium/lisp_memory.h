#ifndef LISP_MEMORY_H
#define LISP_MEMORY_H

#include "lisp_prelude.h"

/*****************************************************************************/
/*                                   TYPES                                   */
/*****************************************************************************/

typedef void* (*LISPmemoryallocfunc)(void* ctx, LISPusize size);
typedef void* (*LISPmemoryreallocfunc)(void* ctx, void* ptr, LISPusize size);
typedef void  (*LISPmemoryfreefunc)(void* ctx, void* ptr);

typedef struct LISPmemory
{
  void*                 context;
  LISPmemoryallocfunc   alloc_func;
  LISPmemoryreallocfunc realloc_func;
  LISPmemoryfreefunc    free_func;
} LISPmemory;

/*****************************************************************************/
/*                                 LIFE CYCLE                                */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPbool8
lispMemoryInitialize(LISPmemory* mem);
LISP_EXPORT void
lispMemoryFinalize(LISPmemory* mem);

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

[[nodiscard, maybe_unused]] static inline void*
lispMemoryAllocate(LISPmemory* mem, LISPusize size)
{
  if (!mem) return nullptr;
  if (size == 0) return nullptr;
  if (!mem->alloc_func) return nullptr;
  return mem->alloc_func(mem->context, size);
}

[[nodiscard, maybe_unused]] static inline void*
lispMemoryRellocate(LISPmemory* mem, void* ptr, LISPusize new_size)
{
  if (!mem) return nullptr;
  if (!ptr) return lispMemoryAllocate(mem, new_size);
  if (new_size == 0) return ptr;
  if (!mem->realloc_func) return nullptr;
  return mem->realloc_func(mem->context, ptr, new_size);
}

[[maybe_unused]] static inline void*
lispMemoryFree(LISPmemory* mem, void* ptr)
{
  if (!mem) return ptr;
  if (!ptr) return nullptr;
  if (!mem->free_func) return ptr;
  mem->free_func(mem->context, ptr);
  return nullptr;
}

#endif /* LISP_MEMORY_H */
