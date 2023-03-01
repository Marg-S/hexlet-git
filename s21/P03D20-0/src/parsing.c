#include "parsing.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"
#include "stack.h"

void parsing(char *str, struct word *operations, char *str_output) {
    struct stack *top = NULL;
    struct queue *first = NULL, *last = NULL;

    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9' || str[i] == 'x') {
            // //-----------------------------------------------------------
            // printf("pars: %c\n", str[i]);
            // //-----------------------------------------------------------

            str_output[j++] = str[i];
            if (str[i + 1] < '0' || str[i + 1] > '9') str_output[j++] = ' ';
            /*while ((str[++i] >= '0' && str[i] <= '9') || str[i] == '.') {
                str_output[j++] = str[i];
            }

            i--;*/
        }  // else if (str[i] == 's' && str[i+1] == 'i' && str[i+2])

        else if ((str[i] >= 'a' && str[i] <= 'z')) {
            // if (str[i] == 's')
            char temp_str[LEN];
            int k = 0;
            temp_str[k++] = str[i];
            while (str[++i] >= 'a' && str[i] <= 'z') {
                temp_str[k++] = str[i];
            }
            temp_str[k] = '\0';
            i--;
            struct word *p = find_word(operations, temp_str);

            if (p) push(&top, p);
        } else if (str[i] == '(') {
            char temp_str[LEN];
            temp_str[0] = str[i];
            temp_str[1] = '\0';
            struct word *p = find_word(operations, temp_str);
            push(&top, p);

        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            char temp_str[LEN];
            temp_str[0] = str[i];
            temp_str[1] = '\0';
            struct word *p = find_word(operations, temp_str);

            if (top && (top->operation)->value < p->value) {
                while (top && (top->operation)->value < p->value) {
                    push_q(pop(&top), &last, &first);
                }
                push(&top, p);
                while (first) push(&top, pop_q(&first));

            } else
                push(&top, p);

        } else if (str[i] == ')') {
            while (top && ((top->operation)->str)[0] != '(') {
                struct word *op = pop(&top);
                str_output[j] = '\0';

                strcat(str_output, op->str);
                j += strlen(op->str);
                str_output[j++] = ' ';
            }
            if (top) {
                pop(&top);
                if ((top->operation)->type == FUNCTION) {
                    struct word *op = pop(&top);
                    str_output[j] = '\0';

                    strcat(str_output, op->str);
                    j += strlen(op->str);
                    str_output[j++] = ' ';
                }
            } else {
                printf("Error in expression");
                exit(1);
            }
        }
    }
    while (top != NULL) {
        struct word *op = pop(&top);
        str_output[j] = '\0';
        strcat(str_output, op->str);
        j += strlen(op->str);
        str_output[j++] = ' ';
    }
    str_output[j] = '\0';
}