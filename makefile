SOURCE=BinarySearchTree_LeBoeuf_Ryan.cpp
EXE=start
C_FLAGS=-Wall --std=c++11
V_FLAGS=--leak-check=full

compile:
	g++ ${C_FLAGS} ${SOURCE} -o ${EXE}
run:
	./${EXE}
valgrind:
	valgrind ./${EXE} ${V_FLAGS}
clean:
	rm ${EXE}