#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>
#include <limits.h>
#include "/Users/buseokcu/CLionProjects/mv/include/mv_file.h"

int mv_file(const char *source, const char *destination) {
    char dest_path[PATH_MAX];
    snprintf(dest_path, PATH_MAX, "%s/%s", destination, basename((char *)source));

    // Dosyayı taşımak için rename fonksiyonunu kullan
    if (rename(source, dest_path) != 0) {
        perror("rename");
        return 1; // Hata durumunda 1 döndür
    }
    return 0; // Başarılı bir şekilde taşındı
}