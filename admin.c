#include<stdlib.h>
#include<stdio.h>
void admin(){
	struct data{
	char id[10];	
	char pass[16];
	};

	struct data c;
	FILE *fp,*fm;
	fp=fopen("admin.txt","rb+");
	printf("enter the id \n");
	printf("enter  pass\n");
	char m[10] ,n[10],x,ch;
	int d=0;	
	scanf("%s\n%s", m, n);
	rewind(fp);
	fread(&c,sizeof(struct data), 1, fp);
	while((d==0)){
		
		if((strcmp(c.id,m)==0) && (strcmp(c.pass,n)==0)){
			printf("match\n");
			d=1;
		}
		else {
			printf("1.re enter\n ");
			printf("for exit press 2\n");
			scanf(" %c",&x);		
			system("clear");
			switch(x){
				case '1':
					printf("enter the id \n");
					printf("enter  pass\n");
					scanf("%s\n%s", m, n);
					break;
				case '2':
					exit(0);
				}
		}
	}
	if(d){	
		printf("1.show record\n");
		printf("2.add books\n");
		printf("3.change passwaord\n");
		printf("4.remove books\n");
		printf("5.exit");
		scanf(" %c",&ch);
		switch(ch){
			case '1':
//				showrcrd();
				break;
			case '2'://printf("adding books");
//				addbooks();
				break;
			case '3':
//				changepass();
				break;
			case '4':
//				rmbook();
				break;
			case '5':
				exit(0);
				break;
		}	
	}
	fclose(fp);
}









