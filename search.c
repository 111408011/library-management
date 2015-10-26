#include<stdio.h>
#include"t1.h"
#include<string.h>
void search(){
	book a;
	FILE *fp;
	char ch,d[10],s[10],c='n';
	printf("Search Books\n");
	printf(" 1. Search By ID\n");
	printf(" 2. Search By Name\n");
	printf("Enter Your Choice\n");
	scanf(" %c",&ch);
	fp=fopen("book.txt","rb+");
	rewind(fp);   
	switch(ch){
		case '1':
			printf("****Search Books By Id****\n");
			printf("Enter the book id:\n");
			scanf("%s",d);
			printf("Searching........\n");
			while(fread(&a,sizeof(a),1,fp)==1){
				if(strcmp(a.id,d)==0){
					printf("The Book is available\n");
					printf("%s\n %s\n %s\n %s\n ",a.name,a.id,a.auther,a.edition);
					printf("%s\n %d\n %d\n %f\n",a.publication,a.page,a.count,a.price);
					c='y';
					printf("do u want issue this book if yes note down id(Y/N)\n");
					scanf(" %c",&ch);
					if(ch=='y')
						issue();
				}
			}
			break;			
		case '2':
			printf("****Search Books By Name****\n");
			printf("Enter Book Name:\n");
			scanf(" %[^\n]s",s);
			while(fread(&a,sizeof(a),1,fp)==1){
					if(strcmp(a.name,s)==0) {
						printf("The Book is available\n");
						printf("%s\n %s\n %s\n %s\n ",a.name,a.id,a.auther,a.edition);
						printf(" %s\n %d\n %d\n %f\n",a.publication,a.page,a.count,a.price);
						c='y';
						printf("do u want issue this book if yes note down id(y/n)\n");
						scanf(" %c",&ch);
						if(ch=='y'|| ch=='Y')
							issue();
					}
			}
			break;
	}
	if(c=='n'){
		printf("book name or id not matching \n");
		printf("Try another search?(Y/N)\n");
		scanf("%c",&ch);
		if(ch=='y')
			search();
		else
			student();
	}
	printf("do u want another search?(Y/N)\n");
	scanf("%c",&ch);
	if(ch=='y')
		search();
	else
		student();

	fclose(fp);
}

