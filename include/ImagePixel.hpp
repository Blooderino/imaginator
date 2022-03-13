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

        ImagePixel(byte red = 0, byte green = 0, byte blue = 0, std::optional<byte> alpha = std::nullopt);

        ImagePixel(const ImagePixel& imagePixel);

        virtual ~ImagePixel();

        void setRed(byte red);

        byte getRed() const;

        void setGreen(byte green);

        byte getGreen() const;

        void setBlue(byte blue);

        byte getBlue() const;

        void setAlpha(std::optional<byte> alpha);

        std::optional<byte> getAlpha() const;

    private:

        byte m_red;

        byte m_green;

        byte m_blue;

        std::optional<byte> m_alpha;
    };
}

#endif // IMAGINATOR_IMAGEPIXEL_HPP