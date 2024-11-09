LIB=./Classes/

Test3:	Test3.cpp $(LIB)Timing.o $(LIB)Event.o $(LIB)Time.o 
		g++ Test3.cpp $(LIB)Timing.o $(LIB)Event.o $(LIB)Time.o  -o Test3

$(LIB)Event.o:	$(LIB)Event.cpp $(LIB)Event.h
		g++ $(LIB)Event.cpp -c -o $(LIB)Event.o
$(LIB)Time.o: $(LIB)Time.cpp $(LIB)Time.h
		g++ $(LIB)Time.cpp -c -o $(LIB)Time.o
$(LIB)Timing.o:	$(LIB)Timing.cpp $(LIB)Timing.h
		g++ $(LIB)Timing.cpp -c -o $(LIB)Timing.o

