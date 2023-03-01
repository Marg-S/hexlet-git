#include "calculate.h"

#include "stack.h"

double calculate(char *expression) {
    struct stack *top = NULL;

    char *token = strtok(expression, " ");
    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            push(&stack, operand1 + operand2);
        } else if (strcmp(token, "-") == 0) {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            push(&stack, operand1 - operand2);
        } else if (strcmp(token, "*") == 0) {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            push(&stack, operand1 * operand2);
        } else if (strcmp(token, "/") == 0) {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            push(&stack, operand1 / operand2);
        } else if (strcmp(token, "sin") == 0) {
            double operand1 = pop(&stack);
            push(&stack, sin(operand1));
        } else if (strcmp(token, "cos") == 0) {
            double operand1 = pop(&stack);
            push(&stack, cos(operand1));
        } else if (strcmp(token, "tan") == 0) {
            double operand1 = pop(&stack);
            push(&stack, tan(operand1));
        } else if (strcmp(token, "ctg") == 0) {
            double operand1 = pop(&stack);
            push(&stack, ctg(operand1));
        } else if (strcmp(token, "sqrt") == 0) {
            double operand1 = pop(&stack);
            push(&stack, sqrt(operand1));
        } else if (strcmp(token, "ln") == 0) {
            double operand1 = pop(&stack);
            push(&stack, ln(operand1));
        } else {
            push(&stack, atof(token));
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}
