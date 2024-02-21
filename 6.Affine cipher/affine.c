#include <stdio.h>
#include <string.h>
int findModInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}
int main() {
    char ciphertext[] = "Helloeveryone";
    int freq[26] = {0}; 
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
            freq[ciphertext[i] - 'A']++;
    }  
    int maxFreqIndex = 0, secondMaxFreqIndex = 0;
    for (int i = 1; i < 26; i++) {
        if (freq[i] > freq[maxFreqIndex]) {
            secondMaxFreqIndex = maxFreqIndex;
            maxFreqIndex = i;
        } else if (freq[i] > freq[secondMaxFreqIndex] && i != maxFreqIndex) {
            secondMaxFreqIndex = i;
        }
    }
    int a = (maxFreqIndex - secondMaxFreqIndex + 26) % 26;
    int b = (ciphertext[maxFreqIndex] - 'A' - a * (ciphertext[secondMaxFreqIndex] - 'A')) % 26;
    if (b < 0)
        b += 26;
    int modInverse = findModInverse(a, 26);
    if (modInverse == -1) {
        printf("Modular inverse of key 'a' does not exist. Affine cipher cannot be decrypted.\n");
        return 0;
    }
    printf("Key: a = %d, b = %d\n", a, b);
    printf("Decrypted Text: ");
    for (int i = 0; i < len; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int x = (modInverse * (ciphertext[i] - 'A' - b + 26)) % 26;
            printf("%c", 'A' + x);
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
    return 0;
}