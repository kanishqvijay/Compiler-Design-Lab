#include <stdio.h>

int main() {
  FILE *fp;
  int whitespaceCount = 0;
  int newlineCount = 0;
  char ch;

  fp = fopen("input.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  while ((ch = fgetc(fp)) != EOF) {
    if (isspace(ch)) {
      whitespaceCount++;
    } else if (ch == '\n') {
      newlineCount++;
    }
  }

  fclose(fp);

  printf("Whitespace count: %d\n", whitespaceCount);
  printf("Newline count: %d\n", newlineCount);

  return 0;
}