include ../makefile_common

# File names
LIB = $(LIB_DIR)/Lazy.so
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

$(LIB): $(OBJ)
	$(AT) echo "Linking " $@
	$(AT) $(CC) -shared $(LFLAGS) $< -o $@

# Generic rule
%.o : %.cpp
	$(AT) echo "Compiling " $<
	$(AT) $(CC) -c $(CFLAGS) $< -o $@

clean:
	$(AT) echo "Deleting objects..."
	$(AT) rm -f $(OBJ) $(LIB)
