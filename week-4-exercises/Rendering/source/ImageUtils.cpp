#include "ImageUtils.h"
#include <vector>
#include <stddef.h>
#include <array>
#include <string>
#include <fstream>
#include <stdexcept>

using std::vector, std::array, std::string, std::fstream, std::size_t;

std::ostream &operator<<(std::ostream &os, const Colour &c)
{
    os << static_cast<int>(c.r) << " " << static_cast<int>(c.g) << " " << static_cast<int>(c.b);
    return os;
}

Image::Image(size_t x, size_t y) : width(x), height(y), buffer(vector<Colour>(x * y, Colours::Black)) {}

void Image::Save(string filename)
{
    fstream file(filename, std::ios::out);
    // file header
    file << "P3\n"
         << width << " " << height << "\n255\n";

    for (auto &c : buffer)
    {
        file << c << "\n";
    }
}

Colour &Image::operator()(std::size_t x, std::size_t y)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
    {
        throw std::range_error("Pixel coordinates out of range of image.");
    }
    std::size_t y_inv = height - 1 - y;
    return buffer[y_inv * width + x];
}

std::size_t Image::getWidth() { return width; }
std::size_t Image::getHeight() { return height; }