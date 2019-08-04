#include "virtual_memory.hpp"
#include <iostream>
#include <string>

void VM::ClearMemory() {
    memory_fullness_index = 0;
    for(int i = 0; i < memory_max_size; ++i) {
        this->tb[i] = '\0';
    }
}

void VM::ResetMemory() {
    memory_fullness_index = 0;
    for(int i = 0; i < MAGIC_NUMBER; ++i) {
        this->tb[i] = '\0';
    }
}

void VM::PrintAvailableMemorySpace() {
    std::cout << "Percent Full: " << ((memory_fullness_index * 100) / memory_max_size) << " %" << std::endl;
}

void VM::NewString(std::string *&s, const char *text) {
    s = new (this->tb + memory_fullness_index) std::string(text);
    memory_fullness_index += sizeof(std::string) + s->size();
}

unsigned char * VM::NewString(const char *s, size_t len) {
    for(size_t i = 0; i < len; ++i) {
        this->tb[memory_fullness_index + i] = *(s + i);
    }
    memory_fullness_index += len;
    return &this->tb[memory_fullness_index - len];
}

unsigned char * VM::NewString(const char c, size_t len = 1) {
    for(size_t i = 0; i < len; ++i) {
        this->tb[memory_fullness_index + i] = c;
    }
    memory_fullness_index += len;
    return &this->tb[memory_fullness_index - len];
}
