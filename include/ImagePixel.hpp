#ifndef IMAGINATOR_IMAGEPIXEL_HPP
#define IMAGINATOR_IMAGEPIXEL_HPP

#include <optional>
#include <limits>

namespace imaginator
{
    using byte = unsigned char;

    class ImagePixel
    {
    public:

        enum : byte
        {
            MIN_CHANNEL_VALUE = std::numeric_limits<byte>::min(),
            MAX_CHANNEL_VALUE = std::numeric_limits<byte>::max()
        };

        ImagePixel(
            byte red = MAX_CHANNEL_VALUE, 
            byte green = MAX_CHANNEL_VALUE, 
            byte blue = MAX_CHANNEL_VALUE, 
            std::optional<byte> alpha = std::nullopt);

        ImagePixel(const ImagePixel& imagePixel);

        virtual ~ImagePixel();

        inline void setRed(byte red);

        inline byte getRed() const;

        inline void setGreen(byte green);

        inline byte getGreen() const;

        inline void setBlue(byte blue);

        inline byte getBlue() const;

        inline void setAlpha(std::optional<byte> alpha);

        inline std::optional<byte> getAlpha() const;

    private:

        byte red;

        byte green;

        byte blue;

        std::optional<byte> alpha;
    };
}

#endif // IMAGINATOR_IMAGEPIXEL_HPP