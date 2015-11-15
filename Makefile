
project: project.o lgn.o search.o search2.o rmbook.o admin.o achangepass.o issue.o co.o 
	gcc project.o lgn.o search.o search2.o rmbook.o admin.o achangepass.o issue.o co.o -lcurses -o project

lgn.o:lgn.c
	gcc -c lgn.c -lcurses
search.o:search.c
	gcc -c search.c
search2.o:search2.c
	gcc -c search2.c
rmbook.o:rmbook.c
	gcc -c rmbook.c
admin.o:admin.c
	gcc -c admin.c
achangepass.o:achangepass.c
	gcc -c achangepass.c
issue.o:issue.c
	gcc -c issue.c
co.o:co.c
	gcc -c co.c
clear:
	rm -rf *o project

