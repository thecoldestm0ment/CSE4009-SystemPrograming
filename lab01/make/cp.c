#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 2048
#define PERM 0644

static void do_copy(const char *src, const char *des);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(1);
    }

    do_copy(argv[1], argv[2]); // 소스 파일 argv[1]을 목적지 파일 argv[2]로 복사
    exit(0);
}

static void do_copy(const char *src, const char *des)
{
    int fd_src, fd_des, nread;
    unsigned char buf[BUF_SIZE];
    // 소스 파일을 읽기 전용으로 열고, 없으면 에러 처리
    if ((fd_src = open(src, O_RDONLY)) < 0) {
        perror(src);
        exit(1);
    }
    // 목적지 파일을 쓰기 전용으로 열고, 없으면 생성하고, 있으면 내용을 지우고 새로 씀
    if ((fd_des = open(des, O_WRONLY | O_CREAT | O_TRUNC, PERM)) < 0) {
        perror(des);
        close(fd_src);
        exit(1);
    }
    // 소스 파일에서 읽은 내용을 목적지 파일에 쓰기
    while ((nread = read(fd_src, buf, sizeof(buf))) > 0) {
        if (write(fd_des, buf, nread) < nread) { // write()가 실패한 경우 
            close(fd_src);
            close(fd_des);
            exit(1);
        }
    }
    // 소스, 목적지 파일 닫기
    close(fd_src);
    close(fd_des);
    if(nread == -1) { // read()가 실패한 경우
        exit(1);
    }
}