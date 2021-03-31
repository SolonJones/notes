#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int getPageNum(int);

int getOffset(int);

int getFrameNum(int);

void pageFault(int);

int getPhyAddr(int, int);

signed char fetchValue(FILE*, int);

void stats(FILE*);
