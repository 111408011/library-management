#include<stdlib.h>
#include<string.h>
#include<stdio.h>
void login(){
	struct data{
	char id[10];	
	char pass[16];
	};

	struct data c;
	char ch;
	char m[10] ,n[10],x;
	int d=0,a=0;	
	printf("2.login\n");
	FILE *fp;

	fp=fopen("stud","rb+");
	printf("enter the id for login \n");
	printf("enter  pass\n");
	scanf("%s\n%s", m, n);
	rewind(fp);
	while(a==0){
	while((fread(&c,sizeof(c), 1, fp))==1){
	
		
		if((strcmp(c.id,m)==0) && (strcmp(c.pass,n)==0)){
			printf("succesfully login\n");
			d=1; a=1;
			break;
		}
		else {
			a=0;
			}
		}
			if(a==0){
			printf("1.re enter\n ");
			printf("for exit press 2\n");
			scanf(" %c",&x);		
			switch(x){
				case '1':
					printf("enter the id \n");
					printf("enter  pass\n"); rewind(fp);
					m[0]='\0';n[0]='\0';
					scanf(" %s %s", m, n);
					break;
				case '2':
					exit(0);
				}
		}}
	
	if(d){	
		//student();
		system("clear");
		printf("1.search\n");
		printf("2.issue\n");
		printf("3.change passwaord\n");
		printf("4.close app\n");
		printf("enter your choice\n");
		scanf(" %c",&ch);
		switch(ch){
			case '1':
				search();
				break;
			case '2':
				issue();
				break;
			case '3':
//				changepass();
				break;
			case '4':
				closeapp();
				break;}
	}
	fclose(fp);
	}









