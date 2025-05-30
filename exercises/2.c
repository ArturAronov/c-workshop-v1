#include <unistd.h>
#include <stdio.h>
#include <string.h>

// 👉 First, build and run the program.
//
// To do this, make sure you're in the `exercises` directory, and then run:
//
// gcc -o app2 2.c && ./app2

int main() {
    char *header = "HTTP/1.1 200 OK";

    // 👉 Try replacing this `15` with a call to `strlen` (and `#include <string.h>` above!)
    // ✅
    write(1, header, strlen(header));

    // 👉 After you're using `strlen` above, try adding a `\0` (with the backslash)
    // inside the definition of `header`, e.g.  "HTT\0P/1.1 200 OK" - this inserts
    // a zero byte in the string. Before you run the program, what do you think it will print?
    // 💡 It only printed "HTT"

    // 👉 Try changing this `%s` to `%zu` (ignore the compiler warning).
    printf("\n\n");
    printf("That output was from write(). This is from printf: %s\n", header);
    printf("That output was from write(). This is from printf: %s\n", (char*)0);
    printf("That output was from write(). This is from printf: %s\n", (char*)42069);

    // 👉 Try changing the `%zu` back to `%s` and then replace the printf call's
    // last argument (originally `header`) with this argument instead: `(char*)123456`
    // 💡 Returns: HTTP/1.1 200 OK[1]    91355 segmentation fault  ./app2

    // 👉 Then try it with the number 0 instead of 123456.
    // 💡 Returns: That output was from write(). This is from printf: (null)

    return 0;
}
