include ../makefile_common

# File names
LIB = $(LIB_DIR)/Sequence.so
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

# Main target
$(LIB): $(OBJ)
	$(AT) echo "Linking " $@
	$(AT) $(CC) -shared $(LFLAGS) $< -o $@

# Compile rule
%.o : %.cpp
	$(AT) echo "Compiling " $<
	$(AT) $(CC) -c $(CFLAGS) $< -o $@

clean:
	$(AT) echo "Deleting objects..."
	$(AT) rm -f $(LIB) $(OBJ)

