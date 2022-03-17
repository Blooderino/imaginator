#include "BmpConverter.hpp"

namespace imaginator
{
    BmpConverter::BmpConverter() : 
        ImageConverter::ImageConverter()
    {}

    BmpConverter::~BmpConverter() {}

    const BmpData& BmpConverter::convertData(const ImageData& imageData)
    {
        BmpData bmpData = static_cast<const BmpData&>(imageData);
        return bmpData;
    }

    const BmpData& BmpConverter::inputData(const std::vector<byte>& sourceData)
    {
        BmpData convertedData;
        return convertedData;
    }

    const std::vector<byte>& BmpConverter::outputData(const ImageData& editedData)
    {
        const BmpData& bmpData = BmpConverter::convertData(editedData);
        std::vector<byte> destinationData;

        return destinationData;
    }
}