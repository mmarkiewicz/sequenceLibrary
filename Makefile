include makefile_common

MODULES = Lazy \
          Sequence \
          Main

LIBS = $(MODULES:%=%.lib)
LIBS_CLEAN = $(LIBS:.lib=.libclean)

EXE = $(BIN_DIR)/seq.e

default: $(EXE)

clean: $(LIBS_CLEAN)

$(EXE): $(LIBS)
	$(AT) echo "Generating executable file"
	$(AT) $(CC) $(LFLAGS) $(LIBS:%.lib=$(LIB_DIR)/%.so) -o $@

%.lib: 
	$(AT) cd $(MAIN_DIR)/$(@:.lib=) && $(MAKE)

%.libclean:
	$(AT) cd $(MAIN_DIR)/$(@:.libclean=) && $(MAKE) clean


