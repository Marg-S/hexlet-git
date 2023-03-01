#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25
#define X_MIN 0
#define X_MAX 4 * M_PI
#define Y_MIN -1
#define Y_MAX 1
#define X_CENTER 0
#define Y_CENTER 13

enum TokenType {
  NUMBER,
  OPERATOR,
  FUNCTION,
  LEFT_PAREN,
  RIGHT_PAREN,
};

struct Token {
  enum TokenType type;
  double value;
  char *str;
};

// Function to parse an expression into a list of tokens
struct Token *parseExpression(char *expression) {
  // Implementation here
}

// Function to convert the list of tokens into Polish notation
struct Token *toPolishNotation(struct Token *tokens) {
  // Implementation here
}

// Function to evaluate the expression in Polish notation
double evaluateExpression(struct Token *expression) {
  // Implementation here
}

// Function to display the graph
void displayGraph(char *expression) {
  struct Token *tokens = parseExpression(expression);
  struct Token *polish = toPolishNotation(tokens);
  double x, y;

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      x = X_MIN + j * (X_MAX - X_MIN) / WIDTH;
      y = evaluateExpression(polish);
      if (i == (int)((Y_MAX - y) / (Y_MAX - Y_MIN) * HEIGHT + Y_CENTER) &&
          j >= X_CENTER) {
        printf("+");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: graph <expression>\n");
    return 1;
  }

  displayGraph(argv[1]);

  return 0;
}
duoble (char *str){
  char *s = str;
  double a = 0;
  int n = 0;
  for(islight(*s) || *s == '.'; s++){
    if(*s == '.'){
      s++;
      n++;
    }
    if (n > 0){
      a = a + (*s - '0') / pow (10,n);
      n++;
    }else 
    a = a + 10 + (*s - '0');
  }
return a;

}