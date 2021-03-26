/**
  \file      TD20210325.c
  \brief     pointeurs....
  \author    Pierre BRESSY
  \version   1.0
  \date      2021-03-22 16:00:00
  \details

**/

#include <stdio.h>  // standard library for inputs and ouputs
#include <stdint.h>

int main(int argc, const char *argv[])
{

  int i ;
  int *pi = &i;
  printf("             // i : %6d   pi : %p\n", i, pi);
  i = 1;
  printf("i = 1;       // i : %6d   pi : %p\n", i, pi);
  pi = &i;
  printf("pi = &i;     // i : %6d   pi : %p\n", i, pi);
  *pi = 2;
  printf("*pi = 2;     // i : %6d   pi : %p\n", i, pi);
  *&i = 3;
  printf("*&i = 3;     // i : %6d   pi : %p\n", i, pi);
  pi = 4;
  printf("pi = 4;      // i : %6d   pi : %p\n", i, pi);
  *pi = 5;
  printf("*pi = 5;     // i : %6d   pi : %p\n", i, pi);

  return 0;
}


int main_1(int argc, const char *argv[])
{

  int32_t i = 0;
  int16_t j = 42;
  
  printf("adress of i : %p\n", &i);
  printf("adress of j : %p\n", &j);

  return 0;
}

