# Makefile

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRCS = main.cpp Document.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = HW7

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX)	$(CXXFLAGS)	-o	$(TARGET)	$(OBJS)
  
# Rule to compile source files
%.o: %.cpp
	$(CXX)	$(CXXFLAGS)	-c	$<	-o	$@