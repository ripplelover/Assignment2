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

// 파일 1의 정보를 가져오는 함수
void filestat1(){
    if (stat(text1, &stat1) == -1) {
        perror("Failed to get stat for text1");
    }
}

// 파일 2의 정보를 가져오는 함수
void filestat2(){
    if (stat(text2, &stat2) == -1) {
        perror("Failed to get stat for text2");
    }
}

// 파일 1의 시간 정보를 가져오는 함수
void filetime1(){
    time1 = localtime(&stat1.st_mtime);
    if (time1 == NULL) {
        perror("Failed to convert time for text1");
    }
}

// 파일 2의 시간 정보를 가져오는 함수
void filetime2(){
    time2 = localtime(&stat2.st_mtime);
    if (time2 == NULL) {
        perror("Failed to convert time for text2");
    }
}

// 두 개의 파일 크기를 비교하는 함수
void sizecmp(){
    printf("size compare\n");
    if (stat1.st_size > stat2.st_size)
        printf("%s is bigger\n\n", text1);
    else if (stat1.st_size < stat2.st_size)
        printf("%s is bigger\n\n", text2);
    else
        printf("sizes are equal\n\n");
}

// 두 개의 파일 블럭 수를 비교하는 함수
void blockcmp(){
    printf("block compare\n");
    if (stat1.st_blocks > stat2.st_blocks)
        printf("%s uses more blocks\n\n", text1);
    else if (stat1.st_blocks < stat2.st_blocks)
        printf("%s uses more blocks\n\n", text2);
    else
        printf("blocks are equal\n\n");
}

// 두 개의 파일 수정 날짜를 비교하는 함수
void datecmp(){
    printf("date compare\n");
    if (time1->tm_mon < time2->tm_mon)
        printf("%s is early\n\n", text1);
    else if (time1->tm_mon > time2->tm_mon)
        printf("%s is early\n\n", text2);
    else {
        if (time1->tm_mday < time2->tm_mday)
            printf("%s is early\n\n", text1);
        else if (time1->tm_mday > time2->tm_mday)
            printf("%s is early\n\n", text2);
        else
            printf("same date\n\n");
    }
}

// 두 개의 파일 수정 시간을 비교하는 함수
void timecmp(){
    printf("time compare\n");
    if (time1->tm_hour < time2->tm_hour)
        printf("%s is early\n", text1);
    else if (time1->tm_hour > time2->tm_hour)
        printf("%s is early\n", text2);
    else {
        if (time1->tm_min < time2->tm_min)
            printf("%s is early\n", text1);
        else if (time1->tm_min > time2->tm_min)
            printf("%s is early\n", text2);
        else
            printf("same time\n");
    }
    printf("\n");
}
