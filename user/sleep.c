#include "kernel/types.h"
#include "user/user.h"


int main(int argc, char *argv[]) {

    // only allows 1 arg

    if (argc != 2) {
        printf("ERROR: Sleep only accepts 1 argument\n");
        exit(0);
    }

    int i = atoi(argv[1]);
    sleep(i);
    printf("%d", argc);
    exit(0);
};