#ifndef IMAGINATOR_BMPCONVERTER_HPP
#define IMAGINATOR_BMPCONVERTER_HPP

#include "ImageConverter.hpp"
#include "BmpData.hpp"

namespace imaginator
{
    class BmpConverter : public ImageConverter
    {
    public:

        BmpConverter();

        virtual ~BmpConverter();

        static const BmpData& convertData(const ImageData& imageData);

    protected:

        virtual const BmpData& inputData(const std::vector<byte>& sourceData) override;

        virtual const std::vector<byte>& outputData(const ImageData& editedData) override;

    };
}

#endif // IMAGINATOR_BMPCONVERTER_HPP