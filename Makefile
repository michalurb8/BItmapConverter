CF = -Wall -O3 -std=c++11

build: src/main.o src/Pixel.o src/Image.o
	g++ src/Pixel.o src/Image.o src/main.o -o src/exe

main.o: src/main.cpp
	g++ $(CF) -c src/main.cpp -o src/main.o

src/Image.o: src/Image.cpp src/Image.h
	g++ $(CF) -c src/Image.cpp -o src/Image.o
	
src/Pixel.o: src/Pixel.cpp src/Pixel.h
	g++ $(CF) -c src/Pixel.cpp -o src/Pixel.o
	
clean:
	rm -f src/*.o src/exe example.bmp

run: clean build
	src/exe
	timeout 1s eog example.bmp
