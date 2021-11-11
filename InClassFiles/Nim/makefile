CXXFLAGS = --std=c++11
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: main_window

debug: CXXFLAGS += -g
debug: main_window

main_window: main.o main_window.o nim.o
	$(CXX) $(CXXFLAGS) -o nim main.o main_window.o nim.o $(GTKFLAGS)

main.o: main.cpp main_window.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS)

main_window.o: main_window.cpp main_window.h
	$(CXX) $(CXXFLAGS) -c main_window.cpp $(GTKFLAGS)

nim.o: nim.cpp nim.h
	$(CXX) $(CXXFLAGS) -c nim.cpp $(GTKFLAGS)

clean:
	-rm -f *.o *.gch *~ nim
