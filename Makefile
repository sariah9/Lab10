CXX=g++
CXXFLAGS = -Wall -g -std=c++11

output: main.o Runtime.o 
	$(CXX) $(CXXFLAGS) -o output main.o Runtime.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Runtime.o: Runtime.cpp Runtime.hpp
	$(CXX) $(CXXFLAGS) -c Runtime.cpp

zip:
	zip -D Group14.zip *.cpp *.hpp Makefile *.pdf 

debug:
	@valgrind --tool=memcheck --leak-check=full --show-reachable=yes --show-leak-kinds=all --track-origins=yes ./main
  
clean:
	rm *.o output
