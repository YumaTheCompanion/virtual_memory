#ifndef virtual_memory_hpp
#define virtual_memory_hpp

#include <iostream>
#include <vector>

#define MAGIC_NUMBER            8

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
    
    void ClearMemory();
    void ResetMemory();
    void PrintAvailableMemorySpace();
    void NewString(std::string *&s, const char *text);
    unsigned char * NewString(const char *s, size_t len);
    unsigned char * NewString(const char s, size_t len);
private:
    bool memory_is_allocated;
    unsigned char *tb;
    size_t memory_max_size;
    size_t memory_fullness_index;
};

#endif /* virtual_memory_hpp */
