SRC=LeBoeuf_Ryan_Quicksort.cpp LeBoeuf_Ryan_InputFileGenerator.cpp main.cpp
EXE=start
CXX=g++
CFLAGS=-Wall --std=c++11
VFLAGS=--leak-check=full

compile:
	${CXX} ${CFLAGS} ${SRC} -o ${EXE}
run:
	./${EXE}
mem:
	valgrind ${VFLAGS} ./${EXE}
clean:
	rm ./${EXE} ${FILEOUT}
