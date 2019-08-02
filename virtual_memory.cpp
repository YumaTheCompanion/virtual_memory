#include "virtual_memory.hpp"
#include <iostream>
#include <string>

void VM::PrintAvailableMemorySpace() {
    std::cout << "Percent Full: " << ((memory_fullness_index * 100) / memory_max_size) << " %" << std::endl;
}

void VM::NewString(std::string *&s, const char *text) {
    s = new (this->tb + memory_fullness_index) std::string(text);
    memory_fullness_index += sizeof(std::string) + s->size();
}
