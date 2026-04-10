#include "args.h"

#include <stdlib.h>

/*****************************************************************************/
/*                                    MAIN                                   */
/*****************************************************************************/

[[nodiscard]] static int
replMain([[maybe_unused]] const APPargs* args)
{
  return EXIT_SUCCESS;
}

int
main(int argc, char* argv[])
{
  APPargs args;
  if (!appArgsInitialize(&args, argc, argv)) return EXIT_FAILURE;

  int status = EXIT_SUCCESS;

  switch (args.type) {
    case APP_TYPE_REPL: status = replMain(&args); break;
  }

  appArgsFinalize(&args);
  return status;
}
