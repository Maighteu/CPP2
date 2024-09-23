Test1:	Test1.cpp Event.o
		g++ Test1.cpp Event.o -o Test1
Event.o:	Event.cpp Event.h
		g++ Event.cpp -c