//#include "new_delete_redefine.h"

#include <iostream>
#include <queue>
#include <string>
#include <list>
#include <vector>
#include <functional>
#include <cassert>
#include "memory_usage.h"
#include "utils.h"

static const std::string string_to_fill = "Find leaks in this fucking SDL!";
static size_t count_of_strings = 10000000u;
static size_t time_to_sleep = 1000000;  // microseconds

void measure_mem_twice() {
  print_memory_usage();
  std::cout << "Measure memory secondary" << std::endl;
  print_memory_usage();
}

void list_test() {
  std::cout << "List Test" << std::endl;
  std::list<std::string> l;
  auto creator = []() { return string_to_fill; };

  print_memory_usage();
  fill_container(l, creator, count_of_strings);
  print_memory_usage();

  free_container(l);
  measure_mem_twice();

  std::cout << "Fill List secondary" << std::endl;
  fill_container(l, creator, count_of_strings);
  print_memory_usage();

  free_with_swap(l);
  measure_mem_twice();

  std::cout << "Fill List third time" << std::endl;
  fill_container(l, creator, count_of_strings);
  print_memory_usage();

  l.resize(0);
  std::cout << "List resized to " << l.size() << std::endl;

  measure_mem_twice();

  any_key();
}

void deque_test() {
  std::cout << "Deque Test" << std::endl;
  std::deque<std::string> q;
  auto creator = []() { return string_to_fill; };

  print_memory_usage();
  fill_container(q, creator, count_of_strings);
  print_memory_usage();

  free_container(q);
  measure_mem_twice();

  std::cout << "Fill secondary" << std::endl;
  fill_container(q, creator, count_of_strings);
  print_memory_usage();

  free_with_swap(q);
  measure_mem_twice();

  std::cout << "Fill thirt time" << std::endl;
  fill_container(q, creator, count_of_strings);
  print_memory_usage();

  q.resize(0);
  std::cout << "Queue freed with resize " << q.size() << std::endl;
  measure_mem_twice();

  any_key();
}

void queue_test() {
  std::cout << "Queue Test" << std::endl;
  std::queue<std::string> q;
  auto creator = []() { return string_to_fill; };

  print_memory_usage();
  fill_container(q, creator, count_of_strings, &std::queue<std::string>::push);
  measure_mem_twice();
  free_container(q, &std::queue<std::string>::pop);
  measure_mem_twice();

  std::cout << "Fill secondary" << std::endl;
  fill_container(q, creator, count_of_strings, &std::queue<std::string>::push);
  print_memory_usage();
  free_with_swap(q);
  measure_mem_twice();

  any_key();
}

void vector_test() {
  std::cout << "Vector Test" << std::endl;
  std::vector<std::string> v;
  auto creator = []() { return string_to_fill; };

  print_memory_usage();
  fill_container(v, creator, count_of_strings);
  print_memory_usage();

  free_container(v);
  measure_mem_twice();

  std::cout << "Fill secondary" << std::endl;
  fill_container(v, creator, count_of_strings);
  print_memory_usage();

  free_with_swap(v);
  measure_mem_twice();

  any_key();
}

void raw_test() {
  std::cout << "Raw test" << std::endl;
  std::string* data = new std::string[count_of_strings];
  for (size_t i = 0; i < count_of_strings; ++i) {
    data[i] = string_to_fill;
  }
  std::cout << "Alocated std::string* with size = " << count_of_strings
            << std::endl;
  print_memory_usage();
  delete[] data;
  std::cout << "Memory Freed" << std::endl;
  measure_mem_twice();
  any_key();
}

static ssize_t counter = 0;
class ComplicatedObject {
  int index_;
  std::string data_;

 public:
  ComplicatedObject(int index) : index_(index), data_(string_to_fill) {
    counter++;
  }
  ComplicatedObject(const ComplicatedObject& other)
      : index_(other.index_), data_(other.data_) {
      	counter++;
      }

  ~ComplicatedObject() {
    counter--;
  }
};

void queue_of_complicated_object() {
  std::cout << "Queue of complicated objects test";
  std::queue<ComplicatedObject> q;
  auto creator = []() {
    static int i = 0;
    return ComplicatedObject(i++);
  };

  print_memory_usage();
  fill_container(q, creator, count_of_strings, &std::queue<ComplicatedObject>::push);
  assert(counter == count_of_strings);
  print_memory_usage();

  free_container(q, &std::queue<ComplicatedObject>::pop);
  measure_mem_twice();

  fill_container(q, creator, count_of_strings, &std::queue<ComplicatedObject>::push);
  assert(counter == count_of_strings);
  print_memory_usage();

  free_with_swap(q);
  assert(counter == count_of_strings);
  measure_mem_twice();
  assert(counter == 0);
  std::cout << "Finish queue_of_complicated_object" << std::endl;
}

int main() {
  vector_test();
  list_test();
  deque_test();
  queue_test();
  raw_test();
  queue_of_complicated_object();
  return 0;
}
