#ifndef IMAGINATOR_JPEGCONVERTER_HPP
#define IMAGINATOR_JPEGCONVERTER_HPP

#include "ImageConverter.hpp"

namespace imaginator
{
    class JpegConverter : public ImageConverter
    {
    public:

        JpegConverter();

        virtual ~JpegConverter();

    protected:

        virtual const ImageData& inputData(const std::vector<byte>& sourceData) override;

        virtual const std::vector<byte>& outputData(const ImageData& editedData) override;
    };
}

#endif // IMAGINATOR_JPEGCONVERTER_HPP