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


















































#if 0
#include <stdint.h>
#include <math.h>

#define  LOOP_MAX  50
#define  NBCATS  5

typedef struct {
	double x;
	double y;
	double speed;
	int nextCatIndex;
} sCat;

int main(int argc, char *argv[])
{

	sCat cats[NBCATS]={
		{0., 0., 0.1, 1},
		{0., 1., 0.1, 2},
		{2., 1., 0.1, 3},
		{0.9, 1.3, 0.5, 4},
		{2., 0., 0.1, 0}
	};

	unsigned long loop=0;
	unsigned long cat=0;
	double dist=0.;
	double dx=0.;
	double dy=0.;

  printf("loop,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5\n");
  for (loop = 0; loop < LOOP_MAX; loop++)
  {
    printf("%ld",loop);
		for(cat=0;cat<NBCATS;cat++) {
			printf(",%+6.3lf,%+6.3lf",cats[cat].x,cats[cat].y);

			dx = cats[cats[cat].nextCatIndex].x - cats[cat].x ;
			dy = cats[cats[cat].nextCatIndex].y - cats[cat].y ;

			cats[cat].x += dx*cats[cat].speed;
			cats[cat].y += dy*cats[cat].speed;
		}
			puts("");
  }
	return 0;
}



#endif