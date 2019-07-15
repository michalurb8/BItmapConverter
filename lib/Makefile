all: main.o Pixel.o Image.o
	g++ ../out/main.o ../out/Pixel.o ../out/Image.o -o ../out/exe
	../out/exe
main.o: main.cpp
	g++ -c main.cpp -o ../out/main.o
Pixel.o: Pixel.cpp
	g++ -c Pixel.cpp -o ../out/Pixel.o
Image.o: Image.cpp
	g++ -c Image.cpp -o ../out/Image.o
