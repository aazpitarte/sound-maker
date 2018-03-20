CC = g++
FILES = example.cpp sound_maker.cpp 
FLAGS = -std=c++11 -g
EXE = run.exe

all: $(FILES) sound_maker.hpp
	$(CC) $(FILES) -o $(EXE) $(FLAGS)

clean:
	rm run.exe
	
