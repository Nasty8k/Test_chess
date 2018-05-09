#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "check_str.h"
#include "board.h"

    char **pole;
    char **_board() {
    int i,j;
    
    pole = (char**)malloc(8 * sizeof(char*));
    for(i = 0; i < 8; i++) {
        pole[i] = (char*)malloc(8 * sizeof(char));
        for(j = 0; j < 8; j++) {
            pole[i][j] = ' ';
        }
    }
    char figure_black[] = "rnbqkbnr";
    char figure_white[] = "RNBQKBNR";

    for(i = 0; i < 8; i++) {
        pole[0][i] = figure_black[i];
        pole[7][i] = figure_white[i];
        pole[1][i] = 'p';
        pole[6][i] = 'P';
    }    
    return pole; 
}

void reprint_board() {
    pole = _board();
    print_board(pole);
}

void print_board() {
    system("clear");
    printf("\n  ");
    for (char ch = 'a'; ch <= 'h'; ch++) {
         printf("  %c", ch);
    }
    printf("\n   ────────────────────────\n");
    for(int i = 0; i < 8; i++) {
    
        printf(" %d|", 8 - i);
        
        for(int j = 0; j < 8; j++) {
            printf("[%c]", pole[i][j]);
        }
        printf("|\n");
                
    }
    printf("   ────────────────────────\n  ");
    for(char ch = 'a'; ch <= 'h'; ch++) {
        printf("  %c", ch);
    }
    printf("\n");
}

char** movePawn(char **v, int* cord) { 
    int poz = pole[cord[1]][cord[0]];
    pole[cord[1]][cord[0]] = pole[cord[3]][cord[2]];
    pole[cord[3]][cord[2]] = poz;
    return v;
}

int board_func(char *places, int test) {
    if (strlen(places) != 5) {
        return -1;
    }
    int cord[4];
    cord[0] = places[0] - 97;
    cord[1] = 8 - (places[1] - 48);
    cord[2] = places[3] - 97;
    cord[3] = 8 - (places[4] - 48);
    printf("\n ");
    int err = check_str(cord, pole);
    if (err == -1) return -1;

    for(int g = 0; g < 4; g++) {
        if (cord[g] < 0 || cord[g] > 8) {
            return -1;
        }
    }
    pole = movePawn(pole, cord);
    if (test == 0) print_board(pole);
    return 0;
}
