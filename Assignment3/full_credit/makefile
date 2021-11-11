#Makefile for Planner Project
CXXFLAGS = -std=c++17

executable: mli1200_Animal.o mli1200_main.o
	$(CXX) $(CXXFLAGS) mli1200_main.o mli1200_Animal.o
	./a.out
mli1200_main.o: mli1200_main.cpp mli1200_Animal.h
	$(CXX) $(CXXFLAGS) -c mli1200_main.cpp
mli1200_Animal.o: mli1200_Animal.h mli1200_Animal.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Animal.cpp
clean:
	rm -f *.o a.out
