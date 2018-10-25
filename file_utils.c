/*
 *Author(s): Collin Sipple, Victor Nguyen
 *Date Created: 10/25/2018
 *Date Modified: 10/25/2018
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"file_utils.h"

char *getFileContents(const char *filePath) {
  if(filePath == NULL) {
    return NULL;
  }
  FILE *file = fopen(filePath, "r");
  if(file == NULL) {
    return NULL;
  }
  //Allocate memory for a string
  //First count number of characters in the file
  int numChars = 0;
  int currChar = 0;
  do {
    currChar = fgetc(file);
    numChars++;
  } while(currChar != EOF);
  char *fileString = (char *) malloc(sizeof(char) * numChars);
  //Set the fgetc() back to the beginning of the file
  fclose(file);
  file = fopen(filePath, "r");
  for(int i = 0; i < numChars; i++) {
    fileString[i] = fgetc(file);
  }
  fclose(file);
  return fileString;
}

char **getFileLines(const char *filePath, int *numLines){
  if(filePath == NULL || numLines == NULL) {
    return NULL;
  }
  printf("Begin function getFileLines()\n");
  //TODO: Count the number of lines in the file
  char *string = getFileContents(filePath);
  printf("Function getFileContents() successful\n");
  int lineIndex = 1;
  for(int i = 0; string[i] != EOF; i++) {
    if(string[i] == '\n') {
      lineIndex++;
    }
  }
  char **stringMatrix = (char **) malloc(sizeof(char *) * (lineIndex));
  printf("Number of lines determined to be: %d\n", lineIndex);
  int numChars = 0;
  int index = 0;
  lineIndex = 0;
  //Iterate over each character for each line
  while(string[index] != EOF) {
    if(string[index] != '\n') {
      numChars++;
    } else {
      printf("Begin allocating memory for line %d\n", lineIndex);
      stringMatrix[lineIndex] = (char *) malloc(sizeof(char) * (numChars + 1));
      printf("Line %d memory allocated\n", lineIndex);
      //After a new line is declared, fill that line
      for(int i = 0; i <= numChars; i++) {
        stringMatrix[lineIndex][i] = string[index];
        if(stringMatrix[lineIndex][i] == '\n') {
          stringMatrix[lineIndex][i] = '\0';
        }
      }
      printf("Line %d filled with characters\n", lineIndex);
      lineIndex++;
      numChars = 0;
    }
    index++;
  }
  if(stringMatrix[lineIndex][numChars] == EOF) {
    stringMatrix[lineIndex][numChars] = '\0';
  }
  *numLines = lineIndex;
  printf("Function getFileLines() successful\n");
  free(string);
  return stringMatrix;
}
