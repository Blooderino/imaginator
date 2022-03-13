#ifndef IMAGINATOR_IMAGECONVERTER_HPP
#define IMAGINATOR_IMAGECONVERTER_HPP

#include <string>
#include <vector>

#include "ImageData.hpp"

namespace imaginator
{
    class ImageConverter
    {
    public:

        ImageConverter();

        virtual ~ImageConverter();

        const ImageData& readData(const std::string& sourcePath);

        void writeData(const std::string& destinationPath, const ImageData& editedData);

        const std::string& getSourcePath() const;
    
    protected:

        virtual const ImageData& inputData(const std::vector<byte>& sourceData) = 0;

        virtual const std::vector<byte>& outputData(const ImageData& editedData) = 0;

    private:

        std::string m_sourcePath;
    };
}

#endif // IMAGINATOR_IMAGECONVERTER_HPP