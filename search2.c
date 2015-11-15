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

/*this function for hashing in which add book branchwise and search also */
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include"t1.h"
#define SIZE 9 

node* createNode(book  *newnod) {
        node *newnode;
        newnode = ( node *)malloc(sizeof( node));
        strcpy(newnode->cat,newnod->cat);
        strcpy(newnode->name,newnod->name);
        strcpy(newnode->id,newnod->id);
        strcpy(newnode->auther,newnod->auther);
        strcpy(newnode->edition,newnod->edition);
	newnode->page=newnod->page;
        strcpy(newnode->publication,newnod->publication);
	newnode->price=newnod->price;
	newnode->count=newnod->count;
        newnode->next = NULL;
        return (newnode);
}

int hash (book  *newnod) {
	char data[10];
	strcpy(data,newnod->cat);
	int i;
	char a[9][10]={"CIVIL","COMP","ELEC","ENTC","IT","MECH","META","PROD","PLAN"};
	for(i=0; i < 9; i++){
		if(strcmp(data,a[i])==0)
			break;	 
	}
	return i;
} 

void inithashtable() {
	int i;
	for(i=0; i < 9; i++)
		hashtable[i] = NULL; 
}
void insert(book  *newnod) {
	int index=hash(newnod);
	node *tmp;
	tmp=createNode(newnod);
	tmp->next = hashtable[index];
	hashtable[index] = tmp;	
}
int searchi(int i,char *id) {
	node *p = hashtable[i];
	while(p) {
		if(strcmp(p->id, id) == 0){
			printf("_______________________________________________\n");
			printf(" cat:%s \n",p->cat);
			printf("name:%s \n",p->name);
			printf("id :%s \n",p->id);
			printf("auther:%s \n",p->auther);
			printf("edition: %s \n",p->edition);
			printf("pages:%d \n",p->page);
			printf("publication:%s \n",p->publication);
			printf("price:%.2f \n",p->price);
			printf("count:%d \n",p->count);
			printf("_________________________________________________\n");
			return 1;
		}
				
		p = p->next;
	}
	return -1;
}
int searchn(int i,char *name) {
	node *p = hashtable[i];
	while(p) {
		if(strcmp(p->name, name) == 0){
			printf("_______________________________________________\n");
			printf(" cat:%s \n",p->cat);
			printf("name:%s \n",p->name);
			printf("id :%s \n",p->id);
			printf("auther:%s \n",p->auther);
			printf("edition: %s \n",p->edition);
			printf("pages:%d \n",p->page);
			printf("publication:%s \n",p->publication);
			printf("price:%.2f \n",p->price);
			printf("count:%d \n",p->count);
			printf("_________________________________________________\n");

			return 1;
			}
				
		p = p->next;
	}
	return -1;
}

void traverse() {
	int i;
	node *p;
	char a[9][10]={"CIVIL","COMP","ELEC","ENTC","IT","MECH","META","PROD","PLAN"};
	for(i = 0; i < SIZE; i++) {
		printf("%d : ", i);
		p = hashtable[i];
		printf("*****************%s*****************\n",a[i]);
		while(p) {
			printf("_______________________________________________\n");
			printf(" cat:%s \n",p->cat);
			printf("name:%s \n",p->name);
			printf("id :%s \n",p->id);
			printf("auther:%s \n",p->auther);
			printf("edition: %s \n",p->edition);
			printf("pages:%d \n",p->page);
			printf("publication:%s \n",p->publication);
			printf("price:%.2f \n",p->price);
			printf("count:%d \n",p->count);
			printf("_________________________________________________\n");
			p = p->next;
		}
		printf("\n");
	}
}
void tra(int i) {
	node *p;
	char a[9][10]={"CIVIL","COMP","ELEC","ENTC","IT","MECH","META","PROD","PLAN"};
		p = hashtable[i];
		printf("*****************%s*****************\n",a[i]);
		while(p) {
			printf("_______________________________________________\n");
			printf(" cat:%s \n",p->cat);
			printf("name:%s \n",p->name);
			printf("id :%s \n",p->id);
			printf("auther:%s \n",p->auther);
			printf("edition: %s \n",p->edition);
			printf("pages:%d \n",p->page);
			printf("publication:%s \n",p->publication);
			printf("price:%.2f \n",p->price);
			printf("count:%d \n",p->count);
			printf("_________________________________________________\n");
			p = p->next;
		}
		printf("\n");
}

