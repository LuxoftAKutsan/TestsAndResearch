void* operator new(std::size_t size) {
  void* x = malloc(size);
  //printf("Allocated %ld bytes at %p\n", size, x);
  return x;
 }

void* operator new[](std::size_t size) {
  void* x = operator new[](size);
  //printf("Allocated %ld bytes at %p\n",size, x);
  return x;
}

void operator delete(void* ptr) {
  //printf("Memory deallocation at %p\n", ptr);
  free(ptr);
}

void operator delete[](void* ptr) {
  //printf("Memory deallocation at %p\n", ptr);
  free(ptr);
}
