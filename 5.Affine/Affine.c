#include <stdio.h>
#include <ctype.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
char encryptChar(int a, int b, char p) {
    if (isalpha(p)) {
        int base = isupper(p) ? 'A' : 'a';
        return (a * (p - base) + b) % 26 + base;
    }
    return p;
}
char decryptChar(int a, int b, char c) {
    if (isalpha(c)) {
        int base = isupper(c) ? 'A' : 'a';
        int a_inverse;
        for (a_inverse = 0; a_inverse < 26; a_inverse++) {
            if ((a * a_inverse) % 26 == 1)
                break;
        }
        return (a_inverse * ((c - base) - b + 26)) % 26 + base;
    }
    return c; 
}
void encrypt(int a, int b, char plaintext[]) {
    int i = 0;
    while (plaintext[i] != '\0') {
        plaintext[i] = encryptChar(a, b, plaintext[i]);
        i++;
    }
}
void decrypt(int a, int b, char ciphertext[]) {
    int i = 0;
    while (ciphertext[i] != '\0') {
        ciphertext[i] = decryptChar(a, b, ciphertext[i]);
        i++;
    }
}
int main() {
    char plaintext[1000];
    char ciphertext[1000];
    int a, b;
    printf("Enter the value of 'a' (must be relatively prime to 26): ");
    scanf("%d", &a);
    printf("Enter the value of 'b': ");
    scanf("%d", &b);
    if (gcd(a, 26) != 1) {
        printf("Error: 'a' must be relatively prime to 26 for one-to-one mapping.\n");
        return 1;
    }
    printf("Enter the plaintext: ");
    scanf(" %[^\n]s", plaintext);
    encrypt(a, b, plaintext);
    printf("Encrypted text: %s\n", plaintext);
    decrypt(a, b, plaintext);
    printf("Decrypted text: %s\n", plaintext);
    return 0;
}
