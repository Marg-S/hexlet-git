#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test(char *input, int length);
void s21_strcmp_test(char *input1, char *input2, int cmp);
void s21_strcpy_test(char *input1, char *input2);

int main() {
#ifdef LEN
    s21_strlen_test("Hello!", 6);
    s21_strlen_test("", 0);
    s21_strlen_test("012345[]{}()", 12);
#elif defined CMP
    s21_strcmp_test("Hello!", "Hello!", 0);
    s21_strcmp_test("Hello!", "Hello", 33);
    s21_strcmp_test("Hello!", "Hi!", -4);
    s21_strcmp_test("Hello!", "", 72);
#elif defined CPY
    char test_arr[10];// = {'\0'};
    s21_strcpy_test(test_arr, "Hello!");
#endif
    return 0;
}

void s21_strlen_test(char *input, int len) {
    int ret_strlen = s21_strlen(input);
    printf("%s\n%d\n%s", input, ret_strlen, len == ret_strlen ? "SUCCESS\n" : "FAIL\n");
}

void s21_strcmp_test(char *input1, char *input2, int cmp) {
    int ret_strcmp = s21_strcmp(input1, input2);
    printf("%s %s\n%d\n%s", input1, input2, ret_strcmp, cmp == ret_strcmp ? "SUCCESS\n" : "FAIL\n");
}

void s21_strcpy_test(char *input1, char *input2) {printf("%c",*input2);
    printf("TEST OF FUNCTION s21_strcpy >>> Input: \"%s", input1);
    char *ret_strcpy = s21_strcpy(input1, input2);
    int cpy = s21_strcmp(input1, input2);
    printf("\" \"%s\"\nOutput: %s", input2, ret_strcpy);
    printf("\nResult: %s", !cpy ? "SUCCESS\n" : "FAIL\n");
}
