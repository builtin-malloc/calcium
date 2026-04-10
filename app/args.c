#include "args.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>

/*****************************************************************************/
/*                                 LIFE CYCLE                                */
/*****************************************************************************/

[[nodiscard]] LISPbool8
appArgsInitialize(APPargs* args, int argc, char* argv[])
{
  assert(args);
  assert(argc >= 0);
  assert(argv);
  assert(argv[argc] == nullptr);

  args->type = APP_TYPE_REPL;

  for (int i = 1; i < argc; ++i) {
    auto arg = argv[i];

    if (strcmp(arg, "--repl") == 0) {
      if (args->type < APP_TYPE_REPL) {
	args->type = APP_TYPE_REPL;
      }
      continue;
    }

    fprintf(stderr, "[ARGS] Unknown argument: %s\n", arg);
  }

  return true;
}

void
appArgsFinalize(APPargs* args)
{
  assert(args);
}
