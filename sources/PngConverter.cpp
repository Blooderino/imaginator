#include "PngConverter.hpp"

namespace imaginator
{
    PngConverter::PngConverter() :
        ImageConverter::ImageConverter()
    {}

    PngConverter::~PngConverter() {}

    const ImageData& PngConverter::inputData(const std::vector<byte> &sourceData)
    {
        ImageData convertedData;

        return convertedData;
    }

    const std::vector<byte>& PngConverter::outputData(const ImageData &editedData)
    {
        std::vector<byte> destinationData;

        return destinationData;
    }
}