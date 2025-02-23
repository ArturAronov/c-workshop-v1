#include <string.h>
#include <stdio.h>

// To build and attempt to run the program: (it will give an error at first!)
//
// cc -o app3 3.c && ./app3

const char* DEFAULT_FILE = "index.html";

char *to_path(char *req) {
    char *start, *end;

    // Advance `start` to the first space
    for (start = req; start[0] != ' '; start++) {
        if (!start[0]) {
            return NULL;
        }
    }

    start++; // Skip over the space

    // Advance `end` to the second space
    for (end = start; end[0] != ' '; end++) {
        if (!end[0]) {
            return NULL;
        }
    }

    // Ensure there's a '/' right before where we're about to copy in "index.html"
    if (end[-1] == '/') {
        end--;
    } else {
        end[0] = '/';
    }

    // Copy in "index.html", overwriting whatever was there in the request string.
    memcpy(end + 1, DEFAULT_FILE, strlen(DEFAULT_FILE) + 1);

    return start;
}

int main() {
    // 👉 This doesn't currently trim off the leading '/' - modify to_path to fix this!
    char req1[] = "GET /blog HTTP/1.1\nHost: example.com";
    printf("Should be \"blog/index.html\": \"%s\"\n", to_path(req1));

    char req2[] = "GET /blog/ HTTP/1.1\nHost: example.com";
    printf("Should be \"blog/index.html\": \"%s\"\n", to_path(req2));

    // 👉 Make sure this case works (when the request is for "/", return "index.html")
    char req3[] = "GET / HTTP/1.1\nHost: example.com";
    printf("Should be \"index.html\": \"%s\"\n", to_path(req3));

    // 👉 Before fixing this next one, try moving it up to the beginning of main().
    //    What happens?

    // 👉 Next, fix it by handling the case where `req` is too short to
    //    have "index.html" memcpy'd into it.
    //    Hint: to_path() will need to take a second argument!
    char req4[] = "GET /blog ";
    printf("Should be \"(null)\": \"%s\"\n", to_path(req4));

    return 0;
}
