project: project.o admin.o lgn.o student.o search.o admi.o issue.o closeapp.o regi.o time.o
	cc project.o admin.o lgn.o student.o search.o admi.o issue.o closeapp.o regi.o time.o -o project

project.o : project.c
	cc -c project.c
admi.o : admi.c
	cc -c admi.c
admin.o : admin.c
	cc -c admin.c
student.o : student.c
	cc -c student.c
search.o : search.c t1.h
	cc -c search.c
issue.o: issue.c t1.h
	cc -c issue.c
closeapp.o : closeapp.c
		cc -c closeapp.c
lgn.o : lgn.c
	cc -c lgn.c
regi.o : regi.c
	cc -c regi.c 

time.o : time.c
	cc -c time.c 
	

