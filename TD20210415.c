/**
  \file      TD20210415.c
  \brief     Memory allocation
  \author    Pierre BRESSY
  \version   1.0
  \date      2021-03-29 13:15:00
  \details

**/

#include <stdio.h>  // standard library for inputs and ouputs
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char const *argv[])
{
  int16_t *t = NULL;
  size_t n = 0;

  printf("Entrez la valeur de n : ");
  scanf("%lu", &n);

  printf("Allocating %lu bytes...\n", n * sizeof(int16_t));

  t = (int16_t *)malloc(n * sizeof(int16_t));
  if(NULL==t) {
    printf("Error while allocating %lu bytes.\n", n * sizeof(int16_t));
  }
  else {
    printf("Table allocated at address %p\n", t);

    print("Freeing memory.\n");
    free(t);
    t = NULL;
  }
  return 0;
}

