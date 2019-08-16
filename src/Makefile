CF = -Wall -O3 -std=c++11

all: clean build run

build: main.o Pixel.o Image.o
	g++ Pixel.o Image.o main.o -o exe

main.o: main.cpp
	g++ $(CF) -c main.cpp -o main.o

Image.o: Image.cpp
	g++ $(CF) -c Image.cpp -o Image.o
	
Pixel.o: Pixel.cpp
	g++ $(CF) -c Pixel.cpp -o Pixel.o
	
clean:
	rm -f *.o exe

run:
	./exe
	timeout 1s eog *.bmp
