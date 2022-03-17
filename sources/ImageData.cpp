#include <stdexcept>
#include <string>
#include <iostream>

#include "ImageData.hpp"

namespace imaginator
{
    ImageData::ImageData(
        size_t width /* = ImageData::MIN_WIDTH */, 
        size_t height /* = ImageData::MIN_HEIGHT */) 
    {
        throwIncorrectArgumentException(width, height);

        this->setWidth(width);
        this->setHeight(height);
        this->pixels.resize(width);
        this->pixels.shrink_to_fit();

        if (width > 0)
            for (size_t i = 0; i < this->getWidth(); i++)
            {
                this->pixels[i] = std::vector<ImagePixel>(this->getHeight());
                this->pixels[i].shrink_to_fit();
            }
    }

    ImageData::~ImageData() 
    {
        this->clear();
    }

    ImagePixel& ImageData::operator()(size_t x, size_t y)
    {
        return this->getPixel(x, y);
    }

    const ImagePixel& ImageData::operator()(size_t x, size_t y) const
    {
        return this->getPixel(x, y);
    }

    void ImageData::setPixel(size_t x, size_t y, const ImagePixel& imagePixel)
    {
        this->throwOutOfBoundsException(x, y, this->getWidth(), this->getHeight());
        this->pixels[x][y] = imagePixel;
    }

    ImagePixel& ImageData::getPixel(size_t x, size_t y)
    {
        this->throwOutOfBoundsException(x, y, this->getWidth(), this->getHeight());

        return this->pixels[x][y];
    }

    const ImagePixel& ImageData::getPixel(size_t x, size_t y) const
    {
        this->throwOutOfBoundsException(x, y, this->getWidth(), this->getHeight());

        return this->pixels[x][y];
    }

    void ImageData::setWidth(size_t width)
    {
        if (width > this->getWidth())
            for (size_t i = 0, count = width - this->getWidth(); i < count; i++)
                this->pixels.push_back(std::vector<ImagePixel>(this->getWidth()));
        else if (width < this->getWidth())
            for (size_t i = 0, count = this->getWidth() - width; i < count; i++)
                this->pixels.pop_back();

        this->width = width;
    }

    size_t ImageData::getWidth() const
    {
        return this->width;
    }

    void ImageData::setHeight(size_t height)
    {
        if (height > this->getHeight())
            for (size_t i = 0; i < this->getWidth(); i++)
                for (size_t j = 0, count = height - this->getHeight(); j < count; j++)
                    this->pixels[i].push_back(ImagePixel());
        else if (height < this->getHeight())
            for (size_t i = 0; i < this->getWidth(); i++)
                for (size_t j = 0, count = this->getHeight() - height; j < count; j++)
                    this->pixels[i].pop_back();

        this->height = height;
    }

    void ImageData::clear()
    {
        this->pixels.clear();
        this->width = ImageData::MIN_WIDTH;
        this->height = ImageData::MAX_HEIGHT;
    }

    void ImageData::reset()
    {
        for (size_t i = 0; i < this->getWidth(); i++)
            for (size_t j = 0; j < this->getHeight(); j++)
            {
                this->pixels[i][j].setRed(ImagePixel::MAX_CHANNEL_VALUE);
                this->pixels[i][j].setGreen(ImagePixel::MAX_CHANNEL_VALUE);
                this->pixels[i][j].setBlue(ImagePixel::MAX_CHANNEL_VALUE);

                if (this->pixels[i][j].getAlpha().has_value())
                    this->pixels[i][j].setAlpha(ImagePixel::MAX_CHANNEL_VALUE);
            }
    }

    void ImageData::throwIncorrectArgumentException(size_t width, size_t height) const
    {
        if ((width == 0 && height > 0) || (height == 0 && width > 0))
            throw std::invalid_argument(
                std::string("[Error] imaginator::ImageData: incorrect argument(s): ") +
                std::string("\"width\"") + std::to_string(width) +
                std::string("\"height\"") + std::to_string(height) +
                std::string("."));
    }

    void ImageData::throwOutOfBoundsException(size_t x, size_t y, size_t width, size_t height) const
    {
        if (x > width || y > height)
            throw std::invalid_argument(
                std::string("[Error] imaginator::ImageData: out of bounds: ") +
                std::string("width = ") + std::to_string(width) +
                std::string(", height = ") + std::to_string(height) +
                std::string(", x = ") + std::to_string(x) +
                std::string(", y = ") + std::to_string(y) +
                std::string("."));
    }
}