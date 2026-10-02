
OBJECTS = f.o g.o 

fact: $(OBJECTS)
	gcc -g -o fact $(OBJECTS)


f.o : f.c
	gcc -c -g -ansi -Wall f.c

g.o : g.c
	gcc -c -g -ansi -Wall g.c

clean:
	rm *.o fact
