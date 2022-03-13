#include "JpegConverter.hpp"

namespace imaginator
{
    JpegConverter::JpegConverter() :
        ImageConverter::ImageConverter()
    {}

    JpegConverter::~JpegConverter() {}

    const ImageData& JpegConverter::inputData(const std::vector<byte>& sourceData)
    {
        ImageData convertedData;

        return convertedData;
    }

    const std::vector<byte>& JpegConverter::outputData(const ImageData& editedData)
    {
        std::vector<byte> destinationData;

        return destinationData;
    }
}