#ifndef IMAGINATOR_BMPCONVERTER_HPP
#define IMAGINATOR_BMPCONVERTER_HPP

#include "ImageConverter.hpp"

namespace imaginator
{
    class BmpConverter : public ImageConverter
    {
    public:

        BmpConverter();

        virtual ~BmpConverter();

    protected:

        virtual const ImageData& inputData(const std::vector<byte>& sourceData) override;

        virtual const std::vector<byte>& outputData(const ImageData& editedData) override;

    };
}

#endif // IMAGINATOR_BMPCONVERTER_HPP