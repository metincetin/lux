//
// Created by metin on 6/9/24.
//

#ifndef VERTEX_STRUCTURE_H
#define VERTEX_STRUCTURE_H
#include <tuple>
#include <vector>

namespace lux {
    enum Entry {
        Position,
        Normal,
        VertexColor,
        TexCoord0,
        TexCoord1,
        TexCoord2,
        TexCoord3,
        TexCoord4,
        TexCoord5,
    };

    class VertexStructure {
    public:

        void add(Entry entry, size_t size) {
            m_entries.push_back(std::make_tuple(entry, size));
        }

        size_t getSize() const { return m_entries.size(); }
        std::tuple<Entry, size_t> getEntry(size_t index) const { return m_entries[index]; }

    private:
        std::vector<std::tuple<Entry, size_t>> m_entries;
    };
}


#endif //VERTEX_STRUCTURE_H
