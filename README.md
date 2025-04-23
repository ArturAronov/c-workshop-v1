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

| Binary   | Decimal Representation            | Decimal Value |
| -------- | --------------------------------- | ------------- |
| 00000000 | 0                                 | 0             |
| 00000001 | 0 + 2<sup>0</sup>                 | 1             |
| 00000010 | 0 + 2<sup>1</sup>                 | 2             |
| 00000011 | 0 + 2<sup>1</sup> + 2<sup>0</sup> | 3             |

- "Hello world" has 11 characters, hence it takes 11 bytes.

| Binary   | Decimal Representation                                                                            | Decimal Value | Character |
| -------- | ------------------------------------------------------------------------------------------------- | ------------- | --------- |
| 01101000 | 0 + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>3</sup>                                                 | 104           | h         |
| 01100101 | 0 + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>2</sup> + 2<sup>0</sup>                                 | 101           | e         |
| 01101100 | 0 + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>3</sup> + 2<sup>2</sup>                                 | 108           | l         |
| 01101100 | 0 + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>3</sup> + 2<sup>2</sup>                                 | 108           | l         |
| 01101111 | 0 + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> | 111           | o         |
| 00100000 | 0 + 2<sup>5</sup>                                                                                 | 32            | (space)   |
| 01110111 | 0 + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> | 119           | w         |
| 01101111 | 0 + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> | 111           | o         |
| 01110010 | 0 + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>3</sup> + 2<sup>1</sup>                                 | 114           | r         |
| 01101100 | 0 + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>3</sup> + 2<sup>2</sup>                                 | 108           | l         |
| 01100100 | 0 + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>2</sup>                                                 | 100           | d         |

- 11111111111111111111111111111111111111111111111111111111111111111111111111111111111 is a 77-bit binary number (since it has 77 digits)
  | Binary | Decimal Representation | Decimal Value |
  |-----------|--------------------------------------------------------|---------------|
  | 11111111 | 2<sup>7</sup> + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>4</sup> + 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> | 255 |
  | 11111111 | 2<sup>7</sup> + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>4</sup> + 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> | 255 |
  | 11111111 | 2<sup>7</sup> + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>4</sup> + 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> | 255 |
  | 11111111 | 2<sup>7</sup> + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>4</sup> + 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> | 255 |
  | 11111111 | 2<sup>7</sup> + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>4</sup> + 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> | 255 |
  | 11111111 | 2<sup>7</sup> + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>4</sup> + 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> | 255 |
  | 11111111 | 2<sup>7</sup> + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>4</sup> + 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> | 255 |
  | 11111111 | 2<sup>7</sup> + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>4</sup> + 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> | 255 |
  | 11111111 | 2<sup>7</sup> + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>4</sup> + 2<sup>3</sup> + 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> | 255 |
  | 11111000 | 2<sup>7</sup> + 2<sup>6</sup> + 2<sup>5</sup> + 2<sup>3</sup> | 248 |

- `write()` function takes in 3 integers  
  `write(1, "Hello World", 13);` gets converted to:  
  `write(1, 140732657256124, 13);`

  - 140732657256124 is a memory address in decimal form (0x7ffee3b6bc3c in hexadecimal).

- "Pointer" means "Memory Address"
- HTTP Responses  
   HTTP/1.1 200 OK
   <!doctype html></html>

  | Decimal | Character |
  | ------- | --------- |
  | 72      | H         |
  | 84      | T         |
  | 84      | T         |
  | 80      | P         |
  | 47      | /         |
  | 49      | 1         |
  | 46      | .         |
  | 49      | 1         |
  | 32      | (space)   |
  | 50      | 2         |
  | 48      | 0         |
  | 48      | 0         |
  | 32      | (space)   |
  | 79      | O         |
  | 75      | K         |
  | 0       |           |

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

- | Feature                | `char *test` / `char* test`          | `char test[]` / `char[] test`    |
  | ---------------------- | ------------------------------------ | -------------------------------- |
  | **Type**               | Pointer to a character               | Array of characters              |
  | **Memory Allocation**  | Pointer stores address of a string   | Array stores the full string     |
  | **Initialization**     | Points to a string literal           | Copies string literal into array |
  | **Re-assignability**   | Can point to a different string      | Cannot be reassigned             |
  | **String Mutability**  | Immutable (if pointing to a literal) | Mutable                          |
  | **Pointer Mutability** | Mutable                              | Immutable                        |
  | **Memory Location**    | Heap or read-only segment            | Stack or static memory           |
  | **Example**            | `char *test = "Hello";`              | `char test[] = "Hello";`         |

- `void *memcpy(void *dest, const void *src, size_t n);`
  - Parameters:
    - `dest`: Pointer to the destination memory where the content is to be copied
    - `src`: Pointer to the source memory from which the content is to be copied
    - `n`: Number of bytes to copy
  - Return value: A pointer to destination (`dest`);
