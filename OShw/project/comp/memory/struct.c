#include<stdio.h>
#include"page.h"
#define MAX 1000
#define PAGE_SZ 256
#include<stdbool.h>

struct Entry{
	int frame_num;
	bool validity;
} test;

int frame_ptr;


// this is to test memory translation 
// vm -> phy mem 
int page_fault, frameptr;

int main(){
	printf("struct init int %d", test.frame_num);
	printf(test.validity ? "true": "false");
	return 0; 
}

