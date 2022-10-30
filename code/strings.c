#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "string.h"
#include <stdlib.h>


void swap_char(char* n1, char* n2) {
    char temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int length_str(char *str) {
    int i;
    for(i=0; str[i]; i++);
    return i;
}

void get_string(char* str) {
    int i=0;
    scanf("%c", &str[i]);
    for(; str[i]!='\n';) {
        i++;
        scanf("%c", &str[i]);
    }
}

void print_str(char* str) {
    for(int i=0; str[i]; i++) {
        printf("%c", str[i]);
    }
}

void str_slice(char* str, int start, int end, char* sliced) {
    int i;
    for(i=start; i<=end; i++) {
        sliced[i-start] = str[i];
    }
    sliced[i-start]=0;
}
void slice_str( char * str, char * buffer, int start, int end)
{
    int j = 0;
    for ( int i = start; i <= end; i++ ) {
        buffer[j] = str[i];
        j++;
    }
    buffer[j] = 0;
}
void copy_str(char* str, char* new){
    int i;
    for(i=0; str[i]!=0; i++) {
         new[i]=str[i] ;
    }
    new[i] = 0;
}

int str_compare(char* str1, char* str2) {
    int i;
    for(i=0; str1[i] || str2[i]; i++) {
        if(str1[i] != str2[i]) return 0;
    }
    return 1;
}

void str_concat(char* str, char* str1, char* str2){
    int i, j;
    for(i=0; str1[i]; i++){
        str[i] = str1[i];
    }
    for(j=0; str2[j]; j++){
        str[i] = str2[j];
        i++;
    }
    str[i]=0;
}

int string_to_int(char* str) {
    int i=0, n=0;
    char negative=0;
    if(str[0] == '-') {
        negative=1;
        i++;
    }
    while(!str[i]) {
        i++;
    }
    // It just skips non numeric characters
    while(str[i]) {
        if(str[i] >= '0' && str[i] <= '9') {
            n = n*10 + (str[i] - '0');
        }
        i++;
    }
    if(negative) {
        n *= -1;
    }
    return n;
}
