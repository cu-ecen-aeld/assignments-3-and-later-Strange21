#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void create_path(const char *path) {
    char *dirpath = strdup(path);
    if (dirpath == NULL) {
        perror("Failed to allocate memory");
        exit(1);
    }

    // Remove the filename from the path to create the directory path
    char *last_slash = strrchr(dirpath, '/');
    if (last_slash != NULL) {
        *last_slash = '\0';  // Set the slash to null terminator
    }

    // Create the directory path if it doesn't exist
    if (mkdir(dirpath, 0777) == -1 && errno != EEXIST) {
        perror("Failed to create directory path");
        free(dirpath);
        exit(1);
    }

    free(dirpath);
}

int main(int argc, char *argv[]) {
    // Ensure two arguments are passed: file path and string to write
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        exit(1);
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Create the directory path if needed
    // create_path(writefile);

    // Open the file for writing (create or overwrite)
    int fd = open(writefile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Failed to open file");
        exit(1);
    }

    // Write the string to the file
    ssize_t bytes_written = write(fd, writestr, strlen(writestr));
    if (bytes_written == -1) {
        perror("Failed to write to file");
        close(fd);
        exit(1);
    }

    // Close the file
    close(fd);

    return 0;
}
