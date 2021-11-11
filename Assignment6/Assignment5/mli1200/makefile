CXXFLAGS = -std=c++17

all: executable

debug: CXXFLAGS += -g
debug: executable

executable: mli1200_main.o mli1200_Animal.o mli1200_Zoo.o mli1200_View.o mli1200_Controller.o
	$(CXX) $(CXXFLAGS) mli1200_main.o mli1200_Animal.o mli1200_Zoo.o mli1200_View.o mli1200_Controller.o
	./a.out

main.o: mli1200_Controller.h mli1200_main.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_main.cpp

Zoo.o: mli1200_Zoo.h mli1200_Zoo.cpp mli1200_Animal.h
	$(CXX) $(CXXFLAGS) -c mli1200_Zoo.cpp

Animal.o:mli1200_Animal.h mli1200_Animal.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Animal.cpp

View.o: mli1200_View.h mli1200_View.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_View.cpp

Controller.o: mli1200_Controller.h mli1200_Controller.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Controller.cpp

clean:
	rm -f *.o a.out
