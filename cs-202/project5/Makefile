OBJ_FILES = proj5.o MyString.o

all: $(OBJ_FILES)
	g++ $(OBJ_FILES) -o pa7

proj5.o: proj5.cpp
	g++ -c proj5.cpp 

MyString.o: MyString.cpp MyString.h
	g++ -c MyString.cpp 

clean:
	rm *.o pa7

tar: 
	tar cvf p7.tar *.cpp *.h makefile documentation.*
