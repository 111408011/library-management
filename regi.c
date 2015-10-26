#include<stdlib.h>
#include<stdio.h>
void registration(){
	struct data{
	char id[10];	
	char pass[16];
	};

	struct data c;
	char ch;
	char m[10] ,n[10],x;
	int d=0,a=0;	

	printf("1.registration\n");

	FILE *fp;

	fp=fopen("stud","ab+");

	printf("enter the id \n");
	printf("enter  pass\n");	

	scanf("%s%s", c.id, c.pass);

	fwrite(&c,sizeof(struct data), 1, fp);

	fclose(fp);

	login();
	

}






