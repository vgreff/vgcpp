#ifndef HEXDUMP_HPP
#define HEXDUMP_HPP

#include <cctype>
#include <iomanip>
#include <ostream>

namespace vbg
{

namespace hft
{

template <unsigned RowSize, bool ShowAscii>
struct CustomHexdump
{
    CustomHexdump(const void* data, unsigned length) :
        mData(static_cast<const unsigned char*>(data)), mLength(length) { }
    const unsigned char* mData;
    const unsigned mLength;
};

template <unsigned RowSize, bool ShowAscii>
std::ostream& operator<<(std::ostream& out, const CustomHexdump<RowSize, ShowAscii>& dump)
{
    std::ios oldState(nullptr);
    oldState.copyfmt(out);

    out.fill('0');
    for (int i = 0; i < dump.mLength; i += RowSize)
    {
        out << "0x" << std::setw(6) << std::hex << i << ": ";
        for (int j = 0; j < RowSize; ++j)
        {
            if (i + j < dump.mLength)
            {
                out << std::hex << std::setw(2) << static_cast<int>(dump.mData[i + j]) << " ";
            }
            else
            {
                out << "   ";
            }
        }

        out << " ";
        if (ShowAscii)
        {
            for (int j = 0; j < RowSize; ++j)
            {
                if (i + j < dump.mLength)
                {
                    if (std::isprint(dump.mData[i + j]))
                    {
                        out << static_cast<char>(dump.mData[i + j]);
                    }
                    else
                    {
                        out << ".";
                    }
                }
            }
        }
        out << std::endl;
    }

    out.copyfmt(oldState);
    return out;
}

using Hexdump = CustomHexdump<16, true> ;

    // Usage examples
    // std::cout << vbg::hft::Hexdump(data, sizeof(data)) << std::endl;
    // std::cout << vbg::hft::CustomHexdump<8, true>(data, sizeof(data)) << std::endl;
    // std::cout << vbg::hft::CustomHexdump<32, false>(data, sizeof(data)) << std::endl;

} // namespace hft
    
} // namespace vbg


#endif // HEXDUMP_HPP
