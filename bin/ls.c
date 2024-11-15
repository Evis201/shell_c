#include<stdio.h>
#include<dirent.h>
#include <errno.h>
#include <stdlib.h>
// Define the struct with correct syntax
struct file_color {
    const char* Red;
    const char* Green;
    const char* Yellow;
    const char* Blue;
    const char* Purple;
};

// Function to initialize the structure with color codes
void init_colors(struct file_color* colors) {
    colors->Red = "\033[0;31m";
    colors->Green = "\033[0;32m";
    colors->Yellow = "\033[0;33m";
    colors->Blue = "\033[0;34m";
    colors->Purple = "\033[0;35m";
};
struct file
{
	struct file_color file_color;
	char name[];
};
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    DIR *path = opendir(argv[1]); // Open the directory specified in argv[1]
    if (!path) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    struct file_color color;
    init_colors(&color);
    while ((entry = readdir(path)) != NULL) { // Read each entry in the directory
       
//	   switch(entry->d_type)
//	   {
//		   case DT_REG:


//	   }
	    printf("Name: %s\n", entry->d_name);
    }

    closedir(path); // Close the directory
    return EXIT_SUCCESS;
}

