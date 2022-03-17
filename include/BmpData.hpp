#ifndef IMAGINATOR_BMPDATA_HPP
#define IMAGINATOR_BMPDATA_HPP

#include "ImageData.hpp"

namespace imaginator
{
    class BmpData : public ImageData
    {
    public:

        BmpData(size_t width = ImageData::MIN_WIDTH, size_t height = ImageData::MIN_HEIGHT);

        virtual ~BmpData();
    };
}

#endif // IMAGINATOR_BMPDATA_HPP