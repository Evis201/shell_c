// DO NOT TOUCH
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// INPUT BUFFER SIZE
#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

// FUNCTION PROTOTYPES
void lireCommande(char *input) {
    printf("myshell> ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;
}

