LIB=./Classes/

Test8:	Test8.cpp $(LIB)Time.o $(LIB)Timing.o $(LIB)Event.o $(LIB)Schedulable.o $(LIB)Professor.o $(LIB)Group.o $(LIB)Classroom.o $(LIB)Exception.o $(LIB)TimeException.o $(LIB)TimingException.o $(LIB)XmlFileSerializerException.o $(LIB)Timetable.o
		g++ Test8.cpp $(LIB)Timing.o $(LIB)Event.o $(LIB)Time.o $(LIB)Schedulable.o $(LIB)Professor.o $(LIB)Group.o $(LIB)Classroom.o $(LIB)Exception.o $(LIB)TimeException.o $(LIB)TimingException.o $(LIB)XmlFileSerializerException.o $(LIB)Timetable.o -o Test8

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
$(LIB)Exception.o:	$(LIB)Exception.cpp $(LIB)Exception.h
		g++ $(LIB)Exception.cpp -c -o $(LIB)Exception.o
$(LIB)TimeException.o:	$(LIB)TimeException.cpp $(LIB)TimeException.h
		g++ $(LIB)TimeException.cpp -c -o $(LIB)TimeException.o
$(LIB)TimingException.o:	$(LIB)TimingException.cpp $(LIB)TimingException.h
		g++ $(LIB)TimingException.cpp -c -o $(LIB)TimingException.o
$(LIB)XmlFileSerializerException.o:	$(LIB)XmlFileSerializerException.cpp $(LIB)XmlFileSerializerException.h
		g++ $(LIB)XmlFileSerializerException.cpp -c -o $(LIB)XmlFileSerializerException.o
$(LIB)Timetable.o:	$(LIB)Timetable.cpp $(LIB)Timetable.h
		g++ $(LIB)Timetable.cpp -c -o $(LIB)Timetable.o
clean:
	rm -f $(LIB)*.o Test?
