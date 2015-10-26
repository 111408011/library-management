/*admin username=12345
	passwaord=123

student username=123
	password=12
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void mainmenu();
void showrcrd();
void search();
void changepass();
void issue();
void closeapp();
void addbooks();
void rmbook();
void admin();
void login();
void registration();
int main(){
	mainmenu();
	return  0;
}
void mainmenu(){
	char s,ch;
	printf("1. ADMIN LOGIN\n");
	printf("3.registration\n");
	printf("2. STUDENT LOGIN\n");
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
		
		
	default :
		printf("invalid input");
		mainmenu();
	}

}
