/**
  \file      TD20210329.c
  \brief     Cats Hunting
  \author    Pierre BRESSY
  \version   1.0
  \date      2021-03-29 13:15:00
  \details

**/

#include <stdio.h>  // standard library for inputs and ouputs
#include <assert.h>
#include <stdint.h>

typedef struct {
  double x;
  double y;

} sPosition2D;

typedef struct {
  sPosition2D pos;
  double speed;
  uint32_t huntedCatId;
  uint32_t catId;
} sCat;

#define NUM_CATS 5
#define NUM_ITERATIONS 50
#define DELTA_T 1.0

int main(int argc, char const *argv[])
{
  sCat cat[NUM_CATS] = {   // cat[0].
      {{0.0, 0.0}, 0.1, 1, 0},
      {{1.0, 0.0}, 0.1, 2, 1},
      {{2.0, 1.0}, 0.1, 3, 2},
      {{0.9, 1.3}, 0.1, 4, 3},
      {{2.0, 0.0}, 0.1, 0, 4}};

  uint32_t iter = 0;
  uint32_t catIndex = 0;
  uint32_t huntedCatIndex = 0;
  double dx = 0.;
  double dy = 0.;
  
  FILE *f=NULL;
  const char *filename = "data.csv";
  const char *mode = "w";

  f = fopen(filename, mode);
  if(NULL==f) {
    printf("Error while creating to %s\n", filename);
  }
  else {

    for (iter = 0; iter < NUM_ITERATIONS; iter++)
    {
      fprintf(f,"%d, ", iter);
      if(ferror(f)) {
        printf("Error while writing to %s\n", filename);
      }

      for (catIndex = 0; catIndex < NUM_CATS; catIndex++)
      {
        huntedCatIndex = cat[catIndex].huntedCatId; // id of hunted cat

        // position difference along x and y axes
        dx = cat[huntedCatIndex].pos.x - cat[catIndex].pos.x;
        dy = cat[huntedCatIndex].pos.y - cat[catIndex].pos.y;
        // new position computation
        cat[catIndex].pos.x += dx * cat[catIndex].speed * DELTA_T;
        cat[catIndex].pos.y += dy * cat[catIndex].speed * DELTA_T;

        fprintf(f,"%+6.3lf, %+6.3lf%s", cat[catIndex].pos.x, cat[catIndex].pos.y, catIndex==(NUM_CATS-1) ? "\n":", ");
        if (ferror(f))
        {
          printf("Error while writing to %s\n", filename);
        }

      }

    }
    if(fclose(f)) {
      printf("Error while closing %s\n", filename);
    }
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