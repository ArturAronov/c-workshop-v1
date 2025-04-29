#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
/*
    Total 144 bytes.

    struct stat {
        dev_t     st_dev;     // ID of device containing file //
        ino_t     st_ino;     // Inode number //
        mode_t    st_mode;    // File type and mode (permissions) //
        nlink_t   st_nlink;   // Number of hard links //
        uid_t     st_uid;     // User ID of owner //
        gid_t     st_gid;     // Group ID of owner //
        dev_t     st_rdev;    // Device ID (if special file) //
        off_t     st_size;    // Total size, in bytes //
        blksize_t st_blksize; // Block size for filesystem I/O //
        blkcnt_t  st_blocks;  // Number of 512B blocks allocated //

        // Time of last access //
        struct timespec st_atim;

        // Time of last modification //
        struct timespec st_mtim;

        // Time of last status change //
        struct timespec st_ctim;
    };
*/

int main() {
    struct stat metadata;
    int fd = open("../README.md", O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    if (fstat(fd, &metadata) == -1) {
        perror("Error getting file metadata");
        close(fd);
        return 1;
    }

    printf("File size: %d bytes\n", (int)metadata.st_size); // File size
    printf("File permissions: %o\n", metadata.st_mode & 0777); // File permissions
    printf("Last modified time: %ld\n", metadata.st_mtime); // Last modification time
    printf("Size of struct stat: %zu bytes\n", sizeof(struct stat));
    close(fd); // Close the file descriptor when done
    return 0;
}
