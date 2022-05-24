#include "plotting.h"
#include "calc.h"
void plotting(Lexeme* input_lex) {
  char matrix[HEIGHT][WIDTH];
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      matrix[i][j] = '.';
    }
  }
  double interval = (double)2 / (double)HEIGHT;
  for (int i = 0; i < WIDTH; i++) {
    double tmp = ((4 * M_PI / WIDTH) * i);
    double y = read_parced(input_lex,tmp) + 1;
    for (int j = 0; j < HEIGHT; j++) {
      if ((y >= (j)*interval) && (y <= (j + 1) * interval)) {
        matrix[j][i] = '#';
      }
    }
  }
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }
}
