#include"page.h"
#define PAGE_SZ 256
#define MAX 1000


/*** variables ***/
struct Entry{
	int frame_num;
	bool validity;
};

int ram_loc=0;
int page_fault=0;
struct Entry pageTable[MAX];


/*** functions ***/
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
    page_fault++;
}

int getPhyAddr(int frame_num, int offset){
	return frame_num*PAGE_SZ + offset;
}

signed char fetchValue(FILE* fs_bin,int vm){
    signed char v;
    fseek(fs_bin, vm, SEEK_SET);
    int ret = fread(&v,sizeof(v),1,fs_bin);
    if(ret !=1){
        printf("something wrong during reading bin");
        exit(3);
    }
   return v; 
}

void stats(FILE* fs_out){
    fprintf(fs_out,"process %d virtual memeory \n", MAX);
    fprintf(fs_out,"page fault %d\n", page_fault);
    fprintf(fs_out,"rate of fault %f\n ", (float)page_fault/MAX);
}
