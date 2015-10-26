#include<stdio.h>		
void student(){
	char ch;
	printf("1.search\n");
	printf("2.issue\n");
	printf("3.change passwaord\n");
	printf("4.close app\n");
	scanf(" %c",&ch);
	switch(ch){
		case '1':
			search();
			break;
		case '2':printf("issue is ssuccesfull");
			issue();
			break;
		case '3':
	//		changepass();
			break;
		case '4':
			closeapp();
			break;
	}
}
