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
#include<time.h>
#include"t1.h"
#include<string.h>
#include <ctype.h>

enum month {JAN=0, FEB,MARCH,APRIL,MAY,JUN,JULY,AUGST,SEP,OCT,NOV,DEC};
/*this function delete issue book data */
void retur(){
	char id[10];
	int b;
	list l;
	init(&l);
	readf(&l);
	traversell(&l);
	printf("Enter id of book\n");
	scanf("%s",id);
	nsearch(&l,id);
	writef(&l);	
	admi();
}
/* this function add books into file*/
void addbooks(){
	int i;
	FILE *fp;
	fp=fopen("book1.txt","ab+");
	book a;
	char b[9][10]={"CIVIL","COMP","ELEC","ENTC","IT","MECH","META","PROD","PLAN"};
	printf("0 .CIVIL 1.COMP  2.ELECTRICAL  3.ENTC  4.IT   5.MECH   6.META   7.PRODUCTION  8.PLANING\n");
	printf("enter the cat\n");
	scanf("%d",&i);
	if(i==9)
		admi();
	strcpy((a.cat),b[i]);	

	printf("name of book\n");
	scanf("%s",a.name);
	printf("id of book\n");
	scanf("%s",a.id);
	printf("auther of book\n");
	scanf("%s",a.auther);
	printf("edition of book\n");
	scanf("%s",a.edition);

	printf("pulication\n");
	scanf("%s",a.publication);

	printf("pages \n ");
	scanf("%d",&a.page);

	printf("total no of books \n");
	scanf("%d",&a.count);

	printf("price\n");
	scanf("%f",&a.price);

	fwrite(&a,sizeof(book),1,fp);
	fclose(fp);
	admi();
}
/*this function issue book on basis of id*/
void issue(char *id){
	book an;
	FILE *fm;
	fm=fopen("book1.txt","rb+");
	int c=0;
	while(fread(&an,sizeof(book),1,fm)==1){
		if(strcmp(an.id,id)==0){
			printf("_____________________________________________\n");
			printf("categary:%s\n name:%s\n id:%s\n  auth:%s\n  edi:%s\n  publi:%s\n pages:%d\n count:%d\n  price:%f\n",an.cat,an.name,an.id,an.auther,an.edition,an.publication,an.page,an.count,an.price);
			printf("_____________________________________________\n");		

			if (an.count==0){
				printf("Sorry,no more is book available\n");
				student();
				exit(0);
			}

			fseek(fm,-sizeof(book),SEEK_CUR);
			c=1;
			//an.count-=1;
			showdate(an.id,an.name);
			fwrite(&an,sizeof(book),1,fm);
			break;
	
		}
	}
	if(!c)
		printf("book id not match\n");
	student();
}
/*this function issue book on basis of name*/
void issuen(char *name){
	book an;
	FILE *fm;
	fm=fopen("book1.txt","rb+");
	int c=0;
	while(fread(&an,sizeof(book),1,fm)==1){
		if(strcmp((an.name),name)==0){
			printf("_____________________________________________\n");
			printf("categary:%s\n bname:%s\n id:%s\n  auth:%s\n  edi:%s\n  publi:%s\n pages:%d\n count:%d\n  price:%f\n",an.cat,an.name,an.id,an.auther,an.edition,an.publication,an.page,an.count,an.price);
			printf("_____________________________________________\n");		
			if (an.count==0){
				printf("Sorry,no more is book available\n");
				student();
				exit(0);
			}
			showdate((an.id),(an.name));
			fseek(fm,-sizeof(book),SEEK_CUR);
			c=1;
			//an.count-=1;
			fwrite(&an,sizeof(book),1,fm);
			break;
	
		}
	}
	if(!c)
		printf("book id not match\n");

	student();
}

void showdate(char *id,char *name){
	date da;
	strcpy((da.name),name);
	strcpy(da.id,id);
	FILE *fp;
	fp=fopen("issue.txt","ab+");
	int i=0,j=JAN;
        char aa[10],ab[10];
	char mo[12][10]={"JAN", "FEB","MARCH","APRIL","MAY","JUN","JULY","AUGST","SEP","OCT","NOV","DEC"};
	char a[10],b[10],c[10],d[10],e[10];

	time_t tp;
        char *str;
	tp = time(NULL);
        str = ctime(&tp);
	printf("%s\n", str);
	sscanf(str,"%s%s%s%s%s",a,b,c,d,e);
	strcpy(aa,b);
	da.day=atoi(c);
	da.year=atoi(e);
        
	while(aa[i]!='\0'){
		ab[i]=toupper(aa[i]);
		i++;	
	}
	ab[i]='\0';
       		
	while(j<=DEC){
		if(strcmp(ab,mo[j])==0 ){
			da.mm=j+1;        	
			break;       
		  }
		j++;
	}
	printf("*****your present date **********************\n");
	printf("%d\t%d\t%d\n",da.day,da.mm,da.year);
	
	fwrite(&da,sizeof(date),1,fp);

	fclose(fp);
}
/*this function travel the all list*/
void just1(){
	list l;
	init(&l);
	readf(&l);
	traversell(&l);
	admi();
}
