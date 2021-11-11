CXXFLAGS = -std=c++17
#GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
#GTKFLAGS example: $(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS)

all: executable

debug: CXXFLAGS += -g
debug: executable

executable: Monster.o Trainer.o Controller.o View.o FileHandle.o Sort.o main.o
	$(CXX) $(CXXFLAGS) Monster.o Trainer.o Controller.o View.o FileHandle.o Sort.o main.o
	./a.out

main.o: Controller.h View.h Monster.h Trainer.h main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Monster.o: Monster.h Monster.cpp
	$(CXX) $(CXXFLAGS) -c Monster.cpp

Trainer.o: Trainer.h Trainer.cpp
	$(CXX) $(CXXFLAGS) -c Trainer.cpp

Controller.o: Controller.h Controller.cpp
	$(CXX) $(CXXFLAGS) -c Controller.cpp

View.o: View.h View.cpp
	$(CXX) $(CXXFLAGS) -c View.cpp

FileHandle.o: FileHandle.h FileHandle.cpp
	$(CXX) $(CXXFLAGS) -c FileHandle.cpp

Sort.o: Sort.h Sort.cpp
	$(CXX) $(CXXFLAGS) -c Sort.cpp

clean:
	rm -f *.o a.out 