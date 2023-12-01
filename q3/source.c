#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

typedef enum {
  OPERATOR,
  NOT_OPERATOR,
  ERROR
} OperatorType;

int isOperator(char *token) {
  if (strcmp(token, "+") == 0 ||
      strcmp(token, "-") == 0 ||
      strcmp(token, "*") == 0 ||
      strcmp(token, "/") == 0) {
    return OPERATOR;
  } else {
    return NOT_OPERATOR;
  }
}

int main() {
  char input[MAX_INPUT_LENGTH + 1];

  printf("Enter a string: ");
  fgets(input, MAX_INPUT_LENGTH + 1, stdin);

  char *token = strtok(input, " ");
  while (token != NULL) {
    OperatorType operatorType = isOperator(token);
    if (operatorType == OPERATOR) {
      printf("%s is an operator.\n", token);
    } else if (operatorType == NOT_OPERATOR) {
      printf("%s is not an operator.\n", token);
    } else {
      printf("Error parsing token: %s\n", token);
    }

    token = strtok(NULL, " ");
  }

  return 0;
}
