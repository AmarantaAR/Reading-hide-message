#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rgb.h"

int main()
{
    int k, pixels;
    int i = 0;

    printf("Por favor indica cuantos pixeles tiene tu imagen:\n");
    scanf("%d", &pixels);
    printf("Por favor indica cuantos bits están escondidos:\n");
    scanf("%d", &k);

    int tamLBits = 3 * pixels;
    int tamMessage = (tamLBits * k) / 8;

    unsigned char *ImageIn = calloc(tamLBits, sizeof(unsigned char));
    unsigned char *LBits = calloc(tamLBits, sizeof(unsigned char));
    char *messageOut = calloc(tamMessage, sizeof(char));

    getchar(); // Limpiar buffer antes de fgets

    printf("Ingresa exactamente %d valores HEX separados por espacio:\n", tamLBits);

    char buffer[2048];
    fgets(buffer, sizeof(buffer), stdin);

    char *token = strtok(buffer, " \n");
    while (token != NULL && i < tamLBits)
    {
        sscanf(token, "%x", &ImageIn[i]);
        i++;
        token = strtok(NULL, " \n");
    }

    if (i < tamLBits)
    {
        printf("Advertencia: Ingresaste menos de %d valores. Vuelve a correr el programa.\n", tamLBits);
        return 0;
    }


    printf("Has ingresado estos %d valores:\n", i);
    for (int j = 0; j < i; j++)
    {
        printf("%X ", ImageIn[j]);
    }
    printf("\n");

    get_k_pixels(ImageIn,LBits, k, tamLBits);

    decrypt_message(LBits,messageOut, k, tamLBits, tamMessage);

    printf("Este es el mensaje:\n");
    for (int j = 0; j < tamMessage; j++)
    {
        printf("%c", messageOut[j]);
    }
    printf("\n");

    free(ImageIn); //Clean up memory ;)
    free(LBits);
    free(messageOut);

    return 0;
}
