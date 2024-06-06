CC = g++
CFLAGS = -Wall -ggdb3 -std=c++11

HW08: HW08.o NonlinearSolver02.o 
	$(CC) $(CFLAGS) -o HW08 HW08.o NonlinearSolver02.o

HW08.o: HW08.cpp NonlinearSolver02.h Function02.h
	$(CC) $(CFLAGS) -c HW08.cpp

NonlinearSolver02.o: Function02.h NonlinearSolver02.h NonlinearSolver02.cpp
	$(CC) $(CFLAGS) -c NonlinearSolver02.cpp
	
clean:
	rm -rf OptionPricer08 *.o



