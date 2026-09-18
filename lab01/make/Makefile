CC = gcc # 컴파일러로 gcc 사용
CFLAGS = -W -Wall # 모든 경고를 표시
TARGET = exe # 최종 결과물
OBJECTS = foo.o bar.o main.o # 오브젝트로 정의된 파일

all: $(TARGET) # 타겟 여러개면 all 사용

# @: 현재 타겟 이름, ^: 현재 타켓 종속 리스트
$(TARGET): $(OBJECTS)    
	$(CC) $(CFLAGS) -o $@ $^   

$(OBJECTS): a.h

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean
