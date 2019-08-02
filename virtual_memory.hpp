#ifndef virtual_memory_hpp
#define virtual_memory_hpp

#include <iostream>
#include <vector>

class VM {
public:
    VM(size_t mem_alloc) {
        memory_fullness_index = 0;
        memory_max_size = mem_alloc;
        tb = new unsigned char[memory_max_size];
        memory_is_allocated = true;
    }
    ~VM() {
        if(memory_is_allocated) {
            delete [] tb;
            memory_is_allocated = false;
        }
        std::cout << "Virtual Memory is destroyed.\n";
    }
    
    void PrintAvailableMemorySpace();
    void NewString(std::string *&s, const char *text);
private:
    bool memory_is_allocated;
    unsigned char *tb;
    size_t memory_max_size;
    size_t memory_fullness_index;
};

#endif /* virtual_memory_hpp */
