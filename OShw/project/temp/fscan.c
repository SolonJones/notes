#include<stdio.h>
#include<stdlib.h>


int main(int argc, char* argv[]){
	if(argc!=2){
		printf("only %d args, provide input file\n", argc);
		exit(1);
	}	

	printf("dummy open file %s\n", argv[1]);
	FILE* fs = fopen(argv[1],"r");
	int ret, value;
	int count = 0;
	for(int i=0; i<1000; i++){
		ret = fscanf(fs,"%d",&value);
		if(ret ==1){
		//	printf("read value %d success \n", value);
			count++;
		}
	}
	printf("total read count %d \n", count);
	printf("last read value %d \n", value);

	fclose(fs);
	return 0; 
}
