#include"page.h"
#include<stdio.h>
// this is to test memory translation 
// vm -> phy mem 

int main(){
	/* test 1 */ 
	int dummy_vm = 16916; 
	int page_num = getPageNum(dummy_vm);
	printf("get page_num %d\n",page_num);
	int offset = getOffset(dummy_vm);
	printf("get offset %d\n",offset);
	int frame_num = getFrameNum(page_num);
	printf("get frame_num %d\n",frame_num);
	int pm = getPhyAddr(frame_num, offset);
	printf("get pm %d\n",pm);
	printf("expectd pm 20 \n");
	printf("--------------\n");

	dummy_vm = 62493; 
	page_num = getPageNum(dummy_vm);
	printf("get page_num %d\n",page_num);
	offset = getOffset(dummy_vm);
	printf("get offset %d\n",offset);
	frame_num = getFrameNum(page_num);
	printf("get frame_num %d\n",frame_num);
	pm = getPhyAddr(frame_num, offset);
	printf("get pm %d\n",pm);
	printf("expectd pm 285 \n");
	printf("--------------\n");

	
	dummy_vm = 30198; 
	page_num = getPageNum(dummy_vm);
	printf("get page_num %d\n",page_num);
	offset = getOffset(dummy_vm);
	printf("get offset %d\n",offset);
	frame_num = getFrameNum(page_num);
	printf("get frame_num %d\n",frame_num);
	pm = getPhyAddr(frame_num, offset);
	printf("get pm %d\n",pm);
	printf("expectd pm 758 \n");
	printf("--------------\n");


		return 0; 

}

