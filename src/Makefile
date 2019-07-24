CF = -g -O0

all: clean default
default: main.o Pixel.o Image.o
	g++ Pixel.o Image.o main.o -o exe
	./exe
	timeout 1s eog default.bmp

main.o: main.cpp
	g++ $(CF) -c main.cpp -o main.o

Image.o:
	g++ $(CF) -c Image.cpp -o Image.o
	
Pixel.o:
	g++ $(CF) -c Pixel.cpp -o Pixel.o
	
clean:
	rm -f *.o exe

preview:
	eog default.bmp