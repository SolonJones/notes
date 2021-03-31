#include"page.h"
#include<stdbool.h>
#define PAGE_SZ 256
#define MAX 1000

struct Entry{
	int frame_num;
	bool validity;
};

int ram_loc=0;

struct Entry pageTable[MAX];

int getPageNum(int vm){
	return vm/PAGE_SZ;
}

int getOffset(int vm){
	return vm%PAGE_SZ;
}

int getFrameNum(int pgnm){

	if(pageTable[pgnm].validity == true){
		// directly get frame num
	}
	else{
		// page fault; load page frame first
		pageFault(pgnm);
		
	}
		return pageTable[pgnm].frame_num;
}

void pageFault(int pgnm){
	pageTable[pgnm].frame_num=ram_loc++;
	pageTable[pgnm].validity=true;
}

int getPhyAddr(int frame_num, int offset){
	return frame_num*PAGE_SZ + offset;
}
