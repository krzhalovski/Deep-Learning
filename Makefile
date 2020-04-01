OBJS = gradient_descent.o \
       perceptron.o

PROGRAMS = gradient_descent 

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


all: gradient_descent perceptron

perceptron: perceptron.o
	g++ perceptron.o -o perceptron
	
gradient_descent: gradient_descent.o
	g++ gradient_descent.o -o gradient_descent


clean:
	rm -rf *.o
