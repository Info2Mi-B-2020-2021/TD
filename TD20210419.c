/**
  \file      TD20210419.c
  \brief     Memory allocation
  \author    Pierre BRESSY
  \version   1.0
  \date      2021-03-29 13:15:00
  \details

**/

#include <stdio.h>  // standard library for inputs and ouputs
#include <stdlib.h>
#include <stdint.h>

typedef struct {
  double time;
  double voltage;
} sData;


int main(int argc, char const *argv[])
{
  FILE *fIn = NULL;
  const char *filename = "data.txt";
  const char *mode = "r";
  uint32_t n = 0;
  sData *t = NULL;
  int ret = 0; // test return value fscanf
  double sum = 0.;
  double mean = 0.;
  uint32_t k = 0;

  fIn = fopen(filename, mode);
  if(NULL!=fIn) {
    ret = fscanf(fIn, "%u", &n);
    if(1==ret) {
      printf("N=%u\n", n);

      t = (sData *)malloc(n * sizeof(sData));
      if(NULL!=t) {

        for (k = 0; k < n;k++) {
          ret = fscanf(fIn, "%lf%lf",
                       &(t[k].time),
                       &(t[k].voltage));
          if(2!=ret) {
            printf("Error while reading line #%u\n",k+1);
          }
        }
        sum = 0.;
        for (k = 0; k < n; k++) {
          sum += t[k].voltage;
        }
        mean = n == 0 ? 0. : sum / n; // prevent div by zero
        printf("mean(voltage)=%+6.3lf [V]\n", mean);

        free(t);
        t = NULL;
      }
      else {
        printf("Error while memory allocation.\n");
      }
    }
    else {
      printf("Error while reading N\n");
    }
    if(0!=fclose(fIn)) {
      printf("Error while closing %s\n",filename);
    }
  }
  else
  {
    printf("Error while opening %s\n", filename);
  }
}
