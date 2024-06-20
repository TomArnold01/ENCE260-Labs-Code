#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

bool isWonRow(char player, const char game[3][3], uint8_t rowNum)
{
    for(size_t i=0; i<3; i ++) {
        if(game[rowNum][i] != player) {
            return false;
        }
    } 
    return true;
}

int main(void)
{
char game1[3][3] = {{'X', 'O', ' '},{'X', 'X', 'X'}, {' ', ' ', ' '}};
printf(isWonRow('X', game1, 1) ? "true\n" : "false\n"); 

const char game2[3][3] = {{'X', 'O', ' '},{' ', ' ', ' '}, {'X', 'X', 'O'}};
printf(isWonRow('X', game2, 2) ? "true\n" : "false\n"); 

const char game[3][3] = {{'X', 'X', 'X'},{' ', ' ', ' '}, {'O', 'O', 'O'}};
printf(isWonRow('O', game, 0) ? "true\n" : "false\n"); 
}