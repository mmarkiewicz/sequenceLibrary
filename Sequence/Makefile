include ../makefile_common

# File names
LIB = $(LIB_DIR)/libSequence.so
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

CALLBACKS_DIR = Callbacks

CALLBACKS_SRC = $(wildcard $(CALLBACKS_DIR)/*.cpp)
CALLBACKS_OBJ = $(CALLBACKS_SRC:.cpp=.o)

# Main target
$(LIB): $(OBJ) $(CALLBACKS_OBJ)
	$(AT) echo "Linking " $@
	$(AT) $(CC) -shared $(LFLAGS) $< -o $@

# Compile rule
%.o : %.cpp
	$(AT) echo "Compiling " $<
	$(AT) $(CC) -c $(CFLAGS) $< -o $@

clean:
	$(AT) echo "Deleting objects..."
	$(AT) rm -f $(LIB) $(OBJ) $(CALLBACKS_OBJ)

