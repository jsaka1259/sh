#include "getcmd.h"

#define OPT_COEF 4

static void debug_get_cmd(cmd_t *cmd) {
  size_t i = 0;

  fprintf(stdout, "\e[33m");
  fprintf(stdout, "[%s]:\n", __func__);
  fprintf(stdout, "argc: %d\n", cmd->argc);
  while (cmd->argv[i] != NULL) {
    fprintf(stdout, "%4ld: %s (%ld)\n",
        i, cmd->argv[i], strlen(cmd->argv[i]));
    i++;
  }
  fprintf(stdout, "\e[m");
}

cmd_t *get_cmd(void) {
  const char *delimiter = " \t";
  char       *line_buf  = NULL;
  char       *p         = NULL;
  size_t      nopt      = OPT_COEF;
  cmd_t      *cmd;

  cmd       = xmalloc(sizeof(cmd_t));
  cmd->argc = 0;
  cmd->argv = xmalloc(sizeof(*cmd->argv) * nopt);

  line_buf = xmalloc(LINE_BUF_SIZE);
  input(line_buf);
  p = strtok(line_buf, delimiter);

  cmd->argv[cmd->argc] = xmalloc(strlen(p) + 1);
  strcpy(cmd->argv[cmd->argc++], p);

  while ((p = strtok(NULL, delimiter)) != NULL) {
    if (cmd->argc % 4 == 0)
      cmd->argv = xrealloc(
          cmd->argv,
          sizeof(*cmd->argv) * (nopt += OPT_COEF));
    cmd->argv[cmd->argc] = xmalloc(strlen(p) + 1);
    strcpy(cmd->argv[cmd->argc++], p);
  }
  cmd->argv[cmd->argc] = NULL;

  free(line_buf);
  line_buf = NULL;

  debug_get_cmd(cmd);

  return cmd;
}
