CXXFLAGS = -std=c++17

all: executable

executable: main.o Date.o Planner.o View.o Controller.o
	$(CXX) $(CXXFLAGS) main.o Date.o Planner.o View.o Controller.o
	./a.out
main.o: main.cpp Date.h Planner.h View.h Controller.h
	$(CXX) $(CXXFLAGS) -c main.cpp
Controller.o: Planner.h View.h Date.h Controller.h Controller.cpp
	$(CXX) $(CXXFLAGS) -c Controller.cpp
View.o: Planner.h View.h View.cpp Date.h
	$(CXX) $(CXXFLAGS) -c View.cpp
Planner.o: Planner.h Date.h Planner.cpp
	$(CXX) $(CXXFLAGS) -c Planner.cpp
Date.o: Date.h Date.cpp
	$(CXX) $(CXXFLAGS) -c Date.cpp
clean:
	rm -f *.o a.out
