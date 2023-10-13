#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {

    // only allows 1 arg

    if (argc != 2) {
        printf("ERROR: Sleep only accepts 1 argument\n");
        exit(0);
    }
    int p[2];
    char *argv[2];

    argv[0] = "wc";
    argv[1] = 0;

    pipe(p);
    if(fork() == 0) {
        close(0);
        dup(p[0]);
        close(p[0]);
        close(p[1]);
        exec("/bin/wc", argv);
    } else {
        close(p[0]);
        write(p[1], "hello world\n", 12);
        close(p[1]);
    }
    exit(0);
};