SOURCE=BinarySearchTree_LeBoeuf_Ryan.cpp
EXE=start

compile:
	g++ -Wall --std=c++11 ${SOURCE} -o ${EXE}
run:
	./${EXE}
clean:
	rm ${EXE}