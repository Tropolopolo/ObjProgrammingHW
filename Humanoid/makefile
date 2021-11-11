#Makefile for Planner Project
CXXFLAGS = -std=c++17
executable: Humanoid.o Main.o
	$(CXX) $(CXXFLAGS) Main.o Humanoid.o
	./a.out 
main.o: Main.cpp Humanoid.h
	$(CXX) $(CXXFLAGS) -c Main.cpp
Animal.o: Humanoid.h Humanoid.cpp
	$(CXX) $(CXXFLAGS) -c Humanoid.cpp
clean:
	rm -f *.o a.out