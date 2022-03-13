#ifndef IMAGINATOR_IMAGEDATA_HPP
#define IMAGINATOR_IMAGEDATA_HPP

#include <vector>

#include "ImagePixel.hpp"

namespace imaginator
{
    class ImageData
    {
    public:

        ImageData(size_t width = 0, size_t height = 0);

        virtual ~ImageData();

        ImagePixel& operator()(size_t x, size_t y);

        const ImagePixel& operator()(size_t x, size_t y) const;

        void putPixel(size_t x, size_t y, const ImagePixel& imagePixel);

        ImagePixel& getPixel(size_t x, size_t y);

        const ImagePixel& getPixel(size_t x, size_t y) const;

        void setWidth(size_t width);

        size_t getWidth() const;

        void setHeight(size_t height);

        size_t getHeight() const;

        void clear();

    private:

        std::vector<std::vector<ImagePixel>> m_pixels;

        size_t m_width;

        size_t m_height;

        void throwIncorrectArgumentException() const;

        void throwOutOfBoundsException(size_t x, size_t y) const;
    };
}

#endif // IMAGINATOR_IMAGEDATA_HPP