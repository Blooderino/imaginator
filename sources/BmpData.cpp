#include "BmpData.hpp"

namespace imaginator
{
    BmpData::BmpData(
        size_t width /* = ImageData::MIN_WIDTH */, 
        size_t height /* = ImageData::MIN_HEIGHT */) :
        ImageData::ImageData(width, height)
    {}

    BmpData::~BmpData() {}
}