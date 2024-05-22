

# Nim

CPP = g++

Exec = .
Source = .

Libs =

Options = -std=c++20 -Wall -pedantic -pedantic-errors

# Linking:

$(Exec)/nim : $(Source)/nim.o $(Source)/state.o
	$(CPP) $(Options) -o $(Exec)/nim $(Source)/nim.o $(Source)/state.o $(Libs)

# Compiling the source files:

$(Source)/nim.o : $(Source)/nim.cpp $(Source)/move.h $(Source)/state.h
	$(CPP) -c $(Options) $(Source)/nim.cpp -o $(Source)/nim.o

$(Source)/state.o : $(Source)/state.cpp $(Source)/move.h $(Source)/state.h
	$(CPP) -c $(Options) $(Source)/state.cpp -o $(Source)/state.o

