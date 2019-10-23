#include "utils.h"

void *xmalloc(size_t size) {
  void *p = malloc(size);

  if (!p) {
    perror("xmalloc");
    exit(1);
  }

  return p;
}

void *xrealloc(void *ptr, size_t size) {
  void *p;

  if (!ptr)
    return xmalloc(size);

  p = realloc(ptr, size);

  if (!p) {
    perror("xrealloc");
    exit(1);
  }

  return p;
}
