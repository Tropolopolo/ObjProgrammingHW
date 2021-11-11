#Makefile for Planner Project
CXXFLAGS = -std=c++17

executable: mli1200_Animal.o mli1200_main.o mli1200_Zoo.o
	$(CXX) $(CXXFLAGS) mli1200_main.o mli1200_Animal.o mli1200_Zoo.o
	#gdb ./a.out
	./a.out

mli1200_main.o: mli1200_main.cpp mli1200_Animal.h
	$(CXX) $(CXXFLAGS) -c mli1200_main.cpp

mli1200_Animal.o: mli1200_Animal.h mli1200_Animal.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Animal.cpp

mli1200_Zoo.o: mli1200_Zoo.h mli1200_Zoo.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Zoo.cpp

clean:
	rm -f *.o a.out
