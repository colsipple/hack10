/*
 *Author(s): Collin Sipple, Victor Nguyen
 *Date Created: 10/25/2018
 *Date Modified: 10/25/2018
 *Purpose: Provide functions for reading in files and specific lines of files
 */

//This function opens a file given a file path and returns all the contents as a
//single string
char *getFileContents(const char *filePath);

//This function opens a file given a path and returns an array of strings
char **getFileLines(const char *filePath, int *numLines);
