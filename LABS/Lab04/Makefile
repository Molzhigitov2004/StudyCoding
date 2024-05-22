
CPP = g++

Exec = .
Source = .

Libs =

Options = -std=c++20 -Wall -pedantic -pedantic-errors -Wno-unused-label

# Linking:

$(Exec)/rpn : $(Source)/rpn.o $(Source)/input.o $(Source)/filereader.o
	$(CPP) $(Options) -o $(Exec)/rpn $(Source)/rpn.o $(Source)/input.o $(Source)/filereader.o $(Libs)

# Compiling the source files:

$(Source)/rpn.o : $(Source)/rpn.cpp $(Source)/filereader.h $(Source)/input.h $(Source)/printstack.h $(Source)/rpn_error.h
	$(CPP) -c $(Options) $(Source)/rpn.cpp -o $(Source)/rpn.o

$(Source)/input.o : $(Source)/input.cpp $(Source)/dfa.h $(Source)/filereader.h $(Source)/input.h
	$(CPP) -c $(Options) $(Source)/input.cpp -o $(Source)/input.o

$(Source)/filereader.o : $(Source)/filereader.cpp $(Source)/filereader.h
	$(CPP) -c $(Options) $(Source)/filereader.cpp -o $(Source)/filereader.o

