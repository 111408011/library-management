#include<stdio.h>
#include<stdlib.h>
void admi(){
	char ch;
	printf("1.show record\n");
	printf("2.add books\n");
	printf("3.change passwaord\n");
	printf("4.remove books\n");
	printf("5.exit");
	scanf(" %c",&ch);
	switch(ch){
		case '1':
//			showrcrd();
			break;
		case '2'://printf("adding books");
	//		addbooks();
			break;
		case '3':
//			changepass();
			break;
		case '4':
//			rmbook();
			break;
		case '5':
			exit(0);
			break;
			
	}
	admi();
}
