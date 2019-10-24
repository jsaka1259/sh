#include "io.h"

static void debug_input(char *line_buf) {
  size_t i = 0;

  fprintf(stdout, "\e[33m");
  fprintf(stdout, "[%s]:\n", __func__);
  fprintf(stdout, "%08lx  %02x ", i, line_buf[i]);
  for (i = 1; i < LINE_BUF_SIZE; i++) {
    if (i % 16 == 0)
      fprintf(stdout, "\n%08lx  ", i);
    else if (i % 8 == 0)
      fputs(" ", stdout);
    fprintf(stdout, "%02x ", line_buf[i]);
  }
  fprintf(stdout, "\nstr%*s%s (%ld)\n",
      7, "", line_buf, strlen(line_buf));
  fprintf(stdout, "\e[m");
}

void input(char *line_buf) {
  unsigned int i;

  memset(line_buf, 0, LINE_BUF_SIZE);

  for (i = 0; i < LINE_BUF_SIZE - 1; i++) {
    if ((line_buf[i] = fgetc(stdin)) == 0x0a) {
      line_buf[i] = 0;
      break;
    }
  }

  if (i >= LINE_BUF_SIZE - 1) {
    fprintf(stderr,
            "\e[33;1m[info] line buffer size: %lu\e[m\n",
            LINE_BUF_SIZE);
    while (fgetc(stdin) != 0x0a)
      ;
  }

  debug_input(line_buf);
}
