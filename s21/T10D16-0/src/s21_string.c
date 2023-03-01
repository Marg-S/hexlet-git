#include <stdio.h>

int s21_strlen(const char *str) {
    int length = 0;

    while (*(str + length)) length++;

    return length;
}

int s21_strcmp(char *str1, char *str2) {
    while (*str1 && *str1 == *str2) str1++, str2++;

    return *str1 - *str2;
}

char *s21_strcpy(char *str1, char *str2) {
//    char *p_str1 = str1, *p_str2 = str2;

//printf("<<%s> <%s>>", str2, str1);
//    char cpystr[len2 + 1];
//    *(cpystr + len2) = '\0';

    for (int i = 0; str2[i]; i++) str1[i] = str2[i];
//    str1[i] = '\0';
//printf("<|%s|>", str1);
    return str1;
}
