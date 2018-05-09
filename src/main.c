#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "board.h"

char places[6];
int end = 0;

int main() {
    system("clear");
    reprint_board();
    while (end == 0) {
        printf("   перезапуск (!)  выход (#)\n\n");
        printf("Введите ход фигуры формата <Место-Новое_место>\nПример: a2-a4 a7-a6\n"
        "-> ХОД: ");
        scanf("%s", places);
       
        if (places[0] == '!') {
            system("clear");
            end = 1;
            main();
        } else if (places[0] == '#') {
            system("clear");
            return 0;
        }
        system("clear");
        end = board_func(places, 0);
        if (end == -1) {
            print_board();
            if (places[0] != '!') {
                printf("\n--> Неправильный ход!");
            }
            end = 0;
        }
   }
    return 0;
}
