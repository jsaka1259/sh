#ifndef _PARSE_H_
#define _PARSE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"
#include "utils.h"

typedef struct {
  int argc;
  char **argv;
} cmd_t;

extern cmd_t *get_cmd(char *line_buf);

#endif
