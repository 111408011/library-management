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

/*this function search book using hashing */
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include"t1.h"
#define SIZE 9 
void search(){
	int i=0,s=0,b,m=1,n=1;
	char st,id[10],name[10];
	char a[9][10]={"CIVIL","COMP","ELECTRICAL","ENTC","IT","MECH","META","PRODUCTION","PLANING"};
	book aa;
	FILE *fp;
	fp=fopen("book1.txt","rb");	
	inithashtable();
	while(fread(&aa,sizeof(book),1,fp)==1) {
//		printf("Read \n");
		insert(&aa);	 
	}
	//traverse();
	//printf("Done storing, now enter searches \n");
	while(m==1) {
		printf("0 .CIVIL 1.COMP  2.ELECTRICAL  3.ENTC  4.IT   5.MECH   6.META   7.PRODUCTION  8.PLANING\n");
		printf("enter the branch\n");
		scanf("%d",&b);
		printf("PRESS 1 FOR SEARCH BY ID \n");
		printf("PRESS 2 FOR SEARCH BY NAME\n");
		scanf(" %c",&st);
			if(st=='1'){
				printf("enter the id\n");
				scanf("%s",id);
				s=searchi(b,id);
					if(s == -1)
						printf("NOT found\n");
					else{
						printf(" book found\n");
						printf("do u want to issue PRESS 1 for yes \n");
						scanf(" %d",&n);
						if(n==1){
							printf("issue\n");
							issue(id);
						}
					}	
			}
			else{
				printf("enter the name\n");
				scanf("%s",name);
				s=searchn(b,name);
					if(s == -1)
						printf("NOT found\n");
					else{
						printf("found\n");
						printf("do u want to issue\n");
						scanf(" %d",&n);
						if(n==1){
							printf("issue\n");
							issuen(name);
						}
					}
			}
		printf("want again 1 for yes\n");
		scanf("%d",&m);
	}
	fclose(fp);		
	student();
}
