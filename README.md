# CSE4009 System Programming

## Lab 01

### Make

- gcc를 이용한 object file 생성
- Makefile dependency
- make / make clean
- foo.o, bar.o, main.o를 링크하여 exe 생성

### cat

- Linux cat 명령의 간단한 재구현
- open()
- read()
- write()
- close()
- file descriptor
- STDOUT_FILENO

### Run

Make 실습:

```sh
cd lab01
make
./exe
make clean
```

cat 실습:

```sh
cd lab01
gcc -W -Wall -o cat cat.c
./cat test/a test/b test/c
```
