
#define PATH_MAX 4096
#include "/Users/buseokcu/CLionProjects/mv/include/move_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int is_directory(const char *path) {
    size_t len = strlen(path);

    if (len < 4) {
        return 1;
    }

    if (path[len - 4] == '.') {
        return 0; //is a file
    }

    return 1;
}

int move_file_to_directory(int argc, char *argv[]) {

    const char *destination = argv[argc - 1]; //dir= sondaki arguman

    int destination_is_dir = is_directory(destination);//kontrol

    if (argc < 3) {
        fprintf(stderr, "Error!At least three arguments must be provided.\n");
        return -1;
    }

    while (--argc > 1) { // tum argumanları (dir= son arguman haric) tek tek dire atiyoruz )
        //Döngü, program adı (argv[0]) ve son argüman (hedef, argv[argc - 1]) hariç diğer tüm argümanları işler.
        char *source = argv[argc - 1];
        char dest_path[1024];

        if (destination_is_dir) {

            snprintf(dest_path, sizeof(dest_path), "%s/%s", destination, strrchr(source, '/') ? strrchr(source, '/') + 1 : source);
        } else {
            // hedef dir değilse, dest_pathe ata
            strncpy(dest_path, destination, sizeof(dest_path));
        }

        // dest_pathe atadığın dosyayı dire taşı (rekursiv)
        if (move_file_to_directory(source, dest_path) != 0) {
            fprintf(stderr, "Error!\n", source);
        }
    }

    return 0;
}


