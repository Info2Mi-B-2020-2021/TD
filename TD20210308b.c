/**
  \file      TD20210308b.c
  \brief     text file reading line by line
  \author    Pierre BRESSY
  \version   1.0
  \date      2021-02-25 17:42:00
  \details
**/

#include <stdio.h>  // standard library for inputs and ouputs

#define MAX_LENGTH 1024

int main(int argc, const char *argv[]) {

  const char *filename = "./data.csv";
  const char *mode = "r";

  FILE *fp = NULL; // file descriptor
  unsigned int count = 0;
  char *result = NULL;
  char s[MAX_LENGTH] = {0};

  fp = fopen(filename, mode);
  if(NULL==fp) {
    printf("Error while opening %s\n", filename);
  }
  else {

    do {
      result=fgets(s, MAX_LENGTH, fp); // read one line
      if (NULL != result)
      {
        count++;
        printf("line %3d : [%s]\n",count,s);
      }
    } while (NULL!=result);

    printf("%u lines.\n", count);

    // close the file
    if (0 != fclose(fp))
    {
      printf("Error while closing %s\n", filename);
    }
  }
  return 0;
}
