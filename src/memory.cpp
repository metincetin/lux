//
// Created by metin on 6/8/24.
//

#include "memory.h"

#include <any>
#include <cstdlib>

std::size_t lux::memory::m_allocated;

void lux::memory::allocate(std::any obj) {
    m_allocated += sizeof(obj);
}
void* lux::memory::allocate(size_t size) {
    m_allocated += size;
    return malloc(size);
}

void lux::memory::free(void * pointer, size_t size) {
    m_allocated -= size;
    std::free(pointer);
}

