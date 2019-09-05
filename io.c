#include <common.h>

char line_buf[LINE_BUF_SIZE];

static void debug_input(void)
{
  size_t i = 0;
  if (sizeof(line_buf) <= 0)
    return;
  fprintf(stdout, "\e[34;1m");
  fprintf(stdout, "[%s]:\n%08lx  %02x ",
          __func__, i, line_buf[i]);
  for (i = 1; i < sizeof(line_buf); i++) {
    if (i % 16 == 0)
      fprintf(stdout, "\n%08lx  ", i);
    else if (i % 8 == 0)
      fputs(" ", stdout);
    fprintf(stdout, "%02x ", line_buf[i]);
  }
  fprintf(stdout, "\n> %s\n", line_buf);
  fprintf(stdout, "\e[m");
}

char *input(void)
{
  uint8_t i;
  memset(line_buf, 0, sizeof(line_buf));
  for (i = 0; i < sizeof(line_buf) - 1; i++) {
    if ((line_buf[i] = fgetc(stdin)) == 0x0a) {
      line_buf[i] = 0x00;
      break;
    }
  }
  if (i >= (sizeof(line_buf) - 1)) {
    fprintf(stderr,
            "\e[33;1m[info] line buffer size: %ld\n", sizeof(line_buf));
    while (fgetc(stdin) != 0x0a) ;
  }
  debug_input();
  return line_buf;
}
