#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

#define BUF_SIZE 32

int main(int argc, char* argv[])
{

    if (argc < 3) {
        printf("Usage: %s [source file] [destination file1] [destination file2] ...\n", argv[0]);
        exit(0);
    }


    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("Source file open failed");
        exit(1);
    }


    int num_files = argc - 2;
    int* dest_fd_list = (int*)malloc(sizeof(int) * num_files);

    for (int i = 0; i < num_files; i++) {
        dest_fd_list[i] = open(argv[i + 2],
                               O_WRONLY | O_CREAT | O_TRUNC,
                               S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

        if (dest_fd_list[i] == -1) {
            perror("Destination file open failed");
            close(src_fd);
            free(dest_fd_list);
            exit(1);
        }
    }


    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result;

    while (1) {

        read_result = read(src_fd, readStr, BUF_SIZE);

        if (read_result < 0) {
            perror("read failed");
            break;
        }

        if (read_result == 0) {
            printf("program end...\n");
            break;
        }

        write(STDOUT_FILENO, readStr, read_result);

        for (int i = 0; i < num_files; i++) {
            write(dest_fd_list[i], readStr, read_result);
        }
    }

    close(src_fd);
    for (int i = 0; i < num_files; i++) {
        close(dest_fd_list[i]);
    }

    free(readStr);
    free(dest_fd_list);

    return 0;
}
