CXX= g++
CXXFLAGS= -Wall -Wextra -Wpedantic -std=c++17

PROG= la-guerre
VERSION= 0.1

SRC= $(wildcard *.cpp)
HSRC = *.hpp
OBJ= $(SRC:.cpp=.o)


all: $(PROG)

$(PROG): $(OBJ)
	$(CXX) $^ -o $@

%.o: %.cpp $(HSRC)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	@rm -f *.o *.out $(PROG)

