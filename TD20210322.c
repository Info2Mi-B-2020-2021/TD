/**
  \file      TD20210322.c
  \brief     write data to binary file
  \author    Pierre BRESSY
  \version   1.0
  \date      2021-03-22 16:00:00
  \details

**/

#include <stdio.h>  // standard library for inputs and ouputs
#include <stdint.h>
#include <math.h>

#define N 64

typedef struct {
  double x;
  double y;
} s2DCartesian;

int main(int argc, const char *argv[])
{
  FILE *f = NULL;
  const char *filename = "data/data.bin";
  const char *mode = "wb";
  int ret = 0;
  uint32_t n = N; // for header

  const double radius = 1.0;
  const double pi = 3.141592654;
  s2DCartesian t[N];
  int index = 0;
  double theta;
  const double deltaTheta = 2 * pi / N;

  for (index = 0; index < N;index++) {
    theta = index * deltaTheta;
    t[index].x = radius * cos(theta);
    t[index].y = radius * sin(theta);
  }

  for (index = 0; index < N;index++) {
    theta = index * deltaTheta;
    printf("%7.1lf %+6.3lf %+6.3lf\n",
        theta*180/pi, t[index].x, t[index].y);
  }

  f = fopen(filename, mode);
  if(f!=NULL) {

    ret = fwrite(&n, sizeof(uint32_t), 1, f);
    if(1!=ret) {
      printf("Error while writing header.\n");
    }
    ret = fwrite(t, sizeof(s2DCartesian), N, f);
    if(N!=ret) {
      printf("Error while writing data.\n");
    }
    if(fclose(f)!=0) {
      printf("Error while closing [%s].\n",filename);
    }
  }
  else {
    printf("Error while creating [%s].\n",filename);
  }

  return 0;
}

