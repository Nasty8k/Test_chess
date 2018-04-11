#include "board_start.h"
#include "board_print_plain.h"
#include "board.h"
int main() {
    char deck[8][8];
    board_start(deck);
    while(1) {
        board_print_plain(deck);
        board(deck);
    }
}
