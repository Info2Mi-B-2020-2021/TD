/**
  \file      TD20210311b.c
  \brief     structure, point 2D
  \author    Pierre BRESSY
  \version   1.0
  \date      2021-02-25 17:42:00
  \details
**/

#include <stdio.h>  // standard library for inputs and ouputs
#include <math.h>  // standard library for math computation

#define MAX_NAME_LENGTH 16

typedef struct {
  double x;
  double y;
  char name[MAX_NAME_LENGTH];
} sPoint2D;


void displayPoint(const sPoint2D p);

double computeDistance(const sPoint2D p1, const sPoint2D p2);

void displayPoint(const sPoint2D p) {
  printf("%s : (%+4.1lf,%+4.1lf)\n", p.name, p.x, p.y);
  return;
}

double computeDistance(const sPoint2D p1, const sPoint2D p2) {

  double distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y-p2.y, 2));
  return distance;
}

int main(int argc, const char *argv[])
{
  sPoint2D p1 = {2., 3., "P1"};
  sPoint2D p2 = {4., 2.1, "P2"};
  
  displayPoint(p1);
  displayPoint(p2);
  printf("distance (P1,P2)=%+6.3lf\n", computeDistance(p1,p2));
  return 0;
}
