#ifndef IMAGINATOR_PNGCONVERTER_HPP
#define IMAGINATOR_PNGCONVERTER_HPP

#include "ImageConverter.hpp"

namespace imaginator
{
    class PngConverter : public ImageConverter
    {
    public:

        PngConverter();

        virtual ~PngConverter();

    protected:

        virtual const ImageData& inputData(const std::vector<byte>& sourceData) override;

        virtual const std::vector<byte>& outputData(const ImageData& editedData) override;

    };
}

#endif // IMAGINATOR_PNGCONVERTER_HPP