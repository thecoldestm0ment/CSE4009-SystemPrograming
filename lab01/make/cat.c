#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 2048

static void do_cat(const char *path);
static void die(const char *s);

int main(int argc, char *argv[])
{
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file> [file ...]\n", argv[0]);
        exit(1);
    }
    // for문으로 여러 파일 처리
    for (i = 1; i < argc; i++) {
        do_cat(argv[i]);
    }

    exit(0);
}

static void do_cat(const char *path)
{
    int fd, n;
    unsigned char buf[BUF_SIZE];

    fd = open(path, O_RDONLY);
    if (fd < 0) { 
        die(path);
    }

    
    while ((n = read(fd, buf, sizeof(buf))) > 0) { // n: read()가 읽은 바이트 수
        ssize_t written = 0;

        while (written < n) {
            ssize_t result = write(STDOUT_FILENO, buf + written, n - written);

            if (result < 0) {
                close(fd);
                die("write");
            }
            written += result;
        }
    }

    if (n < 0) { // read()가 실패한 경우
        close(fd);
        die("read");
    }

    if (close(fd) < 0) { 
        die("close");
    }
}

static void die(const char *s)
{
    perror(s);
    exit(1);
}
