OBJS = gradient_descent.o \
       perceptron.o

BIN_DIR = binaries
PROGRAMS = $(BIN_DIR)/gradient_descent  $(BIN_DIR)/perceptron



ifeq ($(VERBOSE),1)
	QUIET =
else
	QUIET = @
endif
	  
CXX = g++
CXXFLAGS = -std=c++11 -Wall

%.o: %.cpp 
	@echo "$(notdir $(CURDIR)): C++ $@"
	$(QUIET) $(CXX) $(CXXFLAGS) -o $@ -c $<


all: $(PROGRAMS)

$(BIN_DIR)/perceptron: perceptron.o
	g++ perceptron.o -o $(BIN_DIR)/perceptron
	
$(BIN_DIR)/gradient_descent: gradient_descent.o
	g++ gradient_descent.o -o $(BIN_DIR)/gradient_descent


clean:
	rm -rf *.o
	rm -rf $(PROGRAMS)
