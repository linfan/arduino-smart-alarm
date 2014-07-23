RUNABLE=func_test
SOURCE=$(wildcard *.cc)
OBJ=$(SOURCE:.cc=.o)
DEPENDENCE=device_list.ino clock.ino json_parser.ino
DEPENDENCE_OBJ=$(DEPENDENCE:.ino=.obj)

all: compile run

%.o: %.cc
	g++ -c -I.. -o $@ -Wno-parentheses -Wno-deprecated-writable-strings -Wno-delete-non-virtual-dtor $<

%.obj: ../%.ino
	g++ -c -I.. -o $@ -Wno-parentheses -Wno-deprecated-writable-strings -Wno-delete-non-virtual-dtor -x c++ $<

compile: $(OBJ) $(DEPENDENCE_OBJ)
	g++ -o $(RUNABLE) $^

clean:
	rm -f $(RUNABLE) *.o *.obj

run:
	./$(RUNABLE)
