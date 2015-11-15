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
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void sti();
void retur();
void showrcrd();
void search();
void changepass();
void achangepass();
void issue(char *id);
void issuen(char *name);
void closeapp();
void addbooks();
void mainmnu();
void rmbook();
void admin();
void login();
char *pass(char);
void registration();
int main(){
	printf("--------------------------------------------------------\n");
	printf("		*******WELCOME********			\n");
	printf("--------------------------------------------------------\n");
	mainmnu();
	return  0;
}
void mainmnu(){

	char s,ch;
	printf("\n");
	printf("		1. ADMIN LOGIN			\n");
	printf("		2.REGISTRATION			\n");
	printf("		3. STUDENT LOGIN		\n");
	printf("		4. LOG OUT			\n");
	scanf(" %c",&s);
	switch(s){
		case '1':
		admin();
		break;
	case '2':
		registration();
		break;
	case '3':
		login();
		break;
	case '4':
		printf("\n");
		printf("---------------	THANK YOU-----------------------\n");
		printf("---------------	HAVE A NICE DAY	----------------\n");
		printf("\n");
		exit(0);
		break;
		
		
	default :
		printf("---------invalid input----------\n");
		mainmenu();
		break;
	}

}
