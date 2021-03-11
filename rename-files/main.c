#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: a.out <dir>\n");
    exit(1);
  }

  char *pathname = argv[1];
  printf("Reading from directory: \"%s\"\n", pathname);
  DIR *dir;
  struct dirent *dp;

  if ((dir = opendir(pathname)) == NULL) {
    perror("Cannot open dir");
    exit(1);
  }

  while ((dp = readdir(dir)) != NULL) {
    if (dp->d_name[0] == '.') continue;
    printf("%s\n", dp->d_name);
  }
}

