#include <common.h>

#define OPT_COEF 4

cmd_t *cmd;

static void debug_get_cmd(void)
{
  size_t i = 0;
  fprintf(stdout, "\e[34;1m");
  fprintf(stdout, "[%s]:\n", __func__);
  while (cmd->argv[i] != NULL) {
    fprintf(stdout, "%2ld: %s\n", i, cmd->argv[i]);
    i++;
  }
  fprintf(stdout, "\e[m");
}

void get_cmd(void)
{
  const char *delimiter = " \t";
  size_t nopt = OPT_COEF;
  char *p = input();
  cmd = xmalloc(sizeof(cmd_t));
  cmd->argc = 0;
  cmd->argv = xmalloc(sizeof(*cmd->argv) * nopt);
  cmd->argv[cmd->argc++] = strtok(p, delimiter);
  while ((p = strtok(NULL, delimiter)) != NULL) {
    if (cmd->argc % 4 == 0)
      cmd->argv = xrealloc(cmd->argv, sizeof(*cmd->argv) * (nopt += OPT_COEF));
    cmd->argv[cmd->argc++] = p;
  }
  cmd->argv[cmd->argc] = NULL;
  debug_get_cmd();
  while (!cmd->argv)
    free(*cmd->argv);
  free(cmd);
}
