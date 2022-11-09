#ifndef STRINGSO_H_
#define STRINGSO_H_

void char_swap(char* n1, char* n2);
int length_str(char *str);
void get_string(char* str);
void print_str(char* str);
void str_slice(char* str, int start, int end, char* sliced);
void copy_str(char* str, char* new);
int str_compare(char* str1, char* str2);
void str_concat(char* str, char* str1, char* str2);
int string_to_int(char* str);
void slice_str( char * str, char * buffer, int start, int end);
int checkexd(char* s);
int checktran(char* s);
#endif
