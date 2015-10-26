#include<stdio.h>
#define RETURN 8
#include<stdlib.h>
#include<time.h>
#include"t1.h"
void issue(){
	book a;
	FILE *fm;
	fm=fopen("book.txt","rb+");
	char id[10];
	char c='n';
	printf("enter book id");
	scanf(" %s",id);
	while(fread(&a,sizeof(book),1,fm)==1){
		if(strcmp(a.id,id)==0){
		printf("%s\n %s\n %s\n %s\n %s\n %d\n %d\n %f\n",a.name,a.id,a.auther,a.edition,a.publication,a.page,a.count,a.price);		
		if (a.count==0){
			printf("Sorry,no more is book available\n");
			student();
			exit(0);
		}
		showdate();
	fseek(fm,-sizeof(book),SEEK_CUR);
	c='y';
	a.count-=1;
	fwrite(&a,sizeof(book),1,fm);
	break;
	
	}
	if(c!='y')
	printf("book id not match\n");
	}
	student();
}

