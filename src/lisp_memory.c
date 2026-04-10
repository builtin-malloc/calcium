#include "calcium/lisp_memory.h"

#include <assert.h>
#include <stdlib.h>

/*****************************************************************************/
/*                             DEFAULT ALLOCATOR                             */
/*****************************************************************************/

static void*
lispHeapAllocate([[maybe_unused]] void* ctx, LISPusize size)
{
  assert(size > 0);
  return malloc(size);
}

static void*
lispHeapReallocate([[maybe_unused]] void* ctx, void* ptr, LISPusize size)
{
  assert(ptr);
  assert(size > 0);
  return realloc(ptr, size);
}

static void
lispHeapFree([[maybe_unused]] void* ctx, void* ptr)
{
  assert(ptr);
  free(ptr);
}

/*****************************************************************************/
/*                                 LIFE CYCLE                                */
/*****************************************************************************/

[[nodiscard]] LISP_EXPORT LISPbool8
lispMemoryInitialize(LISPmemory* mem)
{
  assert(mem);

  mem->context      = nullptr;
  mem->alloc_func   = lispHeapAllocate;
  mem->realloc_func = lispHeapReallocate;
  mem->free_func    = lispHeapFree;

  return true;
}

LISP_EXPORT void
lispMemoryFinalize(LISPmemory* mem)
{
  assert(mem);
}
