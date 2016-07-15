//#include "new_delete_redefine.h"

#include <iostream>
#include <queue>
#include <string>
#include <list>
#include <vector>
#include <functional>
#include "memory_usage.h"
#include "utils.h"


static const std::string string_to_fill = "Find leaks in this fucking SDL!";
static size_t count_of_strings = 1000000u;
static size_t time_to_sleep = 1000000; // microseconds

void list_test() {
	std::cout << "List Test" << std::endl;
	std::list<std::string> l;
	print_memory_usage();
	auto creator = [](){return string_to_fill;};
	fill_container(l, creator, count_of_strings);
	print_memory_usage();
	free_container(l);
	print_memory_usage();
	print_memory_usage();
	std::cout << "Fill secondary" << std::endl;
	fill_container(l, creator, count_of_strings);
	print_memory_usage();
	free_container(l);
	print_memory_usage();
	print_memory_usage();
	any_key();
}

void queue_test() {
	std::cout << "Queue Test" << std::endl;
	std::queue<std::string> q;
	print_memory_usage();
	auto creator = [](){return string_to_fill;};
	fill_container(q, creator, count_of_strings, &std::queue<std::string>::push);
	print_memory_usage();
	free_container(q, &std::queue<std::string>::pop);
	print_memory_usage();
	usleep(time_to_sleep);
	print_memory_usage();
	std::cout << "Fill secondary" << std::endl;
	fill_container(q, creator, count_of_strings, &std::queue<std::string>::push);
	print_memory_usage();
	free_container(q, &std::queue<std::string>::pop);
	print_memory_usage();
	print_memory_usage();
	any_key();
}

void vector_test() {
	std::cout << "Vector Test" << std::endl;
	std::vector<std::string> v;
	print_memory_usage();
	auto creator = [](){return string_to_fill;};
	fill_container(v, creator, count_of_strings);
	print_memory_usage();
	free_container(v);
	print_memory_usage();
	usleep(time_to_sleep);
	print_memory_usage();
	fill_container(v, creator, count_of_strings);
	print_memory_usage();
	free_container(v);
	print_memory_usage();
	print_memory_usage();
	any_key();
}


int main() {
	list_test();
	queue_test();
	vector_test();
	return 0;
}