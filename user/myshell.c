#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"


int getcmd(char *buf, int nbuf) {
  write(2, ">>> ", 4);
  memset(buf, 0, nbuf);
  gets(buf, nbuf);
  printf("%s", buf);  // Print the contents of buf safely.
  if(buf[0] == 0) // EOF
    return -1;
  return 0;
}


int main(void) {
    static char buf[100];
    int fd;



    // Ensure that three file descriptors are open.
    while((fd = open("console", O_RDWR)) >= 0){
        if(fd >= 3){
        close(fd);
        break;
        }
    }
        
    char* tokens[MAX_TOKENS];
    int token_count = 0;
    static char charbuffer[20]


    // Read and run input commands.
    while(getcmd(buf, sizeof(buf)) >= 0){
        static char token;
        int start = 0;

        for (int i = 0; i < sizeof(buf); i++) {
            if(buf[i] == ' ' ) {
                continue;
            }
            else if (buf[i] == '\n' ) {
                break;
            }
            else {
                charbuffer[t] = buf[i];
                t++;
                if (buf[i+1] == ' ') {
                    tokens[token_count] = charbuffer;
                    free(charbuffer);
                    t=0;

                }
            }
        }

        if(buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' '){
        // Chdir must be called by the parent, not the child.
        buf[strlen(buf)-1] = 0;  // chop \n
        if(chdir(buf+3) < 0)
            fprintf(2, "cannot cd %s\n", buf+3);
        continue;
        }

    }




    exit(0);
}

