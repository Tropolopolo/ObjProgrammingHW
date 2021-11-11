CXXFLAGS = -std=c++17

all: executable

debug: CXXFLAGS += -g
debug: executable

executable: mli1200_main.o mli1200_Animal.o mli1200_Terrestrial.o mli1200_Aquatic.o mli1200_Amphibious.o mli1200_Avian.o
	$(CXX) $(CXXFLAGS) mli1200_main.o mli1200_Animal.o mli1200_Terrestrial.o mli1200_Aquatic.o mli1200_Amphibious.o mli1200_Avian.o
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

clean:
	rm -f *.o a.out
