#include <stdio.h>

void print(char c){
	for(int i = 7; 0 <= i; i--){
		printf("%d",(c >> i) & 0x01);
	}
	printf("\n");
}

int main () {
	FILE *fp;

	fp = fopen("BACKING_STORE.bin","r");
	char c = 'a';
	/**********************/
	fseek( fp, 12107, SEEK_SET );
	int ret = fread(&c,sizeof(c),1,fp );
	printf("fread return %d\n",ret);
	printf("expect to read -46, real read %d",(int)c);
	printf("\n");
	/**********************/
	fseek( fp, 17071, SEEK_SET );
	ret = fread(&c,sizeof(c),1,fp );
	printf("fread return %d\n",ret);
	printf("expect to read -85, real read %d",(int)c);

	printf("\n");

	/**********************/
	fseek( fp, 30198, SEEK_SET );
	ret = fread(&c,sizeof(c),1,fp );
	printf("fread return %d\n",ret);
	printf("expect to read 29, real read %d",(int)c);

	printf("\n");

	/**********************/
	fseek( fp, 24462, SEEK_SET );
	ret = fread(&c,sizeof(c),1,fp );
	printf("fread return %d\n",ret);
	printf("expect to read 23, real read %d",(int)c);

	printf("\n");


	fclose(fp);

	return(0);
}

