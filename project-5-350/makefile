SRC=LeBoeuf_Ryan_Quicksort.cpp
EXE=start
C_FLAGS=-Wall --std=c++11
V_FLAGS=--leak-check=full

FILEIN=input.txt
FILEOUT=output.txt

compile:
	g++ ${C_FLAGS} ${SRC} -o ${EXE}
run:
	./${EXE} ${FILEIN} ${FILEOUT}
clean:
	rm ./${EXE}
