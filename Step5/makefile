LIB=./Classes/

Test5:	Test5.cpp $(LIB)Time.o $(LIB)Timing.o $(LIB)Event.o $(LIB)Schedulable.o $(LIB)Professor.o $(LIB)Group.o $(LIB)Classroom.o
		g++ Test5.cpp $(LIB)Timing.o $(LIB)Event.o $(LIB)Time.o $(LIB)Schedulable.o $(LIB)Professor.o $(LIB)Group.o $(LIB)Classroom.o  -o Test4

$(LIB)Event.o:	$(LIB)Event.cpp $(LIB)Event.h
		g++ $(LIB)Event.cpp -c -o $(LIB)Event.o
$(LIB)Time.o: $(LIB)Time.cpp $(LIB)Time.h
		g++ $(LIB)Time.cpp -c -o $(LIB)Time.o
$(LIB)Timing.o:	$(LIB)Timing.cpp $(LIB)Timing.h
		g++ $(LIB)Timing.cpp -c -o $(LIB)Timing.o
$(LIB)Schedulable.o:	$(LIB)Schedulable.cpp $(LIB)Schedulable.h
		g++ $(LIB)Schedulable.cpp -c -o $(LIB)Schedulable.o
$(LIB)Professor.o:	$(LIB)Professor.cpp $(LIB)Professor.h
		g++ $(LIB)Professor.cpp -c -o $(LIB)Professor.o
$(LIB)Group.o:	$(LIB)Group.cpp $(LIB)Group.h
		g++ $(LIB)Group.cpp -c -o $(LIB)Group.o
$(LIB)Classroom.o:	$(LIB)Classroom.cpp $(LIB)Classroom.h
		g++ $(LIB)Classroom.cpp -c -o $(LIB)Classroom.o

clean:
	rm -f $(LIB)*.o $(LIB)Test?
