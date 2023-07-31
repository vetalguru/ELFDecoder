#include "elfdecoder.h"

int main ()
{
    std::vector<unsigned char> data;
    if (ReadData(std::string{"samples/simple.bin"}, data))
    {
        PrintHEX(data);
        PrintElfHeader(data);
    }

    return 0;
}
