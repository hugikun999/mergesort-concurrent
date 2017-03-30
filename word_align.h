#ifndef __WORD_ALIGN_
#define __WORD_ALIGN_

#include <sys/types.h>

void word_align(char *input, char *output, int pad);
off_t fsize(char *input);

#endif
