typedef struct book{
	char name[10];
	char id[10];
	char auther[10];
	char edition[10];
	int page;
	char publication[10];
	float price;
	int count;

	}book;
typedef struct duedate{
	int day,mm,year;
	}ddate; 

typedef struct issuedata{
	char id[10];
	int day,mm,year;
	ddate ddate;
	}date;
 void showdate();
