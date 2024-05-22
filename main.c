#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv) {
  printf("https://man7.org/linux/man-pages/man1/login.1.html\n");
  printf("Discrepancies on the values from the password database and\n");
  printf("env variables may be due to improper system configuration.\n\n");

  {
    struct passwd* pw = getpwuid(getuid());

    printf("=> Password dabase:\n");
    printf("name:\t%s\n", pw->pw_name);
    printf("home:\t%s\n", pw->pw_dir);
    printf("shell:\t%s\n", pw->pw_shell);
  }

  printf("\n");

  {
    printf("=> Environment variables\n");
    printf("name:\t%s\n", getenv("USER"));
    printf("home:\t%s\n", getenv("HOME"));
    printf("shell:\t%s\n", getenv("SHELL"));
  }

  return EXIT_SUCCESS;
}
