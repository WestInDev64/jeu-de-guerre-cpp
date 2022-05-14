CXX= g++
CXXFLAGS= -Wall -Wextra -Wpedantic -std=c++17

PROG= la-guerre
VERSION= 0.1

CSRC= main.cpp
HSRC = *.hpp


all: $(PROG)

$(PROG): main.o
	$(CXX) $^ -o $@

%.o: %.cpp $(HSRC)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	@rm -f *.o $(PROG)

