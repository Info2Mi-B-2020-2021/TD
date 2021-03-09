/**
  \file      TD20210308.c
  \brief     text file reading char by char
  \author    Pierre BRESSY
  \version   1.0
  \date      2021-02-25 17:42:00
  \details
**/

#include <stdio.h>  // standard library for inputs and ouputs

int main(int argc, const char *argv[]) {

  const char *filename = "./data.csv";
  const char *mode = "r";

  FILE *fp = NULL; // file descriptor
  unsigned int count = 0;
  char c = ' ';

  fp = fopen(filename, mode);
  if(NULL==fp) {
    printf("Error while opening %s\n", filename);
  }
  else {

    do {
      c = fgetc(fp);  // read one char
      if(EOF!=c)      // EOF = End Of File
        count++;
    } while (c != EOF);

    printf("%u bytes.\n", count);

    // close the file
    if (0 != fclose(fp))
    {
      printf("Error while closing %s\n", filename);
    }
  }
  printf("EOF=%d\n.", EOF);
  return 0;
}
