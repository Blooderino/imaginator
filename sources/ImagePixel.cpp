#include "ImagePixel.hpp"

namespace imaginator
{
    ImagePixel::ImagePixel(
        byte red /* = MAX_CHANNEL_VALUE */, 
        byte green /* = MAX_CHANNEL_VALUE */, 
        byte blue /* = MAX_CHANNEL_VALUE*/, 
        std::optional<byte> alpha /* = std::nullopt */)
    {
        this->setRed(red);
        this->setGreen(green);
        this->setBlue(blue);
        this->setAlpha(alpha);
    }

    ImagePixel::ImagePixel(const ImagePixel& imagePixel) :
        ImagePixel::ImagePixel(
            imagePixel.getRed(),
            imagePixel.getGreen(),
            imagePixel.getBlue(),
            imagePixel.getAlpha())
    {}

    ImagePixel::~ImagePixel() {}

    void ImagePixel::setRed(byte red)
    {
        this->red = red;
    }

    byte ImagePixel::getRed() const
    {
        return this->red;
    }

    void ImagePixel::setGreen(byte green)
    {
        this->green = green;
    }

    byte ImagePixel::getGreen() const
    {
        return this->green;
    }

    void ImagePixel::setBlue(byte blue)
    {
        this->blue = blue;
    }

    byte ImagePixel::getBlue() const
    {
        return this->blue;
    }

    void ImagePixel::setAlpha(std::optional<byte> alpha)
    {
        this->alpha = alpha;
    }

    std::optional<byte> ImagePixel::getAlpha() const
    {
        return this->alpha;
    }
}