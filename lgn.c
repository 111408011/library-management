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

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"strc.h"
#include <ncurses.h>
/* this function take password which invisible */
char  *pass(char *a){
	clear();
	initscr();			
	raw();				
	noecho();			
    	printw("ENTER PASSWORD\n");
	scanw("%s",a);
	refresh();			
	endwin();			
	return a;
}
/* this function menu for sudent*/
void student(){
	char ch;
	printf("\n");
	printf("----------------1.SEARCH-------------------------------\n");
	printf("----------------2.SHOW BOOK RECORD BRANCH WISE---------\n");
	printf("----------------3.CHANGE PASSWORD------------------------\n");
	printf("----------------4.MAINMENU--------------------------------\n");
	scanf(" %c",&ch);
	switch(ch){
		case '1':
			search();
			break;
		case '2':
			show();
			break;
		case '3':
			changepass();
			break;
		case '4':
			mainmenu();
			break;
		default :
			printf("---------invalid input----------\n");
			student();
			break;

	}
}
/*this function take id and pass */
void login(){
	struct data{
		char id[10];	
		char pass[16];
	};
	strc st;
	struct data c;
	char ch;
	char m[10] ,n[16],x,pa[10];
	int d=0,a=0;	
	printf("WELCOME STUDENT\n");
	FILE *fp;
	FILE *fs;
	fs=fopen("sho.txt","ab+");
	fp=fopen("stud","rb+");
	printf("/**************ADMIN ID=123   PASS= 00 ******************/\n");
	printf("ENTER THE ID 5 DIGIT FOR LOGIN \n");
	scanf("%s", m);
	printf("ENTER 5 DIGIT PASS\n");
	pass(n);
	rewind(fp);
	while(a==0){
	while(fread(&c,sizeof(c), 1, fp)==1){
	
		if((strcmp(c.id,m)==0) && (strcmp(c.pass,n)==0)){
			fwrite(c.id,sizeof(c.id),1,fs);	
			printf("SUCCESFULLY LOGIN\n");
			d=1; a=1;
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
					printf("ENTER  PASS\n");
					pass(n);
					rewind(fp);
					
					break;
				case '2':
					mainmenu();
				}
		}
	}
	
	if(d){	
		//system("clear");
		printf("----------------1.SEARCH-------------------------------\n");
		printf("----------------2.SHOW BOOK RECORD BRANCH WISE---------\n");
		printf("----------------3.CHANGE PASSWORD------------------------\n");
		printf("----------------4.MAINMENU--------------------------------\n");
		scanf(" %c",&ch);
		switch(ch){
			case '1':
				search();
				break;
			case '2':
				show();
				break;
			case '3':
				changepass();
				break;
			case '4':
				mainmenu();
				break;
			default :
				printf("---------INVALID INPUT----------\n");
				student();
				break;

		}
	}
	fclose(fp);
}
/*this function do registration */
void registration(){
	strc st;
	struct data{
		char id[10];	
		char pass[16];
	};
	struct data c;
	printf("2.REGISTRATION\n");
	FILE *fp,*fm,*fs;
	fm=fopen("sturc.txt","ab+");
	fp=fopen("stud","ab+");
	printf("ENTER THE ID  5 DIGIT\n");
	scanf("%s", c.id);

	printf("ENTER  PASS 5 DIGIT\n");	
	scanf("%s", c.pass);
	printf("ENTER THE FIRST NAME \n");
	scanf(" %s", st.fname);
	printf("ENTER THE MIDDLE NAME \n");
	scanf(" %s", st.mname);
	printf("ENTER THE LAST NAME \n");
	scanf(" %s", st.lname);
	printf("ENTER THE MOBILE NUMBER \n");
	scanf(" %d", &st.mnum);
	
	printf("ENTER THE YEAR \n");
	scanf(" %s", st.course);
	printf("ENTER THE DEPARTMENT \n");
	scanf(" %s", st.mname);
	strcpy(st.id,c.id);
	strcpy(st.pass,c.pass);
	printf("%s\n",c.id);
	printf("%s\n",c.pass);

	fwrite(&c,sizeof(struct data), 1, fp);
	fwrite(&st,sizeof(strc), 1, fm);
	fclose(fp);
	fclose(fm);
	login();
}
/*this function show student personal data*/
void sti(){
	strc st;
	FILE *fp;
	fp=fopen("sturc.txt","rb+");
	
	while(fread(&st,sizeof(struct strc),1,fp)==1){
		printf("________________________________________________\n");
		printf("id :%s\n", st.id);
	
		printf("pass:%s\n ", st.pass);

		printf("the first name : %s\n", st.fname);

		printf("the middle name : %s\n", st.mname);

		printf("the last name : %s\n", st.lname);
		printf("the mobile number: %d\n", st.mnum);
	
		printf("the year: %s\n", st.course);
		printf("the department: %s\n", st.mname);
		printf("________________________________________________\n");
	}
	fclose(fp);
	admi();
}
