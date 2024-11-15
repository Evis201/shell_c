// DO NOT TOUCH
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

// INPUT BUFFER SIZE
#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64


// FUNCTION TYPE DEFINITION
void readCommand(char *input) {
    printf("myshell> ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // RETIIRE CETTE PUTAIN DE RETOUR DE LIGNE
}

void analyseCommand(char *input, char **args) {
    int i = 0;
    args[i] = strtok(input, " ");
    while (args[i] != NULL && i < MAX_ARGS - 1) {
        i++;
        args[i] = strtok(NULL, " ");
    }
    args[i] = NULL; // Null terminate IMPORTANT POUR EXECVP
}

//


int start_bin(pid_t pid)
{
char * argv_list[] = {"hello","NULL","/bin",NULL};
}
