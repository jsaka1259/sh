#ifndef _PARSE_H_
#define _PARSE_H_

typedef struct {
  int argc;
  char **argv;
} cmd_t;

extern void get_cmd(void);

#endif
