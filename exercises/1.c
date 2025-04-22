#include <stdio.h>
#include <unistd.h>

// 👉 First, build and run the program.
//
// To do this, make sure you're in the `exercises` directory, and then run:
//
// gcc -o app1 1.c && ./app1

int main() {
    // 👉 Try changing this string to "Hello, World!\n" - and also
    //    changing the length to 14.
    // 👉 Try making the length less than 14. What happens when you run the program?
    // 💡 If I change the length to 7, it will only print "Hello, %"

    // 👉 Try making the length much longer than 14, like 200. What happens? 😱
    // 💡 By changing the length to 70, the output becomes: 
    //    The numbers are: %d and %d
    //    `@@?@
    //          The numbers are: 42 and 69

    write(1, "Hello, World!\n", 14);

    // 👉 Try uncommenting the next 2 lines, as well as the #include <stdio.h> at the top.
    //    (You'll want to change the length of write() above back to 14 first!)
    // 👉 Try adding a second number, named num2. Set it to something other than 42.
    int num = 42;
    float num2 = 69;
    printf("The numbers are: %d and %f\n", num, num2);

    // 👉 Try having printf print *both* numbers.
    //    Hint: you'll need to make 2 changes to printf's arguments to do this!

    // 👉 Try returning something other than 0. (To see it, you'll need to run `echo $?`
    //    immediately after the program finishes running.)
    // 💡 returns the number I entered
    return 0;
}
