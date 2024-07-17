#ifndef COLOR_HPP
#define COLOR_HPP
namespace lux{

struct Color {
    Color(float r, float g, float b, float a){this->r = r; this->g = g; this->b = b; this->a = a;}

    float r;
    float g;
    float b;
    float a;

    static Color red() { return {1, 0, 0, 1}; };
    static Color white() { return {1, 1, 1, 1}; };
    static Color black() { return {0, 0, 0, 1}; };
};
}
#endif
