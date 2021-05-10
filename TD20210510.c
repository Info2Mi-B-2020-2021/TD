/**
  \file      TD20210510.c
  \brief     bitmap file
  \author    Pierre BRESSY
  \version   1.0
  \date      2021-05-10 13:15:00
  \details

**/

#include <stdio.h>  // standard library for inputs and ouputs
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "bitmap.h"

int main(int argc, char const *argv[])
{
  const char *filename = "data/face.bmp";
  const char *mode = "rb";
  FILE *f = NULL;
  sBitmapFileHeader fileHeader;
  sBitMapInfoHeader infoHeader;
  int ret = 0;
  int32_t height = 0;
  int32_t width = 0;
  sRGB pixel;
  uint32_t index = 0;
  uint32_t whitePixelsCount = 0;

  f = fopen(filename, mode);
  if(f!=NULL) {

    ret = fread(&fileHeader, sizeof(sBitmapFileHeader), 1, f);
    ret += fread(&infoHeader, sizeof(sBitMapInfoHeader), 1, f);
    if(2==ret) {

      height = infoHeader.biHeight;
      width = infoHeader.biWidth;

      printf("Image size :  %d rows x %d cols\n", height, width);

      for (index = 0; index < 3;index++) {
        ret = fread(&pixel, sizeof(sRGB), 1, f);
        if(ret==1){
          printf("%3d %3d %3d\n", pixel.R, pixel.G, pixel.B);
        }
        else {
          printf("Error while reading data from %s\n", filename);
        }
      }


      // count white pixels
      fseek(f, sizeof(sBitmapFileHeader)+sizeof(sBitMapInfoHeader), SEEK_SET);
      for (index = 0; index < width*height; index++)
      {
        ret = fread(&pixel, sizeof(sRGB), 1, f);
        if(ret==1){
          if( pixel.R>127 && pixel.G>127 && pixel.B>127) {
            whitePixelsCount++;
          }
        }
        else {
          printf("Error while reading data from %s\n", filename);
        }
      }
      printf("%u white pixels.\n", whitePixelsCount);
    }
    else {
      printf("Error while reading header of %s\n", filename);
    }

    if(0!=fclose(f))
    {
      printf("Error while closing %s\n", filename);
    }
  }
  else {
    printf("Error while opening %s\n", filename);
  }
  return 0;
}

