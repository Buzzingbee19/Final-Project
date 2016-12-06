CXXFLAGS = -Wall -Werror

main: RoboticArm.o main.o
	g++ RoboticArm.o main.o -o main

RoboticArm.o: RoboticArm.cc RoboticArm.h
	g++ $(CXXFLAGS) -c RoboticArm.cc

main.o: main.cc RoboticArm.h
	g++ $(CXXFLAGS) -c main.cc

clean:
	rm *.o

