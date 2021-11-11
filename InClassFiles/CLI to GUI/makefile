CXXFLAGS = -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: executable

executable: main.o Date.o Planner.o View.o Controller.o dialog.o
	$(CXX) $(CXXFLAGS) main.o Date.o Planner.o View.o Controller.o dialog.o $(GTKFLAGS)
	./a.out
main.o: main.cpp Date.h Planner.h View.h Controller.h dialog.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS)
Controller.o: Planner.h View.h Date.h dialog.h Controller.h Controller.cpp
	$(CXX) $(CXXFLAGS) -c Controller.cpp $(GTKFLAGS)
dialog.o: dialog.h dialog.cpp
	$(CXX) $(CXXFLAGS) -c dialog.cpp $(GTKFLAGS)
View.o: Planner.h View.h View.cpp dialog.h Date.h
	$(CXX) $(CXXFLAGS) -c View.cpp $(GTKFLAGS)
Planner.o: Planner.h Date.h Planner.cpp
	$(CXX) $(CXXFLAGS) -c Planner.cpp $(GTKFLAGS)
Date.o: Date.h Date.cpp
	$(CXX) $(CXXFLAGS) -c Date.cpp $(GTKFLAGS)
clean:
	rm -f *.o a.out
