#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_EXPR_SIZE 100

struct Stack {
  int top;
  double items[MAX_EXPR_SIZE];
};

void push(struct Stack *stack, double value) {
  stack->items[++stack->top] = value;
}

double pop(struct Stack *stack) {
  return stack->items[stack->top--];
}

int is_empty(struct Stack *stack) {
  return stack->top == -1;
}

double calculate(char* expression) {
  struct stack top = NULL;
  char *token = strtok(expression, " ");
  while (token != NULL) {
    if (strcmp(token, "+") == 0) {
      double operand2 = pop(&top);
      double operand1 = pop(&top);
      push(&top, operand1 + operand2);
    } else if (strcmp(token, "-") == 0) {
      double operand2 = pop(&top);
      double operand1 = pop(&top);
      push(&top, operand1 - operand2);
    } else if (strcmp(token, "*") == 0) {
      double operand2 = pop(&top);
      double operand1 = pop(&top);
      push(&top, operand1 * operand2);
    } else if (strcmp(token, "/") == 0) {
      double operand2 = pop(&top);
      double operand1 = pop(&top);
      push(&top, operand1 / operand2);
    } else if (strcmp(token, "sin") == 0) {
      double operand1 = pop(&top);
      push(&top, sin(operand1));
    } else if (strcmp(token, "cos") == 0) {
      double operand1 = pop(&top);
      push(&top, cos(operand1));
    } else if (strcmp(token, "tan") == 0) {
      double operand1 = pop(&top);
      push(&top, tan(operand1));
    } else if (strcmp(token, "ctg") == 0) {
      double operand1 = pop(&top);
      push(&top, ctg(operand1));
    } else if (strcmp(token, "sqrt") == 0) {
      double operand1 = pop(&top);
      push(&top, sqrt(operand1));
    } else if (strcmp(token, "ln") == 0) {
      double operand1 = pop(&top);
      push(&top, ln(operand1));
    } else {
      push(&top, atof(token));
    }
    token = strtok(NULL, " ");
  }
  return pop(&top);
}
