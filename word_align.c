#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/stat.h>

#include "word_align.h"

#define MAX_SIZE 100
#define MAX_NAME_SIZE 16

void word_align(char *input, char *output, int pad)
{
    FILE *fd_in = fopen(input, "r");
    FILE *fd_out = fopen(output, "w+");
    assert(fd_in && "input file open error");
    assert(fd_out && "output file open error");

    int suffix;
    char rbuf[MAX_SIZE];
    char *wbuf = (char *) malloc(sizeof(char) * pad);
    assert(wbuf && "wbuf malloc error");

    while (fgets(rbuf, sizeof(rbuf), fd_in)) {
        memset(wbuf, '\0', pad);

        if (suffix = (pad - strlen(rbuf)) < 0) {
            printf("Waring:\n\tLength of %s is longer than %d\n", rbuf, pad);
        }

        strncpy(wbuf, rbuf, strlen(rbuf));
        fwrite(wbuf, pad, sizeof(char), fd_out);
    }



    fclose(fd_in);
    fclose(fd_out);
    free(wbuf);
}

off_t fsize(char *input)
{
    struct stat st;
    stat(input, &st);

    return st.st_size;
}
