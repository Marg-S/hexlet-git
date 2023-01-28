<p><b>Если нужно быстро найти нужную команду:</b></p>
<a href="https://white55.ru/cmdmain.html">Шпаргалка по командам терминала</a><br>
<a href="https://about.gitlab.com/images/press/git-cheat-sheet.pdf" target="_blank">Шпаргалка по Гит-командам</a>
<br><br><p><b>Курсы (бесплатные):</b><p>
<a href="https://ru.hexlet.io/courses/cli-basics">Основы командной строки (Hexlet)</a><br>
<a href="https://ru.hexlet.io/courses/intro_to_git">Введение в Git (Hexlet)</a>

//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
#include <stdio.h>

#define HIGHT 25
#define WIDTH 80
#define CROSS_L 3
#define CROSS_R 76

#define SPACE ' '
#define CROSS 'X'
#define TOE '0'

void displ(int toe_pos_x, int toe_pos_y, int cross_left_pos, int cross_right_pos);

int main() {
    int cross_left_pos=13;
    int cross_right_pos=13;
    int toe_pos_x=40;
    int toe_pos_y=13;
//    char space=' ';
//    char cross='X';
//    char toe='0';
//system("raw -echo");
char c;
while(1) {
	//if(c=='a') 
    for(toe_pos_x=40; toe_pos_x<=80; toe_pos_x++) {
//c=getchar();
//	    if(c=='a') cross_left_pos++;
    displ(toe_pos_x, toe_pos_y, cross_left_pos, cross_right_pos);
    sleep(1);


    }


}


//system("stty sane");
}

void displ(int toe_pos_x, int toe_pos_y, int cross_left_pos, int cross_right_pos) {
printf("\e[1;1H\e[2J");
    for(int i=0; i<HIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            if(j==toe_pos_x && i==toe_pos_y) printf("%c",TOE);
	    else if((i==cross_left_pos || i==cross_left_pos-1 || i==cross_left_pos+1) && j==CROSS_L)
		    printf("%c",CROSS);
	    else if((i==cross_right_pos || i==cross_right_pos-1 || i==cross_right_pos+1) && j==CROSS_R)
                    printf("%c",CROSS);
	    else printf("%c",SPACE);
	}
	printf("\n");
    }


}

