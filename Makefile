SOURCES = main.cpp component.cpp servo.cpp

OBJECTS = main.o component.o servo.o

filter: main.cpp
	g++ -o mechSystem main.cpp component.cpp servo.cpp

CXXFLAGS = -std=c++11 -D_GNU_SOURCE -Wall