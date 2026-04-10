#ifndef ARGS_H
#define ARGS_H

#include "calcium/lisp_prelude.h"

/*****************************************************************************/
/*                                   TYPES                                   */
/*****************************************************************************/

typedef enum APPtype
{
  APP_TYPE_REPL,
} APPtype;

typedef struct APPargs
{
  APPtype type;
} APPargs;

/*****************************************************************************/
/*                                 LIFE CYCLE                                */
/*****************************************************************************/

[[nodiscard]] LISPbool8
appArgsInitialize(APPargs* args, int argc, char* argv[]);
void
appArgsFinalize(APPargs* args);

#endif /* ARGS_H */
