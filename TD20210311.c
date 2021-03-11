/**
  \file      TD20210311.c
  \brief     structure, point 2D
  \author    Pierre BRESSY
  \version   1.0
  \date      2021-02-25 17:42:00
  \details
**/

#include <stdio.h>  // standard library for inputs and ouputs
#include <math.h>  // standard library for math computation

void displayPoint(const char *name,
                  const double x,
                  const double y);

double computeDistance(const double x1,
                     const double y1,
                     const double x2,
                     const double y2);

void displayPoint(const char *name,
                  const double x,
                  const double y) {
  printf("%s : (%+4.1lf,%+4.1lf)\n", name, x, y);
  return;
}

double computeDistance(const double x1,
                     const double y1,
                     const double x2,
                     const double y2) {

  double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
  return distance;
}

int main(int argc, const char *argv[])
{
  double x1 = 2.;
  double y1 = 3.;
  double x2 = 4.;
  double y2 = 2.1;
  displayPoint("P1", x1, y1);
  displayPoint("P2", x2, y2);
  printf("distance (P1,P2)=%+6.3lf\n", computeDistance(x1, y1, x2, y2));
  return 0;
}
