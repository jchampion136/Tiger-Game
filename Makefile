COMPILER = g++
OPTIONS = -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp Hand.cpp Deck.cpp Card.cpp
	$(CXX) $(OPTIONS) main.cpp Hand.cpp Deck.cpp Card.cpp -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM)

