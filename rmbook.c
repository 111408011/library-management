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
#include <stdlib.h>
#include<string.h>
#include"try11.h"	
/*this function show book record using doubly link list*/
void showrcrd(){
	FILE *fp;
	fp = fopen("book1.txt","rb+");
	inti();
	read_data();
	walkList();
	fclose(fp);
	admi();
}
void rmbook(){
	FILE *fp;
	char id[10];
	fp = fopen("book.txt","rb");
	printf("enter your id \n");
	scanf("%s",id);
	inti();
	read_data();
	searchNode(id);  
	write_data();
	admi();
}

void show(){
	int i;
	book aa;
	FILE *fp;
	char a[9][10]={"CIVIL","COMP","ELEC","ENTC","IT","MECH","META","PROD","PLAN"};
	printf("0 .CIVIL 1.COMP  2.ELEC  3.ENTC  4.IT   5.MECH   6.META   7.PRODUCTION  8.PLANING\n");
	printf("enter branch of book record\n");
	scanf("%d",&i);
	fp=fopen("book1.txt","rb+");	
	inithashtable();
	while(fread(&aa,sizeof(book),1,fp)==1) {
		insert(&aa);	 
	}
	tra(i);
	//traverse();
	student();
}
void mainmenu(){
	system("clear");
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
		printf("---------INVALID INPUT----------\n");
		mainmenu();
		break;
	}

}
/*this functions for double link list which delete ,add,detect book record*/
void inti() {
        head = (node *)malloc(sizeof (node));
        tail = (node *)malloc(sizeof (node));
        head->next = tail;
        tail->prev = head;
        head->prev = tail->next = NULL;
}
node*  creanode(struct node  *newnod) {
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
        newnode->prev = NULL;
        return (newnode);
  }

void walkList(){
	node *p;
	p = (node *)malloc(sizeof( node));
	p = head->next;
	while(p!=tail) {
	printf("________________________________________________\n");
        printf("%s ",p->cat);
        printf("%s ",p->name);
        printf("%s ",p->id);
        printf("%s ",p->auther);
        printf("%s ",p->edition);
	printf("%d ",p->page);
        printf("%s ",p->publication);
	printf("%.2f ",p->price);
	printf("%d \n",p->count);

		p = p->next;
	}
	printf("________________________________________________\n");
  }
  
  void insertAtEnd(node  *newnod) {
        node *newnode =  creanode(newnod);
        newnode->next = tail;
        newnode->prev = tail->prev;
        tail->prev->next = newnode;
        tail->prev = newnode;
  }

    void searchNode(char *id) {
	int ch;
        node *temp = head->next;
	node *temp2;
        while (temp != tail) {
                if (strcmp(temp->id,id)==0) {
                        printf("Given node is present\n");
			printf("do u want to delete 1 for yes\n");
			scanf("%d",&ch);
			if(ch==1){
			temp2 = temp;
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        free(temp2);
			//return;
			}
                       return;
                }
                temp = temp->next;
        }
        printf("Given book is not present in the list\n");
        
  }

void write_data() {
	book a;
	node *p;
	p = ( node *)malloc(sizeof(node));
	p = head->next;	FILE *fp;
	fp= fopen("book1.txt","wb+");
	while(p != tail) {
	strcpy(a.cat,p->cat);	
	strcpy(a.name,p->name);
        strcpy(a.id,p->id);
        strcpy(a.auther,p->auther);
        strcpy(a.edition,p->edition);
	a.page=p->page;
        strcpy(a.publication,p->publication);
	a.price=p->price;
	a.count=p->count;
	fwrite(&a, sizeof(book), 1, fp);
		
		p = p->next;
	}
	fclose(fp);
}
void read_data(){
	book a;
	 node *newnode;
	newnode = ( node *)malloc(sizeof(node));
	FILE *fp;
	fp= fopen("book1.txt","rb+");
	while(fread(&a, sizeof(book), 1, fp)==1) {
	strcpy(newnode->cat,a.cat);
	strcpy(newnode->name,a.name);
        strcpy(newnode->id,a.id);
        strcpy(newnode->auther,a.auther);
        strcpy(newnode->edition,a.edition);
	newnode->page=a.page;
        strcpy(newnode->publication,a.publication);
	newnode->price=a.price;
	newnode->count=a.count;
		insertAtEnd(newnode);		
	}
	fclose(fp);
}
