output: main.o Runtime.o 
	g++ -std=c++0x main.o Runtime.o -o output

main.o: main.cpp
	g++ -c main.cpp

Runtime.o: Runtime.cpp Runtime.hpp
	g++ -c Runtime.cpp
  
clean:
	rm *.o output
