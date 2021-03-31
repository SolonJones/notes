#include"page.h"
#define DUMMY "BACKING_STORE.bin"
#define OUT "result.txt"

// this is the complete program 

int main(int argc, char* argv[]){
    // open address file to read virtual memory addr
    if(argc!=2){
        printf("only %d args, provide input file\n", argc);
        exit(1);
    }	

    FILE* fs_input = fopen(argv[1],"r");
    FILE* fs_bin = fopen(DUMMY,"r");
    FILE* fs_out = fopen(OUT, "w");

    if(fs_input <0 || fs_bin <0 ){
        printf("something wrong when opening file");
        exit(1);
    }

    int ret, vm, page_num, offset, frame_num, pm;
    signed char value;

    // run a 1000 loop to 
    // 1. fetch page numer from vir addr 
    // 2. fetch offset from vir addr 
    // 3. search pageTable for frame num 
    // 4. if page fault, handle it, then repeat 3 
    // 5. translate frame num and offset to phy addr
    // 6. fetch value from .bin file 
    // 7. print statistics 
    for(int i=0; i<1000; i++){
        ret = fscanf(fs_input,"%d",&vm);
        if(ret !=1){
            printf("something wrong during reading file");
            exit(2);
        }
        else{
            page_num = getPageNum(vm);
            //               printf("get page_num %d\n",page_num);
            offset = getOffset(vm);
            //              printf("get offset %d\n",offset);
            frame_num = getFrameNum(page_num);
            //             printf("get frame_num %d\n",frame_num);
            pm = getPhyAddr(frame_num, offset);
            //            printf("get pm %d\n",pm);
            //           printf("expectd pm 285 \n");
            //          printf("--------------\n");            
            value = fetchValue(fs_bin,vm);
           fprintf(fs_out,"virtual mem: %d,\tphysical mem: %d,\t value: %d\n",vm,pm,value);
        }
    }

    // call stats() to print statistic of this run 
    stats(fs_out);

    fclose(fs_input);
    fclose(fs_bin);
    fclose(fs_out);


    return 0; 

}

