all:p1

p1:main.o sort.o
	g++ -std=c++11 -o p1 main.o sort.o

main.o:main.cpp
	g++ -std=c++11 -c -O2 main.cpp

sort.o:sort.cpp
	g++ -std=c++11 -c -O2 sort.cpp

clean:
	rm -f *.o p1
