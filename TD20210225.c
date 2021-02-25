/**
  \file      TD20210225.c
  \brief     text file creation
  \author    Pierre BRESSY
  \version   1.0
  \date      2021-02-25 17:42:00
  \details
        
        read chapter 12 in https://heig-tin-info.github.io/handout/content/files.html
**/

#include <stdio.h>  // standard library for inputs and ouputs

int main(int argc, const char *argv[]) {

  const char *filename = "./text.txt";
  const char *mode = "w";

  FILE *fp = NULL; // file descriptor

  fp = fopen(filename, mode);
  if(NULL==fp) {
    printf("Error while opening %s\n", filename);
  }
  else {
    // do what you want with the file...

    // close the file
    if(0!=fclose(fp)) {
      printf("Error while closing %s\n", filename);
    }
  }

  return 0;
}
