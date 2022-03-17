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
        this->setWidth(width);
        this->setHeight(height);

        throwIncorrectArgumentException();

        this->pixels.resize(this->getWidth());
        this->pixels.shrink_to_fit();

        if (this->getWidth() > 0)
        {
            for (size_t i = 0; i < this->getWidth(); i++)
            {
                this->pixels[i] = std::vector<ImagePixel>(this->getHeight());
                this->pixels[i].shrink_to_fit();
            }
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
        this->throwOutOfBoundsException(x, y);
        this->pixels[x][y] = imagePixel;
    }

    ImagePixel& ImageData::getPixel(size_t x, size_t y)
    {
        this->throwOutOfBoundsException(x, y);

        return this->pixels[x][y];
    }

    const ImagePixel& ImageData::getPixel(size_t x, size_t y) const
    {
        this->throwOutOfBoundsException(x, y);

        return this->pixels[x][y];
    }

    void ImageData::setWidth(size_t width)
    {
        if (width > this->getWidth())
        {
            for (size_t row = 0, count = width - this->getWidth(); row < count; row++)
                this->pixels.push_back(std::vector<ImagePixel>(this->getWidth()));
        }
        else if (width < this->getWidth())
        {
            for (size_t row = 0, count = this->getWidth() - width; row < count; row++)
                this->pixels.pop_back();
        }

        this->pixels.shrink_to_fit();
        this->setWidth(width);
    }

    size_t ImageData::getWidth() const
    {
        return this->width;
    }

    void ImageData::setHeight(size_t height)
    {
        if (height > this->getHeight())
        {
            for (size_t row = 0; row < this->getWidth(); row++)
            {
                for (size_t column = 0, count = height - this->getHeight(); column < count; column++)
                    this->pixels[row].push_back(ImagePixel());

                this->pixels[row].shrink_to_fit();
            }
        }
        else if (height < this->getHeight())
        {
            for (size_t row = 0; row < this->getWidth(); row++)
            {
                for (size_t column = 0, count = this->getHeight() - height; column < count; column++)
                    this->pixels[row].pop_back();

                this->pixels[row].shrink_to_fit();
            }
        }

        this->setHeight(height);
    }

    void ImageData::clear()
    {
        this->pixels.clear();
        this->width = ImageData::MIN_WIDTH;
        this->height = ImageData::MIN_HEIGHT;
    }

    void ImageData::reset()
    {
        for (size_t x = 0; x < this->getWidth(); x++)
        {
            for (size_t y = 0; y < this->getHeight(); y++)
            {
                this->pixels[x][y].setRed(ImagePixel::MAX_CHANNEL_VALUE);
                this->pixels[x][y].setGreen(ImagePixel::MAX_CHANNEL_VALUE);
                this->pixels[x][y].setBlue(ImagePixel::MAX_CHANNEL_VALUE);

                if (this->pixels[x][y].getAlpha().has_value())
                    this->pixels[x][y].setAlpha(ImagePixel::MAX_CHANNEL_VALUE);
            }
        }
    }

    void ImageData::throwIncorrectArgumentException() const
    {
        if ((this->getWidth() == 0 && this->getHeight() > 0) || 
            (this->getHeight() == 0 && this->getWidth() > 0))
        {
            throw std::invalid_argument(
                std::string("[Error] imaginator::ImageData: incorrect argument(s): ") +
                std::string("\"width\"") + std::to_string(width) +
                std::string("\"height\"") + std::to_string(height) +
                std::string("."));
        }
    }

    void ImageData::throwOutOfBoundsException(size_t x, size_t y) const
    {
        if (x > this->getWidth() || 
            y > this->getHeight())
        {
            throw std::invalid_argument(
                std::string("[Error] imaginator::ImageData: out of bounds: ") +
                std::string("width = ") + std::to_string(width) +
                std::string(", height = ") + std::to_string(height) +
                std::string(", x = ") + std::to_string(x) +
                std::string(", y = ") + std::to_string(y) +
                std::string("."));
        }
    }
}