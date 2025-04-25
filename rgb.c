#include "rgb.h"
#include <stdio.h>

void get_k_pixels(unsigned char ImageN[], unsigned char LBits[], int k, int tam){
     
    unsigned char kBit = (1 << k) -1;

    printf("Normalizando...\n");

    for ( int i = 0; i < tam; i++)
    {
        LBits[i] = ImageN[i] & kBit;
    };

    printf("Normalizando!\n");
    
};

void decrypt_message(unsigned char LBits[], char messageOut[], int k, int tamLBits, int tamMessage) {
    int bit = 0;
    unsigned char eightBits = 0;
    int count = 7;
    int charIndex = 0;

    printf("Decifrando...\n");

    for (int i = 0; i < tamLBits; i++) {

        for (int j = k - 1; j >= 0; j--) {
            
            bit = (LBits[i] >> j) & 1;
            eightBits |= (bit << count);
            count--;

            if (count < 0) {
                messageOut[charIndex++] = eightBits;
                eightBits = 0;
                count = 7;

                if (charIndex >= tamMessage) {
                    return;
                }
            }
        }
    }
}