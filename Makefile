OBJS = main.o


all: main

main: $(OBJS)
	g++ $(OBJS) -o main

main.o: main.cpp
	g++ -c main.cpp

