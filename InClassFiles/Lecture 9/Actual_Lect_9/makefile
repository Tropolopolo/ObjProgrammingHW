CXXFLAGS = -std=c++17

all: executable

debug: CXXFLAGS += -g
debug: executable

executable: main.o Employee.o Hourly.o Comission.o Salaried.o Sales_Manager.o
	$(CXX) $(CXXFLAGS) main.o Employee.o Hourly.o Comission.o Salaried.o Sales_Manager.o
	./a.out
main.o: Employee.h Hourly.h Comission.h Salaried.h Sales_Manager.h main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
Sales_Manager.o: Sales_Manager.h Sales_Manager.cpp Employee.h Comission.h Salaried.h
	$(CXX) $(CXXFLAGS) -c Sales_Manager.cpp
Salaried.o: Salaried.h Salaried.cpp Employee.h
	$(CXX) $(CXXFLAGS) -c Salaried.cpp
Comission.o: Comission.h Comission.cpp Employee.h
	$(CXX) $(CXXFLAGS) -c Comission.cpp
Hourly.o: Hourly.h Hourly.cpp Employee.h
	$(CXX) $(CXXFLAGS) -c Hourly.cpp
Employee.o: Employee.h Employee.cpp
	$(CXX) $(CXXFLAGS) -c Employee.cpp
clean:
	rm -f *.o a.out
