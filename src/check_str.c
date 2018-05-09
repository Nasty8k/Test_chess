#include "board_read.h"
#include <stdio.h>
#include <stdlib.h>

char *board_read() {
    char *str = calloc(7, sizeof(char));
    do {
    scanf("%6s", str);
    } while(str[0] < 'a' || str[0] > 'h'
        || str[1] < '0' || str[1] > '8'
        || str[2] != '-'
        || str[3] < 'a' || str[3] > 'h'
        || str[4] < '0' || str[4] > '9'
        || str[5] != '\0'
      );
    return str;
}
