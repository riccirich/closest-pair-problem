SRC_DIR = src
SRC_INCLUDE = include
INCLUDE = -I {SRC_INCLUDE}

%.o: %.cpp
	g++ -std=c++11 -c $< -o $@

.PHONY: tests
tests: main.cpp $(SRC_DIR)
	g++ -std=c++11 $(INCLUDE) -o tests main.cpp \
	$(SRC_DIR)/*.cpp

.PHONY: clean
clean:
	rm -rf *~ *.o *.txt *.