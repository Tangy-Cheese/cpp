#pragma once

#include <vector>
#include <stddef.h>
#include <array>
#include <string>
#include <cstdint>
#include <iostream>

struct Colour
{
    std::uint8_t r;
    std::uint8_t g;
    std::uint8_t b;
};

std::ostream &operator<<(std::ostream &os, const Colour &c);

// Convenience constants for defining basic colours
namespace Colours
{
    // inline used to prevent conflicts in the One Definition Rule
    inline const Colour Black{0, 0, 0};
    inline const Colour Red{255, 0, 0};
    inline const Colour Yellow{255, 255, 0};
    inline const Colour Green{0, 255, 0};
    inline const Colour Blue{0, 0, 255};
    inline const Colour White{255, 255, 255};
}

class Image
{
public:
    Image(std::size_t x, std::size_t y);

    /// @brief Save image to a (human readable) .ppm file
    /// @param filename
    void Save(std::string filename);

    /// @brief Get the colour at a given location.
    /// @param x
    /// @param y
    /// @return Returns a mutable reference for reading or setting.
    Colour &operator()(std::size_t x, std::size_t y);

    std::size_t getWidth();
    std::size_t getHeight();

private:
    std::vector<Colour> buffer;
    std::size_t width, height;
};