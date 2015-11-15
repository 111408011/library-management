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

/*this function include code of hashing */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"t1.h"
void init(list *l){
	l->head = l->tail = NULL;
}
nodell* makenodell(nodell *d){
        nodell *ptr = (nodell *) malloc(sizeof(nodell));
	strcpy(ptr->name,d->name);
	strcpy(ptr->id,d->id);
	ptr->day=d->day;
	ptr->mm=d->mm;
	ptr->year=d->year;

        ptr->next = NULL;
        ptr->prev = NULL;
	return ptr;  
}


void traversell(list *l){
	nodell *ptr = l->head;
	while(ptr) {
	printf("___________________________________________________\n");
                printf("%s	", ptr->name);
                printf("%s	", ptr->id);
		printf("%d-%d-%d\n",ptr->day,ptr->mm,ptr->year);
		ptr=ptr->next;
	}
	printf("___________________________________________________\n");	
}
void writef(list *l) {
	date d;
	nodell *p;
	p = ( nodell *)malloc(sizeof(nodell));
	p = l->head;	FILE *fp;
	fp= fopen("issue.txt","wb+");
	while(p) {
	strcpy(d.name,p->name);	
	strcpy(d.id,p->id);
	d.day=p->day ;
	d.mm=p->mm;
	d.year=p->year;

	fwrite(&d, sizeof(date), 1, fp);
		
		p = p->next;
	}
	fclose(fp);
}
void append(list *l, nodell *d) {
	nodell *p,*tmp;
	p=l->tail;
	tmp = makenodell(d);
	if(l->head==NULL){
	l->head=tmp;
	l->tail=tmp;
	tmp->prev=NULL;
	tmp->next=NULL;
	}
	else{
	tmp->prev=p;
	tmp->next=NULL;
	p->next=tmp;
	l->tail=tmp;	
	}
}

void readf(list *l){
	date d;
	 nodell *ptr;
	ptr = ( nodell *)malloc(sizeof(nodell));
	FILE *fp;
	fp= fopen("issue.txt","rb+");
	while(fread(&d, sizeof(date), 1, fp)==1) {
	strcpy(ptr->name,d.name);
	strcpy(ptr->id,d.id);
	ptr->day=d.day;
	ptr->mm=d.mm;
	ptr->year=d.year;
		append(l,ptr);
	//ptr=ptr->next;
	}
	fclose(fp);
}
void nsearch(list *l,char *id){
	char ch;
        nodell *temp = l->head;
	nodell *temp2;
			nodell *p;
			p = l->head;

        while(temp){
                if (strcmp(temp->id,id)==0) {
                        printf("GIVEN BOOKS IS PRESENT\n");
			printf("DO U WANT TO DELETE 1 FOR YES\n");
			scanf(" %c",&ch);
			if(ch=='1'){
				if(temp==l->head && temp==l->tail){
					l->head->prev=NULL;
					l->head->next=NULL;
					free(temp);
					return;
				}

				if(temp==l->head && temp!=l->tail){
					temp2=temp;
					temp =l-> head->next;
				        l->head->next = temp->next;
				        l-> head=temp;
				        free(temp2);
					return;
				}
				if(temp!=l->head &&  temp!=l->tail){
					temp2 = temp;
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					free(temp2);
					return;			
					}
				if(temp==l->tail && temp!=l->head){
					temp2=temp;
					temp->prev->next = NULL;
					l->tail=temp->prev;
					free(temp2);
					return;		
				}
			}
                }
                temp = temp->next;
        }
        printf("GIVEN BOOK IS NOT PRESENT IN THE LIST\n");
}


