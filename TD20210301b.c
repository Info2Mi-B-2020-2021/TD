/**
  \file      TD20210301b.c
  \brief     text file creation
  \author    Pierre BRESSY
  \version   1.0
  \date      2021-02-25 17:42:00
  \details
        
        read chapter 12 in https://heig-tin-info.github.io/handout/content/files.html
**/

#include <stdio.h>  // standard library for inputs and ouputs
#include <math.h>   // math library for sine computation

int main(int argc, const char *argv[]) {

  const char *filename = "./data.csv";
  const char *mode = "w";

  const double start_angle = 0.;
  const double stop_angle = 359.;
  const double step_angle = 1.;
  const double pi = 3.141592654;  // M_PI non standard

  double angle = 0.;

  FILE *fp = NULL; // file descriptor

  fp = fopen(filename, mode);
  if(NULL==fp) {
    printf("Error while opening %s\n", filename);
  }
  else {
    fprintf(fp, "angle,sinus,cosinus\n");
    for (angle = start_angle; angle <= stop_angle; angle += step_angle)
    {

      fprintf(fp, "%3.0lf,%+6.3lf,%+6.3lf\n",
              angle,
              sin(angle * pi / 180.),
              cos(angle * pi / 180.) );
    }
    // close the file
    if (0 != fclose(fp))
    {
      printf("Error while closing %s\n", filename);
    }
}

  return 0;
}
