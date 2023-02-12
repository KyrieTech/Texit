#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

void create_file(char *filename) {
  FILE *fp;
  fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Error creating file.\n");
    exit(0);
  }
  printf("File created successfully.\n");
  system("clear");
  fclose(fp);
}

void write_to_file(char *filename) {
  char line[MAX_LINE_LENGTH];
  FILE *fp;
  fp = fopen(filename, "a");
  if (fp == NULL) {
    printf("Error opening file.\n");
    exit(0);
  }
  printf("~$ ");
  while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
    fprintf(fp, "%s", line);
  }
  system("clear");
  printf("File written successfully.\n");
  fclose(fp);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("To Get Started... Type: ./texit [filename]\n");
    exit(0);
  }
  char *filename = argv[1];
  create_file(filename);
  write_to_file(filename);
  return 0;
}