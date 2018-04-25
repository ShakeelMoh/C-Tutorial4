#My own makefile for Image project

#Declare variables
CC=g++
LIBS=-lm

#First create ".exe" called fibonacci
imageops: Image.o ImageDriver.o
	$(CC) Image.o ImageDriver.o -o imageops $(LIBS)

#Need to make image.o file though
Image.o: Image.cpp Image.h
	$(CC) -c Image.cpp

#And the driver file
ImageDriver.o: ImageDriver.cpp
	$(CC) -c ImageDriver.cpp

#Other rules

#Clean .o and exe
clean:
	@rm -f *.o
	@rm -f imageops

#To run program
run:
	./imageops
