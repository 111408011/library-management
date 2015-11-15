/*****************************************************************************
 * Copyright (C) MAHESH K. DAWEDAR dawedarmk14.it@coep.ac.in
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 *****************************************************************************/

/*this function changes password of admin*/
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
void achangepass(){
	struct data{
		char id[10];	
		char pass[16];
	};
	struct data c;
	char ch;
	char m[10],nn[16],n[16],x,pa[10];
	int d=0,a=0;	
	printf("CHANGE PASSWAORD\n");
	FILE *fp;
	FILE *fs;
	fp=fopen("admin.txt","rb+");
	printf("ENTER THE ID 5 DIGIT FOR LOGIN \n");
	scanf("%s", m);
	printf("ENTER 5 DIGIT PASS\n");
	pass(nn);

	rewind(fp);
	fread(&c,sizeof(struct data), 1, fp);
	while((d==0)){
		if((strcmp(c.id,m)==0) && (strcmp(c.pass,nn)==0)){
			c.pass[0]='\0';
			printf("ID MATCH SUCCESFULLY \n");
			d=1; a=1;
			fseek(fp,-sizeof(struct data),SEEK_CUR);
			read:		
			    	printf("ENTER NEW PASSWORD\n");
				scanf("%s",pa);
				strcpy((c.pass),pa);
			    	printf("ENTER NEW PASSWORD FOR CONFORMATION\n");
				scanf("%s",n);
			if(strcmp(c.pass,n)==0){
				fwrite(&c,sizeof(struct data), 1, fp);
				printf("YOUR PASSWORD CHANGE SUCCESSFULLY\n");	
			}
			else{
				printf("YOUR PASSWORD NOT MATCH\n");
				goto read;
			}
		}

		else {
			printf("1.RE ENTER UR ID\n ");
			printf("2.MAINMENU\n");
			scanf(" %c",&x);		
			system("clear");
			switch(x){
				case '1':
					printf("ENTER THE ID \n");
					scanf("%s", m);
					break;
				case '2':
					mainmenu();
				}
		}
	}
		fclose(fp);
	if(d)
	printf("LOGIN ONCE AGAIN\n");
	admin();	

	
}

/*this function changes password of student*/
void changepass(){
	struct data{
		char id[10];	
		char pass[16];
	};
	struct data c;
	char ch;
	char m[10] ,n[16],x,pa[10],nn[16];
	int d=0,a=0;	
	printf("CHANGE PASSWAORD\n");
	FILE *fp;
	FILE *fs;
	fp=fopen("stud","rb+");
	printf("ENTER THE ID FOR LOGIN \n");
	scanf("%s", m);
	printf("ENTER  PASS\n");
	pass(nn);

	rewind(fp);
	while(a==0){
		while(fread(&c,sizeof(struct data), 1, fp)==1){
	
			if((strcmp(c.id,m)==0) && (strcmp(c.pass,nn)==0)){
				printf("ID MATCH SUCCESFULLY \n");
				d=1; a=1;
				fseek(fp,-sizeof(struct data),SEEK_CUR);
				c.pass[0]='\0';
				read:		
				    	printf("ENTER NEW PASSWORD\n");
					scanf("%s",pa);
					strcpy((c.pass),pa);
				    	printf("ENTER NEW PASSWORD FOR CONFORMATION\n");
					scanf("%s",n);
				if(strcmp(c.pass,n)==0){
					printf("YOUR PASSWORD CHANGE SUCCESSFULLY\n");	
					fwrite(&c,sizeof(struct data), 1, fp);
				}
				else{
					printf("YOUR PASSWORD NOT MATCH\n");
					goto read;
				}
				break;
			}
			else {
				a=0;
			}
		}
		if(a==0){
		printf("1.RE ENTER\n ");
		printf("2.MAINMENU\n");
		scanf(" %c",&x);		
		switch(x){
			case '1':
				m[0]='\0';n[0]='\0';
				printf("ENTER THE ID \n");
				scanf("%s", m);
				rewind(fp);
				
				break;
			case '2':
				mainmenu();
			}
		}
	}
	fclose(fp);
	mainmenu();
}

