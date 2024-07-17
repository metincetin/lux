//
// Created by metin on 6/8/24.
//

#ifndef MEMORY_H
#define MEMORY_H
#include <any>


namespace lux {
    class memory {
    public:
        static void allocate(std::any obj);

        static void* allocate(std::size_t size);
        static void free(void*, std::size_t);
        static void free(std::size_t);

        static std::size_t getUsage() { return m_allocated; }

    private:
        static std::size_t m_allocated;
    };

}


#endif //MEMORY_H
