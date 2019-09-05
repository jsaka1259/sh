#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include "io.h"
#include "getcmd.h"
#include "utils.h"

#define debug_print() fprintf(stdout, "%s:%d\n", __func__, __LINE__)

#endif
