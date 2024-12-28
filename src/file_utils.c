#include "include/file_utils.h"

int file_exists(const char *filename) {
    if (access(filename, F_OK) != 0) {
        perror("Source file not found");
        return 0;
    }
    return 1;
}

int delete_file(const char *filename) {
    if (remove(filename) != 0) {
        perror("Error deleting file");
        return -1;
    }
    return 0;
}

int is_file(const char *path) {
    size_t len = strlen(path);

    if (len < 4) {
        return 1;
    }

    if (path[len - 4] == '.') {
        return 0; //is a file
    }

    return 1;
}