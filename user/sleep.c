#include "kernel/types.h"
#include "user/user.h"

//int sleep(int n)

int main(int argc, char *argv[]) {
    printf("fj");

    // only allows 1 arg
    if (argc == 1) {
        printf("ERROR: Sleep only accepts 1 argument\n");
        exit(0);
    }

    
    exit(0);
};