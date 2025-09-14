OPT=-O0
DEBUG=-g
LIBS=
FLAGS=

BUILDDIR=./build
INCLUDEDIRS=-I.

#.PHONY: buildandrun
#buildandrun: binary
#	$(BINARY)

.PHONY: test
test: $(BUILDDIR) testbin
	gcc $(DEBUG) -o -fpic -shared -o build/example.so test/example.c 
	$(BUILDDIR)/testbin $(BUILDDIR)/example.so

.PHONY: testbin
testbin: 
	gcc lib/c_test_suite/test.c $(OPT) $(DEBUG) $(LIBS) $(FLAGS) $(INCLUDEDIRS) -o $(BUILDDIR)/testbin 


$(BUILDDIR):
	@mkdir $(BUILDDIR)
	@echo "*" > $(BUILDDIR)/.gitignore
	@echo "!.gitignore" >> $(BUILDDIR)/.gitignore

.PHONY : clean
clean: 
	rm -rf $(BUILDDIR)
	rm -f compile_commands.json
