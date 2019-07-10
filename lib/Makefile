all: bmain.o bPixel.o bImage.o
	g++ bmain.o bPixel.o bImage.o -o exe
	./exe
bmain.o: main.cpp
	g++ -c main.cpp -o bmain.o
bPixel.o: Pixel.cpp
	g++ -c Pixel.cpp -o bPixel.o
bImage.o: Image.cpp
	g++ -c Image.cpp -o bImage.o
