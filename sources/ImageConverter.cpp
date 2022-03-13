#include <fstream>

#include "ImageConverter.hpp"

namespace imaginator
{
    ImageConverter::ImageConverter() :
        m_sourcePath("")
    {}

    ImageConverter::~ImageConverter() {}

    const ImageData& ImageConverter::readData(const std::string& sourcePath)
    {
        m_sourcePath = sourcePath;

        std::ifstream file;
        file.open(sourcePath, std::ios::binary);
        file.seekg(0, std::ios::end);
        std::vector<byte> sourceData(file.tellg());
        file.seekg(0, file.beg);
        file.read(reinterpret_cast<char*>(sourceData.data()), sourceData.size());
        file.close();

        return inputData(sourceData);
    }

    void ImageConverter::writeData(const std::string& destinationPath, const ImageData& editedData)
    {
        std::vector<byte> destinationData = outputData(editedData);
        std::ofstream file;
        file.open(destinationPath, std::ios::binary);
        file.write(reinterpret_cast<char*>(destinationData.data()), destinationData.size());
        file.close();
    }

    const std::string& ImageConverter::getSourcePath() const
    {
        return m_sourcePath;
    }
}