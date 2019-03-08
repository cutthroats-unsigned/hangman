#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>


struct ll{
        char *data;
        struct ll *next;
};

struct bank{
        char word[41];
        int strike;
        char letter[2];
};


void printll(struct ll *temp);
struct ll *init();
struct ll *underscoreinit(char *c, int i, struct ll *temp);
//int whitespacerm(int num);
void wordbank(int num, char *c, struct ll *temp);
void drawboard(int num, char *c, int wdlen);



