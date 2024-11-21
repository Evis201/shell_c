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
    input[strcspn(input, "\n")] = 0; // RETIRE CETTE PUTAIN DE RETOUR DE LIGNE
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

void changeDirectory(char **args) {  // CD FUNCTION
    if (args[1] == NULL) {
        fprintf(stderr, "cd: expected argument\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("cd");
        }
    }
}

//

int start_bin(pid_t pid)
{
char * argv_list[] = {"hello","NULL","/bin",NULL};
}

// MAIN FUNCTION
void main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARGS];

    while (1) {
        readCommand(input);
        analyseCommand(input, args);

        if (args[0] == NULL) {
            continue;
        }

        if (strcmp(args[0], "cd") == 0) {
            changeDirectory(args);
        } else {
            // FORKING
        }
    }

    return 0;
}
