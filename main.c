#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
  {
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;

    printf("pw:\t%s\n", homedir);
  }

  {
    char *homedir = getenv("HOME");
    printf("env:\t%s\n", homedir);
  }

  return EXIT_SUCCESS;
}
