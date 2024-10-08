#include "get_next_line.h"

int main(int fd) {
    fd = open("hola.txt", O_RDONLY);
    read(fd);
    close(fd);
    return(0);
}