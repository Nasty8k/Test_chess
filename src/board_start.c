#include "board_start.h"

void board_start(char deck[8][8]) {
    char letters[]={'r','n', 'b', 'q', 'k', 'b', 'n', 'r'};
    for (int letter = 0; letter < 8; ++letter) {
        deck[0][letter] = letters[letter];
        deck[7][letter] = letters[letter]-32;
        deck[1][letter] = 'p';
        deck[6][letter] = 'p'-32;
        for (int i = 2; i < 6; ++i) {
            deck[i][letter] = ' ';
        }
    }
}
