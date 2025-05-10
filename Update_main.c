#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

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

    free(time1);
    free(time2);
}

// 파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    if (stat(text1, &stat1) == -1) {
        perror("Failed to get stat for text1");
    }
}

// 파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    if (stat(text2, &stat2) == -1) {
        perror("Failed to get stat for text2");
    }
}

// 파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
    struct tm *temp = localtime(&stat1.st_mtime);
    if (temp != NULL) {
        time1 = malloc(sizeof(struct tm));
        if (time1 == NULL) {
            perror("malloc failed for time1");
            exit(1);
        }
        *time1 = *temp;
    } else {
        perror("Failed to convert time for text1");
    }
}

// 파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    struct tm *temp = localtime(&stat2.st_mtime);
    if (temp != NULL) {
        time2 = malloc(sizeof(struct tm));
        if (time2 == NULL) {
            perror("malloc failed for time2");
            exit(1);
        }
        *time2 = *temp;
    } else {
        perror("Failed to convert time for text2");
    }
}

// 두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    printf("size compare\n");
    if (stat1.st_size > stat2.st_size)
        printf("%s is bigger\n\n", text1);
    else if (stat1.st_size < stat2.st_size)
        printf("%s is bigger\n\n", text2);
    else
        printf("sizes are equal\n\n");
}

// 두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    printf("block compare\n");
    if (stat1.st_blocks > stat2.st_blocks)
        printf("%s uses more blocks\n\n", text1);
    else if (stat1.st_blocks < stat2.st_blocks)
        printf("%s uses more blocks\n\n", text2);
    else
        printf("blocks are equal\n\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp() {
    printf("date compare\n");
    if (time1->tm_mon < time2->tm_mon)
        printf("text1 is early\n\n");
    else if (time1->tm_mon > time2->tm_mon)
        printf("text2 is early\n\n");
    else {
        if (time1->tm_mday < time2->tm_mday)
            printf("text1 is early\n\n");
        else if (time1->tm_mday > time2->tm_mday)
            printf("text2 is early\n\n");
        else
            printf("same date\n\n");
    }
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp() {
    printf("time compare\n");
    int total_sec1 = time1->tm_hour * 3600 + time1->tm_min * 60 + time1->tm_sec;
    int total_sec2 = time2->tm_hour * 3600 + time2->tm_min * 60 + time2->tm_sec;
    if (total_sec1 < total_sec2) printf("%s is early\n\n", text1);
    else if (total_sec1 > total_sec2) printf("%s is early\n\n", text2);
    else printf("times are equal\n\n");
}
