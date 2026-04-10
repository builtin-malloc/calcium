#include "args.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <readline/history.h>
#include <readline/readline.h>

#include "calcium/lisp_eval.h"
#include "calcium/lisp_macro.h"
#include "calcium/lisp_reader.h"
#include "calcium/lisp_state.h"
#include "calcium/lisp_writer.h"

/*****************************************************************************/
/*                                    MAIN                                   */
/*****************************************************************************/

[[nodiscard]] static int
replMain([[maybe_unused]] const APPargs* args)
{
  // TODO: When we have an empty line or the :q, we don't free its memory

  LISPstate state;
  if (!lispStateInitialize(&state)) return EXIT_FAILURE;

  auto mem = lispStateGetMemory(&state);

  while (true) {
    auto line = readline("> ");
    if (!line) break;
    if (line[0] == '\0') continue;
    if (strcmp(line, ":q") == 0) break;

    add_history(line);

    auto form = lispRead(&state, line);
    form      = lispMacroExpand(&state, form);
    form      = lispEvaluate(&state, form);
    auto repr = lispWrite(&state, form);

    if (repr) printf("\n=> %s\n\n", repr);

    lispMemoryFree(mem, repr);
    free(line);
  }

  lispStateFinalize(&state);
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
