#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

typedef enum {
  COMMENT,
  NOT_COMMENT
} CommentType;

int isComment(char *line) {
  int length = strlen(line);

  if (line[0] == '/' && line[1] == '/') {
    return 1;
  }

  for (int i = 0; i < length - 1; i++) {
    if (line[i] == '/' && line[i + 1] == '*') {
      for (i += 2; i < length; i++) {
        if (line[i] == '*' && line[i + 1] == '/') {
          return 1;
        }
      }
      return 2;
    }
  }

  return 0;
}

int main() {
  char line[MAX_LINE_LENGTH + 1];

  printf("Enter a line: ");
  fgets(line, MAX_LINE_LENGTH + 1, stdin);

  CommentType commentType = isComment(line);

  if (commentType == COMMENT) {
    printf("The line is a comment.\n");
  } else if (commentType == 2) {
    printf("The line is an unclosed multi-line comment.\n");
  } else {
    printf("The line is not a comment.\n");
  }

  return 0;
}
