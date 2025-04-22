#include <stdio.h>

int main() {
    char *header = "HTTP/1.1 200 OK";
    size_t header_address = (size_t)header;
    printf("Header: %s\n", header);
    printf("Header address: %zu\n", header_address);

    return 0;
}