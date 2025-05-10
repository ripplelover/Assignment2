#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

const char* text1 = "text1";
const char* text2 = "text2";

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    if (stat(text2, &stat2) == -1) perror("stat2");
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
    
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    time2 = localtime(&stat2.st_mtime);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){

}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    printf("block compare\n");
    if (stat1.st_blocks > stat2.st_blocks)
        printf("%s uses more blocks\n\n", file1);
    else if (stat1.st_blocks < stat2.st_blocks)
        printf("%s uses more blocks\n\n", file2);
    else
        printf("blocks are equal\n\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    
}
