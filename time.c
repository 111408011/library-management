#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include<time.h>
#define RETURNTIME 8
#include<stdlib.h>
#include"t1.h"

enum month {JAN=0, FEB,MARCH,APRIL,MAY,JUN,JULY,AUGST,SEP,OCT,NOV,DEC};
void showdate(){
	ddate ddate;
	FILE *fp;
	fp=fopen("issue.txt","ab+");
	int i=0,j=JAN;
        char aa[10],ab[10];
	char mo[12][10]={"JAN", "FEB","MARCH","APRIL","MAY","JUN","JULY","AUGST","SEP","OCT","NOV","DEC"};
	char a[10],b[10],c[10],d[10],e[10];
	date da;
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
	i++;	}
	ab[i]='\0';
       		
	while(j<=DEC){
	if(strcmp(ab,mo[j])==0 ){
	da.mm=j+1;        	break;       
	  }
		j++;
	}
	printf("*****your present date **********************\n");
	printf("%d\t%d\t%d\n",da.day,da.mm,da.year);
	
da.ddate.day=da.day+RETURNTIME;
da.ddate.mm=da.mm;
da.ddate.year=da.year;
if(da.ddate.day>30)
{
da.ddate.mm+=da.ddate.day/30;
da.ddate.day-=30;

}
if(ddate.mm>12)
{
da.ddate.year+=da.ddate.mm/12;
da.ddate.mm-=12;

}
printf("********your due date******\n");
printf("%d\t%d\t%d\n",da.ddate.day,da.ddate.mm,da.ddate.year);
		//printf("MONTH=%s\n",mo[ddate.mm-1]);        
fwrite(&da,sizeof(date),1,fp);

fclose(fp);
/*fp=fopen("issue.txt","rb+");
fread(&da,sizeof(date),1,fp);
	printf("*****read   your present date **********************\n");
	printf("%d\t%d\t%d\n",da.day,da.mm,da.year);
printf("********read   your due date******\n");
printf("%d\t%d\t%d\n",da.ddate.day,da.ddate.mm,da.ddate.year);

fclose(fp);*/
}






















