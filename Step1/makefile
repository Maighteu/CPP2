LIB=./Classes/

Test1:	Test1.cpp $(LIB)Event.o
		g++ Test1.cpp $(LIB)Event.o -o Test1

$(LIB)Event.o:	$(LIB)Event.cpp $(LIB)Event.h
		g++ $(LIB)Event.cpp -c -o $(LIB)Event.o
