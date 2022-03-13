#include "ImageData.hpp"

#include <stdexcept>
#include <string>

namespace imaginator
{
    ImageData::ImageData(size_t width, size_t height) :
        m_width(width),
        m_height(height),
        m_pixels(std::vector<std::vector<ImagePixel>>(m_width))
    {
        throwIncorrectArgumentException();

        if (m_width > 0)
            for (size_t i = 0; i < m_width; i++)
                m_pixels[i] = std::vector<ImagePixel>(m_height);
    }

    ImageData::~ImageData() 
    {
        clear();
    }

    ImagePixel& ImageData::operator()(size_t x, size_t y)
    {
        return getPixel(x, y);
    }

    const ImagePixel& ImageData::operator()(size_t x, size_t y) const
    {
        return getPixel(x, y);
    }

    void ImageData::putPixel(size_t x, size_t y, const ImagePixel& imagePixel)
    {
        throwOutOfBoundsException(x, y);
        m_pixels[x][y] = imagePixel;
    }

    ImagePixel& ImageData::getPixel(size_t x, size_t y)
    {
        throwOutOfBoundsException(x, y);

        return m_pixels[x][y];
    }

    const ImagePixel& ImageData::getPixel(size_t x, size_t y) const
    {
        throwOutOfBoundsException(x, y);

        return m_pixels[x][y];
    }

    void ImageData::setWidth(size_t width)
    {
        if (width > m_width)
            for (size_t i = 0, count = width - m_width; i < count; i++)
                m_pixels.push_back(std::vector<ImagePixel>(m_height));
        else if (width < m_width)
            for (size_t i = 0, count = m_width - width; i < count; i++)
                m_pixels.pop_back();

        m_width = width;
    }

    size_t ImageData::getWidth() const
    {
        return m_width;
    }

    void ImageData::setHeight(size_t height)
    {
        if (height > m_height)
            for (size_t i = 0; i < m_width; i++)
                for (size_t j = 0, count = height - m_height; j < count; j++)
                    m_pixels[i].push_back(ImagePixel());
        else if (height < m_height)
            for (size_t i = 0; i < m_width; i++)
                for (size_t j = 0, count = m_height - height; j < count; j++)
                    m_pixels[i].pop_back();

        m_height = height;
    }

    void ImageData::clear()
    {
        m_pixels.clear();
    }

    void ImageData::throwIncorrectArgumentException() const
    {
        if ((m_width == 0 && m_height > 0) || (m_height == 0 && m_width > 0))
            throw std::invalid_argument(
                std::string("[Error] imaginator::ImageData: incorrect argument(s): ") +
                std::string("\"width\"") + std::to_string(m_width) +
                std::string("\"height\"") + std::to_string(m_height) +
                std::string("."));
    }

    void ImageData::throwOutOfBoundsException(size_t x, size_t y) const
    {
        if (x > m_width || y > m_height)
            throw std::invalid_argument(
                std::string("[Error] imaginator::ImageData: out of bounds: ") +
                std::string("width = ") + std::to_string(m_width) +
                std::string(", height = ") + std::to_string(m_height) +
                std::string(", x = ") + std::to_string(x) +
                std::string(", y = ") + std::to_string(y) +
                std::string("."));
    }
}