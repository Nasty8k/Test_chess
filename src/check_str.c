#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "board.h"

#define FREE container[pozition[3]][pozition[2]] == ' '

int check_str(int* pozition, char** container) {
    char i;
    i = tolower(container[pozition[1]][pozition[0]]);
    int k, f1, f2;
    int xy[8][2];
    xy[0][0] =  1; xy[0][1] = -2;
    xy[1][0] =  1; xy[1][1] =  2;
    xy[2][0] = -1; xy[2][1] = -2;
    xy[3][0] = -1; xy[3][1] =  2;
    xy[4][0] =  2; xy[4][1] = -1;
    xy[5][0] =  2; xy[5][1] =  1;
    xy[6][0] = -2; xy[6][1] =  1;
    xy[7][0] = -2; xy[7][1] = -1;
    switch (i) {
    case 'p':
        f1 = pozition[3] - pozition[1]; 
        f2 = pozition[2] - pozition[0];
        if (( ((pow( f1, 2 ) == 1) 
              || (pow( f1, 2 ) == 0)) 
                 || pow( f1, 2 ) == 4 ) && (f2 == 0 )) {
            if (FREE) {
                return 0;
            }
         }
         break;
    case 'n':
         for (k = 0; k <= 7; k++) {
            if (pozition[0] + xy[k][0] == pozition[2]) {
                if (pozition[1] + xy[k][1] == pozition[3]) {
                    if (FREE) {
                        return 0;
                    }
                }
            }
         }
         break;
    }
        
    return -1;   
}
