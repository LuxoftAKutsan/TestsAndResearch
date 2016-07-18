#include <iostream>
#include <functional>


template<class T>
void free_with_swap(T& v) {
	T t;
	std::swap(t, v);
}

void print_memory_usage() {
   std::cout << "Memory usage : " << mem_usage::rss() / 1000 << " Mb." << std::endl;
}

template <typename Container>
void fill_container(Container& container,
	 std::function<typename Container::value_type()> creator,
	 const ssize_t count,
	 void (Container::*push_method)(const typename Container::value_type&) = &Container::push_back
	 ) {
	for(ssize_t i = 0; i < count; ++i) {
		(container.*push_method)(creator());
	}
	std::cout << "Filled. size = " << container.size() << std::endl;
}


template <class Container>
void free_container(Container& container,
					void (Container::*pop_method)() = &Container::pop_back) {
	while(!container.empty()) {
		 (container.*pop_method)();
		std::cout.flush();
	}
	std::cout << "Freed. size = " << container.size() << std::endl;
}

void any_key() {
	std::cout << std::endl;
	std::cout << std::endl;
	// getchar();
}


