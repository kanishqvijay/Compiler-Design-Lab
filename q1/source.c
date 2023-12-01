#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 256

typedef enum {
  IDENTIFIER,
  CONSTANT,
  OPERATOR,
  KEYWORD,
  ERROR
} TokenType;

typedef struct {
  TokenType type;
  char lexeme[MAX_IDENTIFIER_LENGTH + 1];
} Token;

int isKeyword(char *lexeme) {
  const char *keywords[] = {
    "int",
    "char",
    "float",
    "double",
    "void",
    "if",
    "else",
    "while",
    "for",
    "return",
    "break",
    "continue"
  };

  for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
    if (strcmp(lexeme, keywords[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

int isOperator(char *lexeme) {
  const char *operators[] = {
    "+",
    "-",
    "*",
    "/",
    "=",
    "==",
    "!=",
    "<",
    ">",
    "<=",
    ">=",
    "&&",
    "||",
    "!",
    ";",
    ","
  };

  for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); i++) {
    if (strcmp(lexeme, operators[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

Token getNextToken(FILE *fp) {
  Token token;
  token.type = ERROR;

  int c;
  while ((c = fgetc(fp)) != EOF) {
    if (isspace(c)) {
      continue;
    }

    if (c == '/' && (c = fgetc(fp)) == '*') { 
      while ((c = fgetc(fp)) != EOF && (c != '*' || (c = fgetc(fp)) != '/'));
      continue;
    } else if (c == '/' && (c = fgetc(fp)) == '/') { 
      while ((c = fgetc(fp)) != EOF && c != '\n');
      continue;
    }

    int i = 0;
    while (isalnum(c) || c == '_') {
      token.lexeme[i++] = c;
      c = fgetc(fp);
    }

    token.lexeme[i] = '\0';

    if (isKeyword(token.lexeme)) {
      token.type = KEYWORD;
    } else if (isdigit(token.lexeme[0])) {
      token.type = CONSTANT;
    } else if (isOperator(token.lexeme)) {
      token.type = OPERATOR;
    } else {
      token.type = IDENTIFIER;
    }

    break;
  }

  return token;
}

int main() {
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  Token token;
  while ((token = getNextToken(fp)).type != ERROR) {
    printf("Token: %s, Type: %d\n", token.lexeme, token.type);
  }

  fclose(fp);

  return 0;
}
