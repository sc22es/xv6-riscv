#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
  // Buffer for up to 10 commands, each up to 100 bytes long
  // plus 3 bytes for the command numbers and space.
  char buf[10][103];

  // Number of last history entries to print
  int n = 0;
  // Check args given to history command.
  if (argc == 1)
    n = 10; // print all 10
  else if (argc == 2)
    n = atoi(argv[1]);
  else {
    fprintf(2, "Too many arguments.");
    exit(1);
  }

  int hist = open(".history",  O_CREATE | O_RDONLY);
  if (hist < 0) {
    printf("No history of commands.");
    exit(0);
  }

  // Read in the history to buf.
  int count = 0;
  char *p = buf[0];
  while (read(hist, p, 1) != 0) {
    if (*p == '\n') {
      count++;
      p = buf[count];
    } else
      p++;
  }
  close(hist);

  // Print last few entires
  if (count < n)
    n = count;
  for (int i = 0; i < n; i++)
    fprintf(1, "%s", buf[count-n+i]);

  exit(0);
}
