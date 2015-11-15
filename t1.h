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

#define SIZE 9 
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

typedef struct nodell {
	char name[10];
	char id[10];
	int day,mm,year;
	struct nodell *next, *prev;
}nodell;

typedef struct list {
	struct nodell *head, *tail;
}list;


typedef struct issuedata{
	char name[10];
	char id[10];
	int day,mm,year;
	}date;
typedef struct showr{
	char stid[10];
	char bid[10];
	char bname[10];
	char type[10];
	}showr;
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
	struct node *next;
}node;
node *hashtable[SIZE];
int hash (book  *newnod);
void inithashtable();
void insert(book  *newnod);
int searchi(int i,char *id);
int searchn(int i,char *name);
void traverse();
void student();
void showdate(char *id,char *name);
nodell* makenodell(nodell *d);
void init(list *l); 
void traversell(list *l) ;
void writef(list *l);
void append(list *l, nodell *d);
void readf(list *l);
void nsearch(list *l,char *id);
void mainmenu();
