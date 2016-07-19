#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include "utils.h"

const std::string usage =
    "Usage: \n"
    "\t grab_memory COUNT UNIT\n\n"
    "Grab 1000 megabytes :\n"
    "\t grab_memory 10000 M\n"
    "Grab 30000 bytes :\n"
    "\t grab_memory 20000 B\n"
    "Grab 2 gigabytes :\n"
    "\t grab_memory 2 G\n";

const std::string bytes = "B";
const std::string megabytes = "M";
const std::string gigabytes = "G";

enum Unit { INVALID_UNIT = -1, BYTES, MEGABYTES, GIGABYTES };

bool is_number(const std::string& str) {
  return str.find_first_not_of("0123456789") == std::string::npos;
}

Unit parse_unit(const std::string& unit) {
  if (unit == bytes) return BYTES;
  if (unit == megabytes) return MEGABYTES;
  if (unit == gigabytes) return GIGABYTES;
  return INVALID_UNIT;
}

ssize_t in_bytes(ssize_t count, Unit unit) {
  assert(unit != INVALID_UNIT);
  static const ssize_t b_in_mb = 1048576;
  static const ssize_t b_in_gb = 1073741824;
  switch (unit) {
    case BYTES: {
      return count;
    }
    case MEGABYTES: {
      return count * b_in_mb;
    }
    case GIGABYTES: {
      return count * b_in_gb;
    }
    default: { return -1; }
  }
}

volatile char* alocate(ssize_t size) {
  volatile char* data = new char[size];
  std::fill_n(data, size, '\0');
  return data;
}

void dealocate(volatile char* data) { delete[] data; }

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << usage << std::endl;
    return 1;
  }
  std::string s_count(argv[1]);
  if (!is_number(s_count)) {
    std::cout << usage << std::endl;
    return 2;
  }
  const ssize_t count = std::atoi(s_count.c_str());
  const Unit unit = parse_unit(argv[2]);
  if (unit == INVALID_UNIT) {
    std::cout << usage << std::endl;
    return 2;
  }

  const ssize_t count_in_bytes = in_bytes(count, unit);
  print_memory_usage();
  std::cout << "Alocate " << count_in_bytes << " bytes" << std::endl;
  volatile char* data = alocate(count_in_bytes);
  print_memory_usage();
  std::cout << "Press Enter to dealocate" << std::endl;
  any_key();
  dealocate(data);
  print_memory_usage();
}