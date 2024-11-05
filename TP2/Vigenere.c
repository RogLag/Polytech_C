#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_letter(char c){
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
        return 1;
    }
    return 0;

}

char toLowerCase(char c){
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

void encrypt_1(char* message, const char* key, char vigenereTable[26][26]){
    int keyLength = strlen(key);
    int messageLength = strlen(message);
    int dodges = 0;
    for (int i=0;i<messageLength;i++){
        if (is_letter(message[i])==1){
            message[i] = vigenereTable[toLowerCase(key[(i-dodges)%keyLength])-'a'][toLowerCase(message[i])-'a'];
        }
        else{
            dodges++;
        }
    }
}

void decrypt_1(char* message, const char* key, char vigenereTable[26][26]){
    int keyLength = strlen(key);
    int messageLength = strlen(message);
    int dodges = 0;
    int j = 0;
    for (int i=0;i<messageLength;i++){
        if (is_letter(message[i])==1){
            while (vigenereTable[key[(i-dodges)%keyLength]-'a'][j] != message[i]){
                j++;
            }
            message[i] = 'a' + j;
            j=0;
        }
        else{
            dodges++;
        }
    }
}

void encrypt_2(char* message, const char* key, char** vigenereTable){
    int keyLength = strlen(key);
    int messageLength = strlen(message);
    int dodges = 0;
    for (int i=0;i<messageLength;i++){
        if (is_letter(message[i])==1){
            message[i] = vigenereTable[toLowerCase(key[(i-dodges)%keyLength])-'a'][toLowerCase(message[i])-'a'];
        }
        else{
            dodges++;
        }
    }
}

void decrypt_2(char* message, const char* key, char** vigenereTable){
    int keyLength = strlen(key);
    int messageLength = strlen(message);
    int dodges = 0;
    int j = 0;
    for (int i=0;i<messageLength;i++){
        if (is_letter(message[i])==1){
            while (vigenereTable[key[(i-dodges)%keyLength]-'a'][j] != message[i]){
                j++;
            }
            message[i] = 'a' + j;
            j=0;
        }
        else{
            dodges++;
        }
    }
}

void encrypt_3(char* message, const char* key) {
    int keyLength = strlen(key);
    int messageLength = strlen(message);
    int dodges = 0;
    for (int i = 0; i < messageLength; i++) {
        if (is_letter(message[i]) == 1) {
            char keyChar = toLowerCase(key[(i - dodges) % keyLength]) - 'a';
            char messageChar = toLowerCase(message[i]) - 'a';
            message[i] = 'a' + (keyChar + messageChar) % 26;
        } else {
            dodges++;
        }
    }
}

void decrypt_3(char* message, const char* key) {
    int keyLength = strlen(key);
    int messageLength = strlen(message);
    int dodges = 0;
    for (int i = 0; i < messageLength; i++) {
        if (is_letter(message[i]) == 1) {
            char keyChar = toLowerCase(key[(i - dodges) % keyLength]) - 'a';
            char messageChar = toLowerCase(message[i]) - 'a';
            message[i] = 'a' + (messageChar - keyChar + 26) % 26;
        } else {
            dodges++;
        }
    }
}

int main () {
    char message[] = "L'escargot se promene avec sa maison";
    const char* key = "perdu";
    char vigenereTable1[26][26];//non-dynamic allocation
    for (int i=0;i<26;i++){
        for (int j=0;j<26;j++){//first line should be the alphabet, then the second line should be the alphabet shifted by one, etc.
            vigenereTable1[i][j] = (char)('A' + (i+j)%26);
        }
    }
    char** vigenereTable2 = NULL;//dynamic allocation
    vigenereTable2 = (char**)malloc(26*sizeof(char*));
    for (int i=0;i<26;i++){
        vigenereTable2[i] = (char*)malloc(26*sizeof(char));
        for (int j=0;j<26;j++){
            vigenereTable2[i][j] = (char)('A' + (i+j)%26);
        }
    }
    encrypt_1(message, key, vigenereTable1);
    printf("encrypt1 : %s\n", message);
    decrypt_1(message, key, vigenereTable1);
    printf("decrypt1 : %s\n", message);
    encrypt_2(message, key, vigenereTable2);
    printf("encrypt2 : %s\n", message);
    decrypt_2(message, key, vigenereTable2);
    printf("decrypt2 : %s\n", message);
    encrypt_3(message, key);
    printf("encrypt2 : %s\n", message);
    decrypt_3(message, key);
    printf("decrypt2 : %s\n", message);
    return 0;
}