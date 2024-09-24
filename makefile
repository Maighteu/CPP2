Test1:	Test1.cpp Event.o
		g++ Test1.cpp Event.o -o Test1
Event.o:	Event.cpp Event.h
		g++ Event.cpp -c

Test2:	Test2.cpp Event.o Time.o Timing.o
		g++ Test2.cpp Event.o Time.o -o Test2
Event.o:	Event.cpp Event.h
		g++ Event.cpp -c
Time.o: Time.cpp Time.h
		g++ Time.cpp -c
Timing.o:	Timing.cpp Timing.h
		g++ Timing.cpp

