### Make file

all:
	gcc -std=c99 classics.c -o classics_c -lm
	./classics_c 51
	cp classics.c classics.cpp
	gcc -Weffc++ classics.cpp -o classics_cpp -lm
	./classics_cpp 51
clean:
	rm classics_c classics_cpp classics.cpp