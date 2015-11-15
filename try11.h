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

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct book{
	char cat[10];
	char name[10];
	char id[10];
	char auther[10];
	char edition[10];
	int page;
	char publication[10];
	float price;
	int count;

	}book;

typedef struct node {
	char cat[10];
	char name[10];
	char id[10];
	char auther[10];
	char edition[10];
	int page;
	char publication[10];
	float price;
	int count;
        struct node *next, *prev;
}node;

node *head,*tail ;

node* creanode(struct node  *newnod);
void inti();
void insertAtEnd(node  *newnod);
void walkList();
void searchNode(char *name); 
void write_data(); 
void read_data(); 
void traverse();
void tra(int i);
