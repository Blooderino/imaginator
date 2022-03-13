#include "BmpConverter.hpp"

namespace imaginator
{
    BmpConverter::BmpConverter() : 
        ImageConverter::ImageConverter()
    {}

    BmpConverter::~BmpConverter() {}

    const ImageData& BmpConverter::inputData(const std::vector<byte> &sourceData)
    {
        ImageData convertedData;

        return convertedData;
    }

    const std::vector<byte>& BmpConverter::outputData(const ImageData &editedData)
    {
        std::vector<byte> destinationData;

        return destinationData;
    }
}