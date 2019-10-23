#include "common.h"

#define PROMPT "$ "

int main(int argc, char **argv) {
  char  *line_buf = NULL;
  cmd_t *cmd      = NULL;


  while (1) {
    fputs(PROMPT, stdout);

    line_buf = xmalloc(LINE_BUF_SIZE);
    cmd = get_cmd(line_buf);

    free(line_buf);
    while (!cmd->argv)
      free(cmd->argv);
    free(cmd);
  }

  return 0;
}
