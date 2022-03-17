#ifndef IMAGINATOR_IMAGEDATA_HPP
#define IMAGINATOR_IMAGEDATA_HPP

#include <vector>
#include <limits>
#include <memory>

#include "ImagePixel.hpp"

namespace imaginator
{
    class ImageData
    {
    public:

        enum : size_t
        {
            MIN_WIDTH = std::numeric_limits<size_t>::min(),
            MAX_WIDTH = std::numeric_limits<size_t>::max(),
            MIN_HEIGHT = std::numeric_limits<size_t>::min(),
            MAX_HEIGHT = std::numeric_limits<size_t>::max()
        };

        ImageData(
            size_t width = ImageData::MIN_WIDTH, 
            size_t height = ImageData::MIN_HEIGHT);

        virtual ~ImageData();

        inline ImagePixel& operator()(size_t x, size_t y);

        inline const ImagePixel& operator()(size_t x, size_t y) const;

        inline void setPixel(size_t x, size_t y, const ImagePixel& imagePixel);

        inline ImagePixel& getPixel(size_t x, size_t y);

        inline const ImagePixel& getPixel(size_t x, size_t y) const;

        void setWidth(size_t width);

        inline size_t getWidth() const;

        void setHeight(size_t height);

        inline size_t getHeight() const;

        inline void clear();

        void reset();

    private:

        std::vector<std::vector<ImagePixel>> pixels;

        size_t width;

        size_t height;

        void throwIncorrectArgumentException() const;

        void throwOutOfBoundsException(size_t x, size_t y) const;
    };
}

#endif // IMAGINATOR_IMAGEDATA_HPP