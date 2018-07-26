# @author	Jacob Manning
# @brief	Sample makefile

# Compiler
CXX = g++

# Compiler and linker flags
CC_FLAGS := --std=c++11 -Wall
LD_FLAGS := -pthread

# Directories
SRC := src
BIN := bin
OBJ := obj

# These directories need to be present for building
BUILD_DIRS := $(BIN) $(OBJ)

# Get a list of all the `.cc` files in $(SRC)
SOURCES := $(wildcard $(SRC)/*.cc)
# Substitute all instances of $(SRC)/<any pattern>.cc with $(OBJ)/
# <the same pattern as before>.o in $(SOURCES)
OBJECTS := $(patsubst $(SRC)/%.cc, $(OBJ)/%.o, $(SOURCES))
# Get just the source file names without path/extension
TARGETS := $(patsubst $(SRC)/%.cc, $(BIN)/%, $(SOURCES))

# Create directories, compile objects, link executables
all: | $(BUILD_DIRS) $(OBJECTS) $(TARGETS)

# Rule for object files
$(OBJ)/%.o: $(SRC)/%.cc
	$(CXX) -o $@ -c -I $(SRC) $(CC_FLAGS) $<

# Rule for target exectuables
$(BIN)/%: $(OBJ)/%.o
	$(CXX) -o $@ $(LD_FLAGS) $^

# Make necessary directories for building
$(BUILD_DIRS):
	@mkdir -p $@

# Remove the files in the bin directory to clean
clean:
	-rm -r $(BIN) $(OBJ)

.PHONY: all clean $(BUILD_DIRS)

