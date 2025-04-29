#include <string.h>
#include <stdio.h>

const char* DEFAULT_FILE = "index.html";

char* to_path(char* req) {
    // char* start = req;
    char *start, *end;

    for(start = req; start[0] != ' '; start++) {
        if(start[0] == '\0') return NULL;
    }

    start++;

    for(end = start; end[0] != ' '; end++){
        if(end[0] == '\0') return NULL;
    }

    if(end[-1] == '/') end--;
    else end[0] = '/';

    memcpy(end + 1, DEFAULT_FILE, strlen(DEFAULT_FILE) + 1);
    return start;
}

int main() {
    char req[] = "GET /blog HTTP/1.1...";
    char* path = to_path(req);
    printf("%s\n", path);

    return 0;
}
