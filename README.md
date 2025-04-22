# C Fundamentals Workshop

Welcome!

There are [slides for this workshop](https://docs.google.com/presentation/d/1CGtDVSazrJHI52OnwwJXgogQEHs63lrasfQWJvmcYM0/edit?usp=sharing) which reference the exercises in this repo.

# Setup Instructions

For this workshop, you'll need to be running one of these operating systems:

- macOS
- Linux, BSD, or another UNIX variant
- [Linux Subsystem for Windows](https://learn.microsoft.com/en-us/windows/wsl/install) (regular Windows will _not_ work for this workshop!)

Any of these operating systems should have everything you need already installed.

To verify this, clone this repository, then run the following terminal command in the root directory where you checked out the repo:

```
gcc -o verify verify.c && ./verify
```

It should print "You're all set!"

## Troubleshooting

If running that command didn't print "You're all set!", you'll need to install either
[GCC](https://gcc.gnu.org/) or [Clang](https://clang.llvm.org/) -
either will work fine, so choose whichever you think will be
easier to install.

These exercises all say to run `gcc`, but you can subsitute `clang` for `gcc` and
it should always work in the case of these examples; `clang` and `gcc` accept
almost identical CLI flags.

Fun fact: macOS actually ships with `clang` but aliases it to `gcc`, so if you run
`gcc --version` on macOS, it prints out `Apple clang version ___`.

## Notes

00000000000000100000001000000011  
(grouped by bytes - 8) ⤵️

```
+==========+==========+==========+===============+
| 00000000 | 00000001 | 00000010 | 00000011      |
+==========+==========+==========+===============+
|    0     |  0 + 2^0 |  0 + 2^1 | 0 + 2^1 + 2^0 |
+==========+==========+==========+===============+
|    0     |     1    |     2    |      3        |
+==========+==========+==========+===============+
```

- "Hello world" has 11 characters, hence it takes 11 bytes.

```
  +==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+
  | 01101000 | 01100101 | 01101100 | 01101100 | 01101111 | 00100000 | 01110111 | 01101111 | 01110010 | 01101100 | 01100100 |
  +==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+
  | 0 + 2^6 + 2^5 + 2^3 | 0 + 2^6 + 2^5 + 2^2 + 2^0 | 0 + 2^6 + 2^5 + 2^3 + 2^2 | 0 + 2^6 + 2^5 + 2^3 + 2^2 | 0 + 2^6 + 2^5 + 2^3 + 2^2 + 2^1 + 2^0 | 0 + 2^5 | 0 + 2^6 + 2^5 + 2^3 + 2^2 + 2^1 + 2^0 | 0 + 2^6 + 2^5 + 2^3 + 2^2 + 2^1 + 2^0 | 0 + 2^6 + 2^5 + 2^3 + 2^1 | 0 + 2^6 + 2^5 + 2^3 + 2^2 | 0 + 2^6 + 2^5 + 2^2 |
  +==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+
  | 104       | 101       | 108       | 108       | 111       | 32        | 119       | 111       | 114       | 108       | 100       |
  +==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+
  | h         | e         | l         | l         | o         | (space)   | w         | o         | r         | l         | d         |
  +==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+
```

- 11111111111111111111111111111111111111111111111111111111111111111111111111111111111 is a 77-bit binary number (since it has 77 digits)
  +==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+
  | 11111111 | 11111111 | 11111111 | 11111111 | 11111111 | 11111111 | 11111111 | 11111111 | 11111111 | 11111000 |
  +==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+
  | 2^7+2^6+2^5+2^4+2^3+2^2+2^1+2^0 | 2^7+2^6+2^5+2^4+2^3+2^2+2^1+2^0 | 2^7+2^6+2^5+2^4+2^3+2^2+2^1+2^0 | 2^7+2^6+2^5+2^4+2^3+2^2+2^1+2^0 | 2^7+2^6+2^5+2^4+2^3+2^2+2^1+2^0 | 2^7+2^6+2^5+2^4+2^3+2^2+2^1+2^0 | 2^7+2^6+2^5+2^4+2^3+2^2+2^1+2^0 | 2^7+2^6+2^5+2^4+2^3+2^2+2^1+2^0 | 2^7+2^6+2^5+2^4+2^3+2^2+2^1+2^0 | 2^7+2^6+2^5+2^3 |
  +==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+
  | 255 | 255 | 255 | 255 | 255 | 255 | 255 | 255 | 255 | 248 |
  +==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+

- `write()` function takes in 3 integers  
  `write(1, "Hello World", 13);` gets converted to:  
  `write(1, 140732657256124, 13);`

  - 140732657256124 is a memory address in decimal form (0x7ffee3b6bc3c in hexadecimal).

- "Pointer" means "Memory Address"
- HTTP Responses  
   HTTP/1.1 200 OK
   <!doctype html></html>

  +==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+
  | 72 | 84 | 84 | 80 | 47 | 49 | 46 | 49 | 32 | 50 | 48 | 48 | 32 | 79 | 75 | 0 |
  +==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+
  | H | T | T | P | / | 1 | . | 1 | (space) | 2 | 0 | 0 | (space) | O | K | |
  +==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+==========+
  0 byte at the is an null terminator.  
  When working with strings in C, a null terminator (a 0 byte, represented as \0 in C) is always implicitly added at the end of strings to indicate the end of the string. Without this null terminator, the string wouldn't be properly terminated in memory.

  `char *header = "HTTP/1.1 200 OK";` this means:  
  "address of a byte" (**char** means "byte")  
  aka "pointer to a byte" ("pointer" means "memory address")  
  in memory, **header** is an integer  
  (namely, the memory address of the first byte in the array)  
  `char *header = 415325`  
  `write(1, 415325, 15)`  
  415325 is a memory address

  ```
  include <stdio.h>
  include <string.h>

  int main() {
      char *header = "HTTP/1.1 200 OK";
      // remember, header in printf is just an number that points to memory address where it's stored
      printf("Header: %s", header);
      // or
      write(1, header, strlen(header));

      return 0;
  }
  ```

  if you want to see actual memory address where the `header` is stored:  
  `printf("Header: %zud", header)`

  ```
  #include <stdio.h>

  int main() {
      char *header = "HTTP/1.1 200 OK";
      size_t header_address = (size_t)header;
      printf("Header: %s\n", header);
      printf("Header address: %zu\n", header_address);

      return 0;
  }
  ```
