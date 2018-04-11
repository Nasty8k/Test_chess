#include "board_print_plain.h"
#include <stdio.h>

void board_print_plain(char deck[8][8]) {
    for (int number = 0; number < 8; ++number) {
        printf("%d|", 8 - number);
        for (int letter = 0; letter < 8; ++letter) {
	  printf("-");
            printf("%c|",deck[number][letter]);
        }
        printf("\n");
    }
    printf("   a  b  c  d  e  f  g  h\n\n");
}
