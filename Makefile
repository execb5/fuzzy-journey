IDIR = ./include
SDIR = ./src
ODIR = ./obj

CC = g++
CFLAGS = -std=c++11 -I$(IDIR)

_DEPS = datafile.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o datafile.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean run

run: main
	./main

clean:
	rm -f datafile.part
	rm -f $(ODIR)/*.o 
	rm -f main
