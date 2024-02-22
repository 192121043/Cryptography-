#include <stdio.h>
#include <string.h>
#include <ctype.h>
void generateCipherSequence(char *keyword, char *cipherSequence) {
    int i, j, index = 0;
    int used[26] = {0};
    strcpy(cipherSequence, keyword);
    index = strlen(keyword);
     for (i = 0; i < index; i++) {
        if (isalpha(keyword[i])) {
            used[toupper(keyword[i]) - 'A'] = 1;
        }
    }
    for (i = 0; i < 26; i++) {
        if (!used[i]) {
            cipherSequence[index++] = 'A' + i;
        }
    }
    cipherSequence[index] = '\0';
}
char encrypt(char ch, char *cipherSequence) {
    if (isalpha(ch)) {
        if (islower(ch)) {
            return tolower(cipherSequence[ch - 'a']);
        } else {
            return cipherSequence[ch - 'A'];
        }
    } else {
        return ch;
    }
}
char decrypt(char ch, char *cipherSequence) {
    int i;
    if (isalpha(ch)) {
        for (i = 0; i < 26; i++) {
            if (tolower(ch) == tolower(cipherSequence[i])) {
                if (islower(ch)) {
                    return 'a' + i;
                } else {
                    return 'A' + i;
                }
            }
        }
    }
    return ch;
}
int main() {
    char keyword[] = "SMS";
    char plaintext[] = "VALO";
    char cipherSequence[27];
    char ciphertext[100], decryptedText[100];  
    generateCipherSequence(keyword, cipherSequence);
    printf("Cipher Sequence: %s\n", cipherSequence);
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = encrypt(plaintext[i], cipherSequence);
    }
    ciphertext[i] = '\0';
    printf("Encrypted Text: %s\n", ciphertext);
    for (i = 0; i < strlen(ciphertext); i++) {
        decryptedText[i] = decrypt(ciphertext[i], cipherSequence);
    }
    decryptedText[i] = '\0';
    printf("Decrypted Text: %s\n", decryptedText);
    return 0;
}