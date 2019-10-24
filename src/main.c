#include "common.h"

#define PROMPT "$ "

int main(int argc, char **argv) {
  cmd_t *cmd = NULL;

  while (1) {
    fputs(PROMPT, stdout);

    cmd = get_cmd();

    while (!cmd->argv)
      free(cmd->argv);
    free(cmd);
    cmd = NULL;
  }

  return 0;
}
