OBJECTS = fact.o fact_iter.o fact_recurs.o

fact: $(OBJECTS)
	gcc -g -o fact $(OBJECTS) -pthread

fact.o: fact.c fact.h
	gcc -c -g -Wall fact.c

fact_iter.o: fact_iter.c fact.h
	gcc -c -g -Wall fact_iter.c

fact_recurs.o: fact_recurs.c fact.h
	gcc -c -g -Wall fact_recurs.c

clean:
	rm -f *.o fact