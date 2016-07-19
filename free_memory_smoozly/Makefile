mem_test: main.cc memory_usage.h new_delete_redefine.h
	g++ ./main.cc --std=c++11 -o mem_test


clean: 
	rm ./mem_test
	rm ./grab_memory

all: mem_test grab_memory
	echo "Done"

run: mem_test
	./mem_test


grab_memory: grab_memory.cc
	g++ ./grab_memory.cc --std=c++11 -o grab_memory

