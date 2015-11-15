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
#include<stdio.h>
#include<ncurses.h>
/*this function show menu for admin*/
void admi(){
	char ch;
	printf("\n");
	printf("	--------1.SHOW BOOK RECORD------	\n");
	printf("	--------2.ADD BOOKS-------------	\n");
	printf("	--------3.CHANGE PASSWAORD------	\n");
	printf("	-------	4.REMOVE BOOKS----------	\n");
	printf("	-------	5.RETURN BOOK-----------	\n");
	printf("	-------	6.STUDENT INFORMATION---	\n");
	printf("	-------	7.ISSUE BOOK RECORD-----	\n");
	printf("	-------	8.MAINMENU--------------	\n");
	scanf(" %c",&ch);
	switch(ch){
		case '1':
			showrcrd();
			break;
		case '2':
			addbooks();
			break;
		case '3':
			achangepass();
			break;
		case '4':
			rmbook();
			break;
		case '5':
			retur();
			break;
		case '6':
			sti();
			break;
		case '7':
			just1();
			break;
		case '8':
			mainmenu();
			break;
		default :
			printf("---------INVALID INPUT----------\n");
			admi();
			break;
		}
}

void admin(){
	struct data{
	char id[10];	
	char pass[16];
	};

	struct data c;
	char m[10] ,n[10],x,ch,pa[10];
	int d=0;	

	FILE *fp,*fm;
	fp=fopen("admin.txt","rb+");
	printf("/**************ADMIN ID=12345   PASS= 00 ******************/\n");
	printf("ENTER ID \n");
	scanf("%s", m);
	printf("ENTER PASS\n");
	pass(n);
	rewind(fp);
	fread(&c,sizeof(struct data), 1, fp);
	while((d==0)){
		
		if((strcmp(c.id,m)==0) && (strcmp(c.pass,n)==0)){
			printf("SUCCESFULLY MATCH\n");
			d=1;
		}
		else {
			printf("1.RE ENTER\n ");
			printf("2.MAINMENU\n");
			scanf(" %c",&x);		
			system("clear");
			switch(x){
				case '1':
					printf("ENTER THE ID \n");
					scanf("%s", m);
					printf("ENTER  PASS\n");
					pass(n);
					break;
				case '2':
					mainmenu();
				}
		}
	}
	if(d){	
		printf("\n");
		printf("	--------1.SHOW BOOK RECORD------	\n");
		printf("	--------2.ADD BOOKS-------------	\n");
		printf("	--------3.CHANGE PASSWAORD------	\n");
		printf("	-------	4.REMOVE BOOKS----------	\n");
		printf("	-------	5.RETURN BOOK-----------	\n");
		printf("	-------	6.STUDENT INFORMATION---	\n");
		printf("	-------	7.ISSUE BOOK RECORD-----	\n");
		printf("	-------	8.MAINMENU--------------	\n");
		scanf(" %c",&ch);
	}
	switch(ch){
		case '1':
			showrcrd();
			break;
		case '2':
			addbooks();
			break;
		case '3':
			achangepass();
			break;
		case '4':
			rmbook();
			break;
		case '5':
			retur();
			break;
		case '6':
			sti();
			break;
		case '7':
			just1();
			break;
		case '8':
			mainmenu();
			break;
		default :
			printf("---------INVALID INPUT----------\n");
			admi();
			break;

		}
	fclose(fp);
}









