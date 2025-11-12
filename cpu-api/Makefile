clean:
	rm p1 p2 p3

p1:
	gcc -o p1 p1.c -Wall

p2:
	gcc -o p2 p2.c -Wall

p3:
	gcc -o p3 p3.c -Wall

build: p1 p2 p3

run: build
	./p1 & ./p2 ./p3
