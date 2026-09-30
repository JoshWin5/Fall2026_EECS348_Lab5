cc =g++
CFLAGS = -Wall -Wextra -Wfatal-errors

all: program

program: Joshua_Nguyen_Lab3.cpp
	$(CXX) $(CXXFLAGS) Joshua_Nguyen_Lab3.cpp -o program

clean:
	rm -f program