#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"file_utils.h"

int main(int argc, char **argv) {
  char *string = getFileContents("testing.txt");
  for(int i = 0; i < strlen(string); i++) {
    printf("%c", string[i]);
  }
  printf("\n");
  int lines = 0;
  char **stringMatrix = getFileLines("testing.txt", &lines);
  for(int i = 0; i < lines; i++) {
    printf("%s\n", stringMatrix[i]);
  }
  return 0;
}
