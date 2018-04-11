#include "board.h"
#include "board_read.h"
#include <string.h>
#include <stdlib.h>

void board(char deck[8][8]) {
    char input[6];
    while(1) {
        char *temp = board_read();
        strcpy(input, temp);
        free(temp);
        int move[] = {input[0]-'a', 8-(input[1]-'0'), input[3]-'a', 8-(input[4]-'0')};
        
        if (deck[move[1]][move[0]] == 'p' && ((move[2] == move[0] && deck[move[3]][move[2]] == ' ' &&
            (move[3] == move[1]+1 || (move[1] == 1 && move[3] == 3))) || (move[3] == move[1]+1 &&
            (move[2] == move[0]+1 || move[2] == move[0]-1) && deck[move[3]][move[2]]>='A' && deck[move[3]][move[2]]<='Z'))){
            deck[move[1]][move[0]] = ' ';
            deck[move[3]][move[2]] = 'p';
            break;
        }
        else if (deck[move[1]][move[0]] == 'P' && ((move[2] == move[0] && deck[move[3]][move[2]] == ' ' &&
            (move[3] == move[1]-1 || (move[1] == 6 && move[3] == 4))) || (move[3] == move[1]-1 &&
            (move[2] == move[0]+1 || move[2] == move[0]-1) && deck[move[3]][move[2]]>='a' && deck[move[3]][move[2]]<='z'))){
            deck[move[1]][move[0]] = ' ';
            deck[move[3]][move[2]] = 'P';
            break;
        }
    }
}

