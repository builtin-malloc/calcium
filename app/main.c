#include "args.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <readline/history.h>
#include <readline/readline.h>

/*****************************************************************************/
/*                                    MAIN                                   */
/*****************************************************************************/

[[nodiscard]] static int
replMain([[maybe_unused]] const APPargs* args)
{
  while (true) {
    auto line = readline("> ");
    if (!line) break;
    if (line[0] == '\0') continue;
    if (strcmp(line, ":q") == 0) break;

    add_history(line);

    printf("\n=> %s\n\n", line);

    free(line);
  }

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
