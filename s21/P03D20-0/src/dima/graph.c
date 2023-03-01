#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

enum TokenType {
  NUMBER,
  OPERATOR
};

struct Token {
  enum TokenType type;
  double value;
  char operator;
};

struct Token *parseExpression(char *expression) {
  int expressionLength = strlen(expression);
  struct Token *tokens = malloc(expressionLength * sizeof(struct Token));
  int tokenCount = 0;
  char buffer[expressionLength];
  int bufferIndex = 0;

  for (int i = 0; i < expressionLength; i++) {
    char c = expression[i];
    if (c >= '0' && c <= '9' || c == '.') {
      buffer[bufferIndex++] = c;
    } else {
      if (bufferIndex > 0) {
        buffer[bufferIndex] = '\0';
        tokens[tokenCount].type = NUMBER;
        tokens[tokenCount].value = atof(buffer);
        tokenCount++;
        bufferIndex = 0;
      }
      if (c == '+'  c == '*' || c == '/') {
        tokens[tokenCount].type = OPERATOR;
        tokens[tokenCount].operator = c;
        tokenCount++;
      }
    }
  }

  if (bufferIndex > 0) {
    buffer[bufferIndex] = '\0';
    tokens[tokenCount].type = NUMBER;
    tokens[tokenCount].value = atof(buffer);
    tokenCount++;
  }

  return tokens;
}
// эта функция принимает указатель на строку, которая содержит математическое выражение, 
// и возвращает указатель на массив структур Token. 
// В каждой структуре Token записывается тип токена (число или оператор) и значение. 
// Для парсинга выражения используется буфер buffer,
//  в который сохраняются символы, соответствующие числу, и после этого они преобразу

void push(struct stack root, char* operation) {

}

char* pop(struct stack root) {

}
void init_operations(struct operation_struct *operations) {
    strcpy(operations->str, "(");
    operations->prior = 0;
    operations->type = LEFT_PAREN;

    strcpy(operation->str, ")");
    operations->prior = 1;
    operations->type = RIGHT_PAREN;

    strcpy(operation->str, "+");
    operations->prior = 2;
    operations->type = OPERATOR;

    strcpy(operation->str, "-");
    operations->prior = 2;
    operations->type = OPERATOR;

    strcpy(operation->str, "*");
    operations->prior = 3;
    operations->type = OPERATOR;

    strcpy(operation->str, "/");
    operations->prior = 3;
    operations->type = OPERATOR;

    strcpy(operation->str, "sin");
    operations->prior = 4;
    operations->type = OPERATOR;

    strcpy(operation->str, "cos");
    operations->prior = 4;
    operations->type = OPERATOR;

    strcpy(operation->str, "tan");
    operations->prior = 4;
    operations->type = OPERATOR;

    strcpy(operation->str, "ctg");
    operations->prior = 4;
    operations->type = OPERATOR;

    strcpy(operation->str, "sqrt");
    operations->prior = 4;
    operations->type = OPERATOR;

    strcpy(operation->str, "ln");
    operations->prior = 4;
    operations->type = OPERATOR;

}
