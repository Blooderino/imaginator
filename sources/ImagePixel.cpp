#include "ImagePixel.hpp"

namespace imaginator
{
    ImagePixel::ImagePixel(byte red, byte green, byte blue, std::optional<byte> alpha) :
        m_red(red),
        m_green(green),
        m_blue(blue),
        m_alpha(alpha)
    {}

    ImagePixel::ImagePixel(const ImagePixel& imagePixel) :
        m_red(imagePixel.getRed()),
        m_green(imagePixel.getGreen()),
        m_blue(imagePixel.getBlue()),
        m_alpha(imagePixel.getAlpha())
    {}

    ImagePixel::~ImagePixel() {}

    void ImagePixel::setRed(byte red)
    {
        m_red = red;
    }

    byte ImagePixel::getRed() const
    {
        return m_red;
    }

    void ImagePixel::setGreen(byte green)
    {
        m_green = green;
    }

    byte ImagePixel::getGreen() const
    {
        return m_green;
    }

    void ImagePixel::setBlue(byte blue)
    {
        m_blue = blue;
    }

    byte ImagePixel::getBlue() const
    {
        return m_blue;
    }

    void ImagePixel::setAlpha(std::optional<byte> alpha)
    {
        m_alpha = alpha;
    }

    std::optional<byte> ImagePixel::getAlpha() const
    {
        return m_alpha;
    }
}