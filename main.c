#include <common.h>

#define PROMPT "$ "

int main(int argc, char **argv)
{
  while (1) {
    fputs(PROMPT, stdout);
    get_cmd();
  }
  return 0;
}
