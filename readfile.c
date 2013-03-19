#include <stdlib.h>
#include <stdio.h>

/* These snippets are not ready for serious use - they don't
 * handle failures (fopen, malloc, etc.). */

/**
 * Returns the size of the file in bytes.
 */
size_t file_size(char *path) {
    FILE* file = fopen(path, "r");
    fseek(file, 0, SEEK_END);
    size_t result = ftell(file);
    fclose(file);
    return result;
}

/**
 * Read a file into a C-string.
 */
char* file_read(char *path) {
    size_t buffer_size = file_size(path);
    char* buffer = malloc(buffer_size);
    FILE* file = fopen(path, "r");
    fread(buffer, buffer_size, 1, file);
    fclose(file);
    return buffer;
}

/* Does it work? */
int main(int argc, char** argv) {
    puts(file_read(argv[1]));
    return 0;
}
