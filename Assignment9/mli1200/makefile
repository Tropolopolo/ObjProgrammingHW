CXXFLAGS = -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: executable

debug: CXXFLAGS += -g
debug: executable

executable: mli1200_main.o mli1200_Animal.o mli1200_Terrestrial.o mli1200_Aquatic.o mli1200_Amphibious.o mli1200_Avian.o mli1200_Zoo.o mli1200_Controller.o mli1200_View.o mli1200_Dialogs.o
	$(CXX) $(CXXFLAGS) mli1200_main.o mli1200_Animal.o mli1200_Terrestrial.o mli1200_Aquatic.o mli1200_Amphibious.o mli1200_Avian.o mli1200_Zoo.o mli1200_Controller.o mli1200_View.o mli1200_Dialogs.o $(GTKFLAGS)
	./a.out

mli1200_main.o: mli1200_Animal.h mli1200_Terrestrial.h mli1200_Aquatic.h mli1200_Amphibious.h mli1200_Avian.h mli1200_main.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_main.cpp $(GTKFLAGS)

mli1200_Animal.o: mli1200_Animal.h mli1200_Animal.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Animal.cpp $(GTKFLAGS)

mli1200_Terrestrial.o: mli1200_Terrestrial.h mli1200_Terrestrial.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Terrestrial.cpp $(GTKFLAGS)

mli1200_Aquatic.o: mli1200_Aquatic.h mli1200_Aquatic.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Aquatic.cpp $(GTKFLAGS)

mli1200_Amphibious.o: mli1200_Amphibious.h mli1200_Amphibious.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Amphibious.cpp $(GTKFLAGS)

mli1200_Avian.o: mli1200_Avian.h mli1200_Avian.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Avian.cpp $(GTKFLAGS)

mli1200_Zoo.o: mli1200_Zoo.h mli1200_Zoo.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Zoo.cpp $(GTKFLAGS)

mli1200_Controller.o: mli1200_Controller.h mli1200_Controller.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Controller.cpp $(GTKFLAGS)

mli1200_View.o: mli1200_View.h mli1200_View.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_View.cpp $(GTKFLAGS)

mli1200_Dialogs.o: mli1200_Dialogs.h mli1200_Dialogs.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Dialogs.cpp $(GTKFLAGS)

clean:
	rm -f *.o a.out 