all: main.o Pixel.o Image.o
	g++ ./main.o ./Pixel.o ./Image.o -o ./exe
	./exe
	timeout 1s eog default.bmp
	 
main.o: main.cpp
	g++ -c main.cpp -o ./main.o

Pixel.o: Pixel.cpp
	g++ -c Pixel.cpp -o ./Pixel.o

Image.o: Image.cpp
	g++ -c Image.cpp -o ./Image.o

clean:
	rm *.o

preview:
	eog default.bmp
