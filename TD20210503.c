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
#include <string.h>
#include <math.h>
#include "wav.h"


#define MAX_LINE_LENGHT 100

typedef struct {
  int16_t left;
  int16_t right;

} sStereoSample;





int getWaveInfo(char* filename, uint32_t *fs, uint32_t *numSamples) {
  int returnCode = 0;
  const char *mode = "rb";
  FILE *fIn = NULL;
  sWavHeader h;

  fIn = fopen(filename, mode);
  if(fIn!=NULL) {
    if(1==fread(&h,sizeof(sWavHeader),1, fIn)) {
      *fs = h.format.samplingRate;
      *numSamples = h.data.length / h.format.bytesPerSample;
    }
    else {
      printf("Error while reading header of %s\n", filename);
      returnCode = -1;
    }
    if(0!=fclose(fIn)) {
      printf("Error while clsing %s\n", filename);
      returnCode = -1;
    }
  }
  else {
    printf("Error while opening %s\n", filename);
    returnCode = -1;
  }
  return returnCode;
}

int getWaveData(char *filename, sStereoSample **area, uint32_t *numSamples) {

  int returnCode = 0;
  const char *mode = "rb";
  FILE *fIn = NULL;
  sWavHeader h;

  fIn = fopen(filename, mode);
  if(fIn!=NULL) {
    if(1==fread(&h,sizeof(sWavHeader),1, fIn)) {
      *numSamples = h.data.length / h.format.bytesPerSample;

      printf("Allocating memory to transfer %u samples from %s\n", *numSamples, filename);
      *area = (sStereoSample *)malloc(*numSamples * sizeof(sStereoSample));
      if(NULL==*area) {
        printf("Error while allocating memory to transfer data of %s\n", filename);
        returnCode = -1;
      }
      else {
        if(*numSamples!=fread(*area, sizeof(sStereoSample), *numSamples, fIn)) {
          printf("Error while reading data of %s\n", filename);
          returnCode = -1;
        }
      }
    }
    else {
      printf("Error while reading header of %s\n", filename);
      returnCode = -1;
    }
    if(0!=fclose(fIn)) {
      printf("Error while clsing %s\n", filename);
      returnCode = -1;
    }
  }
  else {
    printf("Error while opening %s\n", filename);
    returnCode = -1;
  }
  return returnCode;
 
}

int main(int argc, char const *argv[])
{
  const char *filename = "melody.txt";
  const char *mode = "r";
  FILE *fIn = NULL;
  char s[MAX_LINE_LENGHT];
  uint32_t fs = 0;
  uint32_t numSamples = 0;
  uint32_t totalNumSamples = 0;
  sStereoSample *t = NULL;
  sStereoSample *area = NULL;
  const double MAX_NOTE_LENGTH=0.5;
  uint32_t numNotes = 0;

  fIn = fopen(filename, mode);
  if(fIn!=NULL) {

    while(!feof(fIn)) {
      fgets(s, MAX_LINE_LENGHT, fIn); // read one line
      if(strchr(s,'\n')) {  // suppress \n if any
        s[strlen(s) - 1] = '\0';
      }
      numNotes++;
      if(0!=getWaveInfo(s, &fs, &numSamples)) {
        printf("Error while reading data of %s\n", s);
      }
      else {
      }
    }
    printf("numNotes=%u\n", numNotes);
    totalNumSamples = numNotes * MAX_NOTE_LENGTH * fs;
    printf("totalNumSamples=%u\n", totalNumSamples);

    t = (sStereoSample *)malloc(totalNumSamples * sizeof(sStereoSample));
    if(NULL==t) {
        printf("Error while alllocating %lu bytes for wav data.\n", totalNumSamples * sizeof(sStereoSample));

    }
    else {

      // parcourir à nouveau le fichier.txt
      rewind(fIn);
      while(!feof(fIn)) {
        fgets(s, MAX_LINE_LENGHT, fIn); // read one line
        if(strchr(s,'\n')) {  // suppress \n if any
          s[strlen(s) - 1] = '\0';
        }
        // pour chaque fichier wav, appeler getWavData
        getWaveData(s, &area, &numSamples);
        // allonger si besoin le tableau alloué dynamiquement
        // à finaliser pour le 6 mai
        if(numSamples<MAX_NOTE_LENGTH * fs) {
        }
        // copier le tableau dans t (au bon endroit)
        // à finaliser pour le 6 mai
      }

      // sauvegarder le fichier wav final.
      // à finaliser pour le 6 mai

      if(t!=NULL) {
        free(t);
        t = NULL;
      }
    }

    if (0 != fclose(fIn))
    {
      printf("Error while closing %s\n", filename);
    }
  }
  else {
    printf("Error while opening %s\n", filename);
  }

  return 0;
}


