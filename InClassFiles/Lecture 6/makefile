#Makefile for Planner Project
CXXFLAGS = -std=c++17

executable: Date.o main.o Planner.o
	$(CXX) $(CXXFLAGS) main.o Date.o Planner.o
	./a.out 
main.o: main.cpp Date.h Planner.h
	$(CXX) $(CXXFLAGS) -c main.cpp
Planner.o: Planner.h Planner.cpp Date.h
	$(CXX) $(CXXFLAGS) -c Planner.cpp
Date.o: Date.h Date.cpp
	$(CXX) $(CXXFLAGS) -c Date.cpp
clean:
	rm -f *.o a.out
