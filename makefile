SRC = ./src
INCLUDE = ./src/include
CFLAGS = -I$(INCLUDE)

all: main

main: main.o sequence.o submax.o test.o
	gcc $^ -o $@

main.o: $(SRC)/main.c $(INCLUDE)/sequence.h $(INCLUDE)/submax.h $(INCLUDE)/test.h
	gcc $(CFLAGS) -c $<

sequence.o: $(SRC)/sequence.c $(INCLUDE)/sequence.h
	gcc $(CFLAGS) -c $<

submax.o: $(SRC)/submax.c $(INCLUDE)/submax.h $(INCLUDE)/sequence.h
	gcc $(CFLAGS) -c $<

test.o: $(SRC)/test.c $(INCLUDE)/test.h
	gcc $(CFLAGS) -c $<

clean:
	rm -f *.o main sequence submax