CXXFLAGS = -std=c++17

all: executable

debug: CXXFLAGS += -g
debug: executable

executable: mli1200_main.o mli1200_Animal.o mli1200_Terrestrial.o mli1200_Aquatic.o mli1200_Amphibious.o mli1200_Avian.o mli1200_Zoo.o mli1200_Controller.o mli1200_View.o mli1200_Save.o
	$(CXX) $(CXXFLAGS) mli1200_main.o mli1200_Animal.o mli1200_Terrestrial.o mli1200_Aquatic.o mli1200_Amphibious.o mli1200_Avian.o mli1200_Zoo.o mli1200_Controller.o mli1200_View.o mli1200_Save.o
	./a.out

main.o: mli1200_Animal.h mli1200_Terrestrial.h mli1200_Aquatic.h mli1200_Amphibious.h mli1200_Avian.h mli1200_main.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_main.cpp

Animal.o: mli1200_Animal.h mli1200_Animal.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Animal.cpp

Terrestrial.o: mli1200_Terrestrial.h mli1200_Terrestrial.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Terrestrial.cpp

Aquatic.o: mli1200_Aquatic.h mli1200_Aquatic.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Aquatic.cpp

Amphibious.o: mli1200_Amphibious.h mli1200_Amphibious.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Amphibious.cpp

Avian.o: mli1200_Avian.h mli1200_Avian.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Avian.cpp

Zoo.o: mli1200_Zoo.h mli1200_Zoo.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Zoo.cpp

Controller.o: mli1200_Controller.h mli1200_Controller.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Controller.cpp

View.o: mli1200_View.h mli1200_View.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_View.cpp

Save.o: mli1200_Save.h mli1200_Save.cpp
	$(CXX) $(CXXFLAGS) -c mli1200_Save.cpp

clean:
	rm -f *.o a.out
