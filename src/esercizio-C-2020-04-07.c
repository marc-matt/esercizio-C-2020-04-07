/*
 * esercizio-C-2020-04-07.c
 *
 *
 *   IN PROGRESS
 *
 *  Created on: Apr 2, 2020
 *      Author: marco
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char * divide(char * str, char * sep){
  char parola[9];
  int i = 0;
  char *token;
  token =  strtok(str, sep);
  while(token != NULL){
    parola[i] = *token;
    token = strtok(NULL, sep);
    i++;
  }
  return parola;
}

void randomize(char * str, char * sep){
  bool noMore[9];
  for(int i = 0; i < 9; i++){
    noMore[i] = false;
  }
  char parola[9];
  *parola = divide(str, sep);
  int lower = 0;
  int upper = 8;
  char * dest = ""; 
  for(int i = 0; i < 300; i++){
    int num = (rand() % (upper - lower + 1)) + lower;
    if(noMore[num] == false){
      strcat(dest, parola[num]);
      noMore[num] = true;
    }
  }
}

int main(int argc, char * argv[]) {
  char * str = "hello world mi chiamo pino sono date delle stringhe";
  char  sep[] = " ";
  randomize(str, sep);
}
