#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define MAXLEN 2048
#define INTLEN 10
#define ASCII_LEN 128

void menu1(char *filename);
void menu2(char *filename);
void cesar(char *directory);
void encrypt(char *filename_ai, int shift);

int main() {
    int n = 0;
    char c[INTLEN], filename[MAXLEN];

    while (n != -1) {
        if ((n = atoi(fgets(c, INTLEN, stdin))) != 0) {
            switch (n) {
                case -1:
                    break;
                case 1:
                    fgets(filename, MAXLEN, stdin);
                    *(filename + strlen(filename) - 1) = '\0';
                    menu1(filename);
                    break;
                case 2:
                    menu2(filename);
                    break;
                case 3:
                    cesar("../src/ai_modules/");
                    break;
                default:
                    printf("n/a\n");
            }
        } else
            printf("n/a\n");
    }

    return 0;
}

void menu1(char *filename) {
    FILE *p_file = fopen(filename, "r");

    if (p_file != NULL) {
        char buffer[MAXLEN];
        if ((fgets(buffer, MAXLEN, p_file)) != NULL) {
            printf(buffer);
            while (fgets(buffer, MAXLEN, p_file)) printf(buffer);
            printf("\n");
        } else
            printf("n/a\n");
        fclose(p_file);
    } else
        printf("n/a\n");
}

void menu2(char *filename) {
    char buffer[MAXLEN];
    fgets(buffer, MAXLEN, stdin);

    if (filename != NULL) {
        FILE *p_file;
        if ((p_file = fopen(filename, "r+")) != NULL) {
            fseek(p_file, 0, SEEK_END);
            fprintf(p_file, buffer);

            fseek(p_file, 0, SEEK_SET);
            while (fgets(buffer, MAXLEN, p_file)) printf("%s", buffer);
            printf("\n");
            fclose(p_file);
        } else
            printf("n/a\n");
    } else
        printf("n/a\n");
}

void cesar(char *directory) {
    DIR *dir_ai = opendir(directory);
    char c[10], filename_ai[MAXLEN] = {'\0'};
    int shift = atoi(fgets(c, INTLEN, stdin));

    if (dir_ai && shift != 0) {
        struct dirent *file_ai;
        while ((file_ai = readdir(dir_ai)) != NULL) {
            strcpy(filename_ai, directory);
            strcat(filename_ai, file_ai->d_name);

            char last = *(file_ai->d_name + strlen(file_ai->d_name) - 1);
            char pin = *(file_ai->d_name + strlen(file_ai->d_name) - 2);

            if (strlen(file_ai->d_name) > 2 && last == 'h' && pin == '.') {
                FILE *p_file_ai = NULL;
                if ((p_file_ai = fopen(filename_ai, "w")) != NULL)
                    fclose(p_file_ai);
                else
                    printf("n/a\n");
            }

            if (strlen(file_ai->d_name) > 2 && last == 'c' && pin == '.') encrypt(filename_ai, shift);
        }
    } else
        printf("n/a\n");

    closedir(dir_ai);
}

void encrypt(char *filename_ai, int shift) {
    FILE *p_file_ai = fopen(filename_ai, "r+");
    if (p_file_ai != NULL) {
        char symbol;

        while ((symbol = fgetc(p_file_ai)) != EOF) {
            // if (symbol != '\n') {
            symbol = (symbol + shift + ASCII_LEN) % ASCII_LEN;
            fseek(p_file_ai, -1, SEEK_CUR);
            fputc(symbol, p_file_ai);
            // }
        }

        fclose(p_file_ai);
    } else
        printf("n/a");
}
