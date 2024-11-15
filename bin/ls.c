#include<stdio.h>
#include<dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
// Define the struct with correct syntax
struct file_color {
    const char* Red;
    const char* Green;
    const char* Yellow;
    const char* Blue;
    const char* Purple;
    const char* Reset;
};

// Function to initialize the structure with color codes
void init_colors(struct file_color* colors) {
    colors->Red = "\033[0;31m";
    colors->Green = "\033[0;32m";
    colors->Yellow = "\033[0;33m";
    colors->Blue = "\033[0;34m";
    colors->Purple = "\033[0;35m";
    colors->Reset = "\033[0m";
};
struct file
{
	struct file_color file_color;
	char name[];
};

const char* get_extension(const char* filename) {
    const char* ext = strrchr(filename, '.');  // Find the last occurrence of '.' in the filename
    if (ext != NULL) {
        return ext + 1;  // Return the extension (skip the dot)
    }
    return "";  // No extension
}
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
        // Get file extension
        const char* ext = get_extension(entry->d_name);

        char buffer[256];  // Buffer to hold the final string to print

        if (entry->d_type == DT_REG) {  // Regular file
            // Check the file extension and assign color
            if (strcmp(ext, "py") == 0) {
                snprintf(buffer, sizeof(buffer), "%s%s 🐍%s", color.Green, entry->d_name, color.Reset);
                printf("%s\n", buffer);
            } else if (strcmp(ext, "c") == 0) {
                snprintf(buffer, sizeof(buffer), "%s%s 🇨%s", color.Blue, entry->d_name, color.Reset);
                printf("%s\n", buffer);
            } else if (strcmp(ext, "txt") == 0) {
                snprintf(buffer, sizeof(buffer), "%s%s 📄%s", color.Yellow, entry->d_name, color.Reset);
                printf("%s\n", buffer);
            } else {
                snprintf(buffer, sizeof(buffer), "%s%s 🔍%s", color.Purple, entry->d_name, color.Reset);
                printf("%s\n", buffer);
            }
        } else if (entry->d_type == DT_DIR) {  // Directory
            snprintf(buffer, sizeof(buffer), "%s%s 📁%s", color.Blue, entry->d_name, color.Reset);
            printf("%s\n", buffer);
        } else if (entry->d_type == DT_LNK) {  // Symbolic link
            snprintf(buffer, sizeof(buffer), "%s%s 🔗%s", color.Purple, entry->d_name, color.Reset);
            printf("%s\n", buffer);
        } else {
            snprintf(buffer, sizeof(buffer), "%s%s ❓%s", color.Reset, entry->d_name, color.Reset);
            printf("%s\n", buffer);
        }
    }

    closedir(path); // Close the directory
    return EXIT_SUCCESS;
}

