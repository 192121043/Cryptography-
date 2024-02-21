#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char plaintext[], char key[]) {
    int i, j;
    int plaintextLen = strlen(plaintext);
    int keyLen = strlen(key);
    char encrypted[plaintextLen];
    for (i = 0, j = 0; i < plaintextLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;
        if (isupper(plaintext[i]))
            encrypted[i] = ((plaintext[i] - 'A' + key[j] - 'A') % 26) + 'A';
        else if (islower(plaintext[i]))
            encrypted[i] = ((plaintext[i] - 'a' + key[j] - 'A') % 26) + 'a';
        else
            encrypted[i] = plaintext[i];
    }
    encrypted[i] = '\0';
    printf("Encrypted text: %s\n", encrypted);
}
int main() {
    char plaintext[1000];
    char key[100];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    if (plaintext[strlen(plaintext) - 1] == '\n')
        plaintext[strlen(plaintext) - 1] = '\0';
    if (key[strlen(key) - 1] == '\n')
        key[strlen(key) - 1] = '\0';
    vigenereEncrypt(plaintext, key);
    return 0;
}