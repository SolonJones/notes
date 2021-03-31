#include"page.h"
#include<stdio.h>
#include<stdlib.h>
#define DUMMY "BACKING_STORE.bin"

// this is the complete program 

int main(int argc, char* argv[]){
    // open address file to read virtual memory addr
    if(argc!=2){
        printf("only %d args, provide input file\n", argc);
        exit(1);
    }	

    FILE* fs_input = fopen(argv[1],"r");
    FILE* fs_bin = fopen(DUMMY,"r");

    if(fs_input <0 || fs_bin <0 ){
        printf("something wrong when opening file");
        exit(1);
    }

    int ret, vm, page_num, offset, frame_num, pm;
    char value;

    for(int i=0; i<1000; i++){
        ret = fscanf(fs_input,"%d",&vm);
        if(ret !=1){
            printf("something wrong during reading file");
            exit(2);
        }
        else{
            // do the whole testing here 

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
        
            fseek(fs_bin, vm, SEEK_SET);
            ret = fread(&value,sizeof(value),1,fs_bin);
            if(ret !=1){
                printf("something wrong during reading bin");
                exit(3);
            }
            printf("virtual mem:\t%d, physical mem:\t%d, value:\t%d\n",vm,pm,(int)value);

        }
    }


    fclose(fs_input);
    fclose(fs_bin);
    return 0; 

}

