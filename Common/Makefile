include ../makefile_common

# File names
LIB = $(LIB_DIR)/Common.so
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

ifneq ($(SRC), '')

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

endif
