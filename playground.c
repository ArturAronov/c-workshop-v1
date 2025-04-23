#include <stdio.h>

char *to_path(char *req) {
    for(char *start  = req; start[0] != ' '; start++) {
        // start++: go up by one step in memory address

        if(start[0] == '\0') return NULL;
        // return null memory address

        // same as: if(start[0] == 0) return NULL;
        // same as: if(!start[0]) return NULL;
        printf("%s\n", start);
    }

    return " ";
  }

int main() {
  char *req = "GET /blog HTTP/1.1";
  char *path = to_path(req);

  int test = 42;
  int *test2 = &test;
  printf("test: %d \n", test);
  printf("test2: %d \n", test2);
  printf("test mem address: %p\n", test);
  printf("test2 mem address: %p\n", test2);
  test = 69;
  printf("===================\n");
  printf("test: %d \n", test);
  printf("test2: %d \n", test2);
  printf("test mem address: %p\n", test);
  printf("test2 mem address: %p\n", test2);
//   printf("%zu\n", *test);

  return 0;
}