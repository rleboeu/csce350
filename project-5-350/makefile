SRC=LeBoeuf_Ryan_Quicksort.cpp
EXE=start
CXX=g++
CFLAGS=-Wall --std=c++11
VFLAGS=--leak-check=full

FILEIN=input.txt
FILEOUT=output.txt

compile:
	${CXX} ${CFLAGS} ${SRC} -o ${EXE}
run:
	./${EXE} ${FILEIN} ${FILEOUT}
mem:
	valgrind ${VFLAGS} ./${EXE} ${FILEIN} ${FILEOUT}
clean:
	rm ./${EXE} ${FILEIN} ${FILEOUT}
