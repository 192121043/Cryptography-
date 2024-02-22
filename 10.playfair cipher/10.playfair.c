#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5
void prepareMatrix(char keySquare[SIZE][SIZE], char *key) {
    int i, j, k, flag = 0;
    int *exist = (int *)calloc(26, sizeof(int)); 
    for (i = 0; i < strlen(key); ++i) {
        if (key[i] == 'J')
            key[i] = 'I';
        if (exist[key[i] - 'A'] == 0) {
            keySquare[flag / SIZE][flag % SIZE] = key[i];
            exist[key[i] - 'A'] = 1;
            flag++;
        }
    }
    for (k = 0; k < 26; ++k) {
        if (exist[k] == 0) {
            keySquare[flag / SIZE][flag % SIZE] = 'A' + k;
            flag++;
        }
    }
    free(exist);
}
void findChar(char keySquare[SIZE][SIZE], char letter, int *row, int *col) {
    int i, j;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (keySquare[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encryptPlayfair(char keySquare[SIZE][SIZE], char *plaintext) {
    int i;
    int row1, col1, row2, col2;
    for (i = 0; i < strlen(plaintext); i++) {
        if (plaintext[i] == plaintext[i + 1]) {
            if (plaintext[i] != 'X')
                plaintext[i + 1] = 'X';
            else
                plaintext[i + 1] = 'Z';
        }
    }
    for (i = 0; i < strlen(plaintext); i += 2) {
        findChar(keySquare, plaintext[i], &row1, &col1);
        findChar(keySquare, plaintext[i + 1], &row2, &col2);
        if (row1 == row2) {
            printf("%c%c", keySquare[row1][(col1 + 1) % SIZE], keySquare[row2][(col2 + 1) % SIZE]);
        } else if (col1 == col2) {
            printf("%c%c", keySquare[(row1 + 1) % SIZE][col1], keySquare[(row2 + 1) % SIZE][col2]);
        } else {
            printf("%c%c", keySquare[row1][col2], keySquare[row2][col1]);
        }
    }
}
int main() {
    char keySquare[SIZE][SIZE];
    char key[] = "MFHIKUNOPQZVWXYELARGDSTBC";
    char plaintext[] = "MUSTSEEOVERCADOGANWESTCOMINGATONCE";
    prepareMatrix(keySquare, key);
    printf("Encrypted Message: ");
    encryptPlayfair(keySquare, plaintext);
    printf("\n");
    return 0;
}