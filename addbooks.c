#include<stdio.h>
#include"t1.h"
void addbooks(){
	FILE *fp;
	fp=fopen("book.txt","ab+");
	book a;
	printf("name of book\n");
	scanf(" %s",a.name);
	printf("id of book\n");
	scanf("%s",a.id);
	printf("auther of book\n");
	scanf(" %s",a.auther);
	printf("edition of book\n");
	scanf(" %s",a.edition);

	printf("pulication\n");
	scanf(" %s",a.publication);
      
	printf("pages \n ");
	scanf(" %d",&a.page);

	printf("total no of books \n");
	scanf(" %d",&a.count);

	printf("price\n");
	scanf(" %f",&a.price);

	fwrite(&a,sizeof(book),1,fp);
	fclose(fp);
	/*fp=fopen("book.txt","rb+");
	fread(&a,sizeof(book),1,fp);
	printf("read succesfull");	
	printf("%s\n %s\n %s\n %s\n %s\n %d\n %d\n %f\n",a.name,a.id,a.auther,a.edition,a.publication,a.page,a.count,a.price);
	fclose(fp);*/
	//return 0;
}

	
